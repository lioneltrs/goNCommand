#!/bin/bash
#
# Refactored by Tomasz Bednarz, 2023.
# Based on
# Lionel Cordesses, 2023.
# Set of functions to help build a MAME or FBAlpha romset (extension: .zip_original), and also FBNeo romset (extension: .zip)
# For games from the Amazon Prime Gaming game.

IFLAG=skip_bytes,count_bytes

# Test if zip is installed.
function checkForZip() {
    if ! command -v zip &> /dev/null
    then
        echo "zip could not be found. Maybe "sudo apt-get install zip"?"
        exit
    fi
}

# Test is ss_unswizzle.c has been compiled.
function checkForCompiledSwizzle() {
    if ! command -v ./ss_unswizzle &> /dev/null
    then
        echo "ss_unswizzle could not be found. You may try: gcc -o ss_unswizzle ss_unswizzle.c"
        exit
    fi
}

# Delete files and directories froms previous runs.
function cleanFilesForReRun() {
    rm -r "$1"
    rm "$2".zip
    rm "$2".zip_original
    mkdir -p "$1"
}
