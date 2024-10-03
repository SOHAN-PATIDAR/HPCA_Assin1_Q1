#include <iostream>
#include <fstream>

using namespace std;

int SIZE = 8192;
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

   
// Allocate memory for matrix A of size 8192x8192 
    int** A = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; ++i) {
        A[i] = (int*)malloc(SIZE * sizeof(int));
    }

    // Taking input for matrix A from the file
    ifstream inFile("D:\\HPCA_assign_Q1\\output\\matrix_8192_inp1.txt");
    if (!inFile) {
        cerr << "Unable to open file matrix_8192_inp1.txt";
        return 1; // Exit with error
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            inFile >> A[i][j];
        }
    }

    inFile.close();


// Allocate memory for matrix B of size 8192x8192
    int** B = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; ++i) {
        B[i] = (int*)malloc(SIZE * sizeof(int));
    }


    // Taking input for matrix B from the file
    ifstream in2File("D:\\HPCA_assign_Q1\\output\\matrix_8192_inp2.txt");
    if (!in2File) {
        cerr << "Unable to open file matrix_8192_inp2.txt";
        return 1; // Exit with error
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in2File >> B[i][j];
        }
    }

    in2File.close();

// Allocate memory for matrix C of size 8192x8192

    int** C = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; ++i) {
        C[i] = (int*)malloc(SIZE * sizeof(int));
    }
    
	
	mul_jik(A,B,C);
 	
 	return 0;
}