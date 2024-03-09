#!/bin/bash

OUT_DIR="./build"
STRACE_DIR="${OUT_DIR}/strace_outputs"

# Create a directory for strace outputs if it doesn't exist
mkdir -p "$STRACE_DIR"

# Function to perform strace and save output
perform_strace() {
    local binary_file=$1
    local output_file="${STRACE_DIR}/strace_$(basename "${binary_file}").txt"
    strace -o "${output_file}" -f -e trace=all "./${binary_file}"
    echo "Strace output for ${binary_file} saved to ${output_file}"
}

# Loop through each file in the output directory
for file in "${OUT_DIR}"/*; do
    if [[ -f "$file" ]] && file "$file" | grep -qE 'executable|shared object'; then
      echo "This is a binary file."
      perform_strace "$file"
    else
        echo "This is a text file."
    fi
done

echo "Strace completed for all executables in ${OUT_DIR}."