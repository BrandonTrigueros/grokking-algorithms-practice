#!/bin/bash

# Script to delete all programming language implementations except C and C++ variants
# from the grokking_algorithms-master repository

# Base directory
BASE_DIR="/home/brandontrigueros/Downloads/grokking_algorithms-master/reference_code"

# Languages to keep (C and C++ variants)
KEEP_LANGS=("c" "c++" "c++11")

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}Starting cleanup of non-C/C++ language implementations...${NC}"
echo -e "${YELLOW}Keeping only: ${KEEP_LANGS[@]}${NC}"
echo

# Function to check if a directory should be kept
should_keep() {
    local dir_name="$1"
    for keep_lang in "${KEEP_LANGS[@]}"; do
        if [[ "$dir_name" == "$keep_lang" ]]; then
            return 0
        fi
    done
    return 1
}

# Counter for deleted directories
deleted_count=0

# Process each algorithm directory
for algo_dir in "$BASE_DIR"/*/; do
    # Skip if not a directory or if it's a special directory
    if [[ ! -d "$algo_dir" ]]; then
        continue
    fi
    
    dir_name=$(basename "$algo_dir")
    
    # Skip special directories (not algorithm chapters)
    if [[ "$dir_name" == "images" ]] || [[ ! "$dir_name" =~ ^[0-9] ]]; then
        echo -e "${YELLOW}Skipping special directory: $dir_name${NC}"
        continue
    fi
    
    echo -e "${GREEN}Processing: $dir_name${NC}"
    
    # Process each language subdirectory
    for lang_dir in "$algo_dir"*/; do
        if [[ ! -d "$lang_dir" ]]; then
            continue
        fi
        
        lang_name=$(basename "$lang_dir")
        
        if should_keep "$lang_name"; then
            echo -e "  ${GREEN}✓ Keeping: $lang_name${NC}"
        else
            echo -e "  ${RED}✗ Deleting: $lang_name${NC}"
            rm -rf "$lang_dir"
            ((deleted_count++))
        fi
    done
    echo
done

echo -e "${GREEN}Cleanup completed!${NC}"
echo -e "${YELLOW}Total directories deleted: $deleted_count${NC}"
echo -e "${GREEN}Remaining languages: ${KEEP_LANGS[@]}${NC}"
