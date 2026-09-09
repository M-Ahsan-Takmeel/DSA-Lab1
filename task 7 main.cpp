#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task_7_function.h"
using namespace std;
// Check if two matrices are equal
bool isEqual(int** A, int** B, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}
// Print matrix content
void printMatrix(int** M, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}
void runTestCase(int size, bool isRandom) {
    int** A = createMatrix(size);
    int** B = createMatrix(size);
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            A[i][j] = isRandom ? (rand() % 10) : (i + j + 1);
            B[i][j] = isRandom ? (rand() % 10) : (i * j + 2);
        }
    }
    int** standardRes = multiplyStandard(A, B, size);
    int** strassenRes = multiplyStrassen(A, B, size);
    if (isEqual(standardRes, strassenRes, size)) 
    {
        cout << "Result: [MATCH]\n";
    } 
    else
        cout << "Result: [MISMATCH]\n";
    if (size <= 4) 
    {
        cout << "Strassen Result Matrix:\n";
        printMatrix(strassenRes, size);
    }
    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(standardRes, size);
    freeMatrix(strassenRes, size);
}
int main() {
    srand(time(0));
    cout << "=== 1. 2x2 Matrix Multiplication ===\n";
    runTestCase(2, false);
    cout << "\n=== 2. 4x4 Matrix Multiplication ===\n";
    runTestCase(4, false);
    cout << "\n=== 3. Random Values (4x4 Matrix) Compared with Naive ===\n";
    runTestCase(4, true);
    return 0;
}
