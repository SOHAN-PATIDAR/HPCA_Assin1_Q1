#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



// void print_C(int **C,int n){
//     // Output the result matrix C
//     cout << "Result matrix C (" << n << "x" << n << "):" << endl;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cout << C[i][j] << " ";
//         }
//         cout << endl;
//     }perf
// }

void mul_ijk(int **A,  int **B,  int **C, int n) {
    // Matrix multiplication (C = A * B)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;  // Initialize result matrix element to 0
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // print_C(C,n);
}





int main() {

    int SIZE = 2048;

    
    // Creating Matrices A,B and C and we will be doing multiplication in the way C = AB

    
// Allocate memory for matrix A of size 2048x2048
    
    int** A = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; ++i) {
        A[i] = (int*)malloc(SIZE * sizeof(int));
    }
    // Taking input for matrix A from the file

    ifstream inFile("D:\\HPCA_assign_Q1\\output\\matrix_2048_inp1.txt");
    if (!inFile) {
        cerr << "Unable to open file matrix_2048_inp1.txt";
        return 1; // Exit with error
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            inFile >> A[i][j];
        }
    }

    inFile.close();


// Allocate memory for matrix B of size 2048x2048
    int** B = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; ++i) {
        B[i] = (int*)malloc(SIZE * sizeof(int));
    }


    // Taking input for matrix B from the file

    ifstream in2File("D:\\HPCA_assign_Q1\\output\\matrix_2048_inp2.txt");
    if (!in2File) {
        cerr << "Unable to open file matrix_2048_inp2.txt";
        return 1; // Exit with error
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in2File >> B[i][j];
        }
    }

    in2File.close();

// Allocate memory for matrix C of size 2048x2048

    int** C = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; ++i) {
        C[i] = (int*)malloc(SIZE * sizeof(int));
    }
    
    

    mul_ijk(A,B,C,SIZE);


    for (int i = 0; i < SIZE; ++i) free(A[i]); free(A);
    for (int i = 0; i < SIZE; ++i) free(B[i]); free(B);
    for (int i = 0; i < SIZE; ++i) free(C[i]); free(C);

    return 0;
}
