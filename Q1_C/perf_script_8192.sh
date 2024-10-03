#!/bin/bash
 
# Define your C source files (replace these with actual file names)
source_files=(
    "matBlock_8192_ijk.cpp"
    "matBlock_8192_jik.cpp"
    "matBlock_8192_kij.cpp"
)
 
# Define an array of output executable names matching the C files
program_names=(
    "matBlock_8192_ijk"
    "matBlock_8192_jik"
    "matBlock_8192_kij"
)
 
# Directory to store the output file
output_dir="D:\\HPCA_assign_Q1\\Q1_C_output"
mkdir -p $output_dir  # Create the directory if it doesn't exist
 
# Output file for all results
output_file="${output_dir}/all_8192_tiling_programs_output.txt"
> "$output_file"  # Clear the file before writing
 
# Loop through each source file, compile it, and run perf stat
for i in "${!source_files[@]}"; do
    # Get the source file and corresponding program name for the executable
    source_file="${source_files[$i]}"
    program_name="${program_names[$i]}"
    # Compile the C file into an executable
    echo "Compiling: $source_file"
    g++ -o "$program_name" "$source_file"
    # Check if compilation was successful
    if [ $? -ne 0 ]; then
        echo "Compilation failed for $source_file" | tee -a "$output_file"
        continue
    fi
    # Add a header to the output file indicating which program the output is for
    echo -e "\n=========================" >> "$output_file"
    echo "Performance stats for $program_name" >> "$output_file"
    echo "=========================" >> "$output_file"
    # Execute the program with perf stat and append the output to the single file
    echo "Running: perf stat on $program_name"
    perf stat -e task-clock,context-switches,cpu-migrations,page-faults,cycles,instructions,branches,branch-misses,cache-misses,cache-references,dTLB-loads,dTLB-load-misses,dTLB-stores,dTLB-store-misses,iTLB-loads,iTLB-load-misses,L1-dcache-loads,L1-dcache-load-misses,L1-icache-loads,L1-icache-load-misses,L2_rqsts.miss,L2-loads,L2-load-misses,L2-stores,L2-store-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses ./$program_name >> "$output_file" 2>&1
    # Print a confirmation message
    echo "Output stored for: $program_name"
done
 
echo "All programs compiled and executed. Combined output stored in: $output_file"
has context menu