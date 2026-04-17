# Author: Jose Francisco Marti Martin
# post_build.py Post build proccessing script.

import os
import struct
import argparse
import sys
import subprocess
import random 
import logging

# Header section size
FLASH_HEADER_SIZE = 1024

# Header section offsets
FLASH_HEADER_OTA_FLAG_OFFSET   = 0
FLASH_HEADER_MAGIC_OFFSET      = 4
FLASH_SIZE_OFFSET              = 8
FLASH_CRC_OFFSET               = 12
FLASH_HEADER_VERSION_OFFSET    = 16

# CRC Seed
CRC_SEED = 0xFFFFFFFF

# Global logger
LOGGER = ""

def CreateLogger():
    """
    Create logger with console and file handler
    """
    global LOGGER

    # Create main logger
    LOGGER = logging.getLogger("bootloader") 
    LOGGER.setLevel(logging.DEBUG)

    # --- Console handler --- 
    console_handler = logging.StreamHandler() 
    console_handler.setLevel(logging.DEBUG)
    console_format = logging.Formatter("[%(levelname)s] %(message)s") 
    console_handler.setFormatter(console_format)

    LOGGER.addHandler(console_handler)

def cli():
    """
    Command line interface using argaparse module
    """
    cli = argparse.ArgumentParser(description='Bootloader host manager')
    cli.add_argument('-rv', 
                     '--random_version_flag',
                     required=False,
                     default=False,
                     action='store_true',
                     help='Random version generator')
    cli.add_argument('-an',
                     '--artifact_name',
                     type=str,
                     required=True,
                     help='Binary name')
    cli.add_argument('-ap',
                     '--artifact_path',
                     type=str,
                     required=True,
                     help='Binary path')

    return cli.parse_args()

def check_arguments(args):
    """
    Command line interface check  
        - Binary and executable file exist check
    Args:
        args: Arguments passed by command line interface
    Returns:
        complete_binary_path: Complete binary path (file path + file name)
        complete_executable_path: Complete executable path (file path + file name)
    """
    complete_binary_path = os.path.join(args.artifact_path, f"{args.artifact_name}.bin")

    if not os.path.isfile(complete_binary_path):

        LOGGER.error(f"File not found: {complete_binary_path}")
        sys.exit(1)

    complete_executable_path = os.path.join(args.artifact_path, f"{args.artifact_name}.elf")

    if not os.path.isfile(complete_executable_path):

        LOGGER.error(f"File not found: {complete_executable_path}")
        sys.exit(1)

    return complete_binary_path, complete_executable_path

def read_binary_file(bin_file):
    """
    Read binary file to process
    Args:
        bin_file: Binary file path
    Returns:
        bin_data: Binary file data read
    """
    with open(bin_file, "rb") as f:

        bin_data = bytearray(f.read())

    return bin_data

def calculate_app_size(bin_data):
    """
    Caculate application size 
    Args:
        bin_data: Binary file data read
    Returns:
        app_size: Application size
    """
    total_size = len(bin_data)

    if total_size < FLASH_HEADER_SIZE:

        LOGGER.error("Error: binary smaller than header")
        sys.exit(1)

    app_size = total_size - FLASH_HEADER_SIZE

    return app_size

def calculate_app_crc(bin_data):
    """
    Calculate application crc
    Args:
        bin_data: Binary file data read
    Returns:
        app_crc: Application crc
    """
    app_crc = sum(bin_data[FLASH_HEADER_SIZE:]) & CRC_SEED

    return app_crc

def update_binary_file(complete_binary_path, bin_data, app_size, app_crc, random_version_flag):
    """
    Update binary file with the current size and crc
    Little-Endian (<) and 32 bits size (I) for every data written
    Args:
        complete_binary_path: Complete binary path 
        bin_data: Binary file data read
        app_size: Application size
        app_crc: Application crc
        random_version_flag: Random version generator flag
    Returns:
        bin_data: Binary file data updated
    """
    struct.pack_into("<I", bin_data, FLASH_SIZE_OFFSET, app_size)
    struct.pack_into("<I", bin_data, FLASH_CRC_OFFSET, app_crc)

    if random_version_flag is True:

        struct.pack_into("<I", bin_data, FLASH_HEADER_VERSION_OFFSET, generate_random_version())

    with open(complete_binary_path, "wb") as f:

        f.write(bin_data)

    return bin_data

def generate_random_version():
    """
    Generate random fw version
    Returns:
        random_fw_version: Random fw version generated
    """
    major = random.randint(0, 255)
    minor = random.randint(0, 255)
    patch = random.randint(0, 255)

    random_fw_version = (major << 16) | (minor << 8) | patch

    return random_fw_version

def generate_header_binary_file(artifact_name, bin_data):
    """
    Generate header binary file based on the app binary file modifcations
    Args:
        artifact_name: Artifact name
        bin_data_updated: Binary file data updated
    Returns:
        complete_header_binary_path: Complete header binary path (file path + file name)
    """
    header_binary_name = f"{artifact_name}_Header.bin"
    cwd = os.getcwd()

    with open(header_binary_name, "wb") as app_header:

        app_header.write(bin_data[:FLASH_HEADER_SIZE])

    return os.path.join(cwd, header_binary_name)

def update_executable_file(complete_header_binary_path, complete_executable_path):
    """
    Update executable file based on header binary modifcation
    Args:
        complete_header_binary_path: Complete header binary path (file path + file name)
        complete_executable_path: Complete executable path (file path + file name)
    """
    cmd = ["arm-none-eabi-objcopy",
           "--update-section",
           f".header={complete_header_binary_path}",
           f"{complete_executable_path}"]
    
    output = subprocess.run(cmd, capture_output=True, text=True)

    LOGGER.info(output)

def print_post_build_data(app_size, app_crc):
    """
    Print relevant post build data
    Args:
        app_size: Application size
        app_crc: Application crc
    """
    LOGGER.info(f"App size: {app_size} bytes")
    LOGGER.info(f"App crc: 0x{app_crc:08X}")

def main():
    """
    Post build binary update main function
    """
    CreateLogger()
    LOGGER.info("Starting post build processing...")
    args = cli()
    complete_binary_path, complete_executable_path = check_arguments(args)
    bin_data = read_binary_file(complete_binary_path)
    app_size = calculate_app_size(bin_data)
    app_crc = calculate_app_crc(bin_data)
    bin_data_updated = update_binary_file(complete_binary_path, bin_data, app_size, app_crc, args.random_version_flag)
    complete_header_binary_path = generate_header_binary_file(args.artifact_name, bin_data_updated)
    update_executable_file(complete_header_binary_path, complete_executable_path)

    print_post_build_data(app_size, app_crc)
    LOGGER.info("Post build processing end")

if __name__ == "__main__":

    main()