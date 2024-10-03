#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <filesystem>
#include <string>

const int SIZE = 2048;

using namespace std;

void generateRandomMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = rand() % 5;
        }
    }
}

int main() {
    int n = 2;

    // Seed the random number generator once at the start
    srand(static_cast<unsigned>(time(0)));

    // Create output directory
    string outputDir = "output";
    filesystem::create_directory(outputDir);

    for (int i = 1; i <= n; i++) {
        vector<vector<int>> matrix(SIZE, vector<int>(SIZE));
        generateRandomMatrix(matrix);

        // Store output in a file with the new naming convention
        string filename = outputDir + "/matrix_" + to_string(SIZE) + "_inp" + to_string(i) + ".txt";
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    outFile << matrix[i][j] << " ";
                }
                outFile << endl;
            }
            outFile.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
        cout << "File created: " << filename << endl; // Output filename for confirmation
    }

    return 0;
}
