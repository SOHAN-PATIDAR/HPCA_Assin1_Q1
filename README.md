This readme file for Q1 of Assignment_1 that explains about the wroking of code, how it is executed and how the required results are generated.

**Q1** consist of 3 subparts which are implemented separately here in different folder namely **Q1_A, Q1_B** and **Q1_c** and the expected results are stored in three folders namely **Q1_A_output,Q1_B_output** and **Q1_C_output**

**output** folder contains 4 files, 2 for 2048 x 2048 and 2 for 8192 x 8192 matrices input. For Q1_A and Q1_C the input is read from this output folder

## Q1_A Working

This question ask us to perform matrix multiplication for 2048 x 2048 and 8192 x 8192 matrix in three different variants of loop order **ijk jik kij**

### Steps follow for matrix multiplication code
1. Allocate memory of size n*n for matrices A B and C using malloc. (n will be 2048 & 8192).
2. Used **Random.cpp** to generate input for matrices that are to be multiplied by setting required SIZE. Run the following commands in terminal to generate files.
```bash
# To generate the executable file
g++ -o random randomInp.cpp

# To run executable file
./random
```
**NOTE:-** The matrix input file for 8192 x 8192 is too big so uploading zip file (for GitHub)
3. Read the values for matrix A and B from the files generated in step 2.
4. Multiply matrix by using standard matrix multiplication algorithm.
5. Deallocate the memory used.

These steps are used to generate 6 code files: 3 files (ijk, jik, kij) for the 2048 x 2048 matrix size and 3 files (ijk, jik, kij) for the 8192 x 8192 matrix size.

### How script file is used to execute the code files and generate output
1. source_files :- an array of program files.
2. program_names :- an array of string values which we want to assign to our exe files.
3. Will create a folder named as Q1_A_output, if it doesn't exist   that will contain our result.
4. Create a single .txt file that will store result of all three variants(ijk, jik, kij).
5. Compile the code file using the command mentioned above.
6. Use **perf** to measure the performance and store the generated result into the .txt created earlier using below command.
```bash
# Execute the program with perf stat and append the output to the single file

    perf stat -e task-clock,context-switches,cpu-migrations,page-faults,cycles,instructions,branches,branch-misses,cache-misses,cache-references,dTLB-loads,dTLB-load-misses,dTLB-stores,dTLB-store-misses,iTLB-loads,iTLB-load-misses,L1-dcache-loads,L1-dcache-load-misses,L1-icache-loads,L1-icache-load-misses,L2_rqsts.miss,L2-loads,L2-load-misses,L2-stores,L2-store-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses ./$program_name >> "$output_file" 2>&1
    
```
### Execution of script file
Open terminal in the folder where script file is present and run the following commands.
```bash
chmod +x script_file_name.sh
./script_file_name.sh
```
I've used two script files, one for 2048 x 2048 matrix and another for 8192 x 8192 matrix.

## Q1_B Working

This question ask us to perform matrix multiplication using huge pages for 2048 x 2048 and 8192 x 8192 matrix in three different variants of loop order **ijk jik kij**

### allocating huge pages
1. Execute the following command for huge page allocation
```bash
# to allocate 100 huge pages
sudo sysctl -w vm.nr_hugepages=100

# check if allocation is successful or not
cat /proc/meminfo | grep Huge

# to deallocate huge pages
sudo sysctl -w vm.nr_hugepages=0
```

### Steps follow for matrix multiplication code
1. Allocate memory of size n*n for matrices A B and C using mmap. (n will be 2048 & 8192).
2. Filling matrices A and B by generating some random number.
3. Multiply matrix by using standard matrix multiplication algorithm.
4. Deallocate the memory used.

These steps are used to generate 6 code files: 3 files (ijk, jik, kij) for the 2048 x 2048 matrix size and 3 files (ijk, jik, kij) for the 8192 x 8192 matrix size.

### Output generation
Script files are used in the same way as they were used in Q1_A to generate output, the only difference is that some parameters will be modified.


## Q1_C Working

This question ask us to perform matrix multiplication using concept of tiling\blocking for 2048 x 2048 and 8192 x 8192 matrix in three different variants of loop order **ijk jik kij**

### Steps follow for matrix multiplication code
1. Follow same step 1,2 and 3 as they were used in this same part of Q1_A
2. Multiply matrix by using concept of tiling.For this question tile size used is 64.
5. Deallocate the memory used.

These steps are used to generate 6 code files: 3 files (ijk, jik, kij) for the 2048 x 2048 matrix size and 3 files (ijk, jik, kij) for the 8192 x 8192 matrix size.

### Output generation
Script files are used in the same way as they were used in Q1_A to generate output, the only difference is that some parameters will be modified.