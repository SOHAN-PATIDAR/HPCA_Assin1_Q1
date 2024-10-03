#include <iostream>
#include <fstream>

using namespace std;

int SIZE = 2048;
int tile_size = 64;



void mul_jik(int **A,  int **B,  int **C){
for(int j=0; j<SIZE; j=j+tile_size)
	{	
		for(int i=0; i<SIZE ;i=i+tile_size){
 			
 			for (int k=0; k < SIZE; k=k+tile_size){
 				for(int ii=i; ii<i+tile_size; ii++){
 					for(int jj=j; jj < j+tile_size; jj++){
 						for(int kk=k; kk < k+tile_size; kk++){
 							C[ii][jj] += A[ii][kk] * B[kk][jj];
 							}
 						}
 					}
 				}
 			}
 							
 	} 
}

int main(){
    
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
    
	
	mul_jik(A,B,C);

    // Decllocate memory of matrix A B and C of size 2048x2048
    for (int i = 0; i < SIZE; ++i) free(A[i]); free(A);
    for (int i = 0; i < SIZE; ++i) free(B[i]); free(B);
    for (int i = 0; i < SIZE; ++i) free(C[i]); free(C);

 	
 	return 0;
}