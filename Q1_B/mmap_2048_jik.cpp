#include <iostream>
#include <vector>
#include <random>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

// void print_C(int **C, int n) {
//     // Output the result matrix C
//     cout << "Result matrix C (" << n << "x" << n << "):" << endl;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cout << C[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void mul_jik(int **A,  int **B,  int **C, int n) {
    // Matrix multiplication (C = A * B)
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = 0;  // Initialize result matrix element to 0
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // print_C(C,n);
}


int** allocate_matrix(int size) {
    // Allocate memory for a matrix using mmap
    int** matrix = (int**)mmap(NULL, size * sizeof(int*) + size * size * sizeof(int),
                                PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB,
                                -1, 0);
    if (matrix == MAP_FAILED) {
        cerr << "Memory allocation failed using mmap" << endl;
        exit(1);
    }

    // Allocate each row of the matrix
    int* data = (int*)(matrix + size);
    for (int i = 0; i < size; ++i) {
        matrix[i] = data + (i * size);
    }
    
    return matrix;
}

void fill_matrix_with_random_values(int** matrix, int size) {
    // Random number generator for values between 0 and 9
    random_device rd;  // Obtain a random number from hardware
    mt19937 eng(rd()); // Seed the generator
    uniform_int_distribution<> distr(0, 9); // Define the range

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = distr(eng); // Generate random number and assign to matrix
        }
    }
}

int main() {
    int SIZE = 2048;

    // Allocate matrices A, B, and C using mmap
    int** A = allocate_matrix(SIZE);
    int** B = allocate_matrix(SIZE);
    int** C = allocate_matrix(SIZE);

    // Fill matrices A and B with random values between 0 and 9
    fill_matrix_with_random_values(A, SIZE);
    fill_matrix_with_random_values(B, SIZE);

    // Perform matrix multiplication
    mul_jik(A, B, C, SIZE);

    // Clean up (unmap the allocated memory)
    munmap(A, SIZE * sizeof(int*) + SIZE * SIZE * sizeof(int));
    munmap(B, SIZE * sizeof(int*) + SIZE * SIZE * sizeof(int));
    munmap(C, SIZE * sizeof(int*) + SIZE * SIZE * sizeof(int));

    return 0;
}
