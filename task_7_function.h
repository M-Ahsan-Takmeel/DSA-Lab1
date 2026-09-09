#ifndef TASK_7_FUNCTION_H
#define TASK_7_FUNCTION_H
#include <iostream>
using namespace std;
inline int** createMatrix(int size) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size]();
    }
    return matrix;
}
// Free dynamic 2D array
inline void freeMatrix(int** matrix, int size) {
    if (!matrix) return;
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
// Standard O(n^3) Matrix Multiplication
inline int** multiplyStandard(int** A, int** B, int size) {
    int** C = createMatrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
// Matrix Addition
inline void addMatrix(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
// Matrix Subtraction
inline void subtractMatrix(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
// Strassen's Matrix Multiplication
inline int** multiplyStrassen(int** A, int** B, int size) {
    int** C = createMatrix(size);
    // Base Case: 1x1 matrix
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int k = size / 2;
    // Allocate sub-matrices
    int** A11 = createMatrix(k);
    int** A12 = createMatrix(k);
    int** A21 = createMatrix(k);
    int** A22 = createMatrix(k);
    int** B11 = createMatrix(k);
    int** B12 = createMatrix(k);
    int** B21 = createMatrix(k);
    int** B22 = createMatrix(k);
    // Split matrices into 4 sub-matrices
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }
    // Temporary matrices for calculation
    int** tempA = createMatrix(k);
    int** tempB = createMatrix(k);
    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, tempA, k);
    addMatrix(B11, B22, tempB, k);
    int** M1 = multiplyStrassen(tempA, tempB, k);
    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, tempA, k);
    int** M2 = multiplyStrassen(tempA, B11, k);
    // M3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, tempB, k);
    int** M3 = multiplyStrassen(A11, tempB, k);
    // M4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, tempB, k);
    int** M4 = multiplyStrassen(A22, tempB, k);
    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, tempA, k);
    int** M5 = multiplyStrassen(tempA, B22, k);
    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, tempA, k);
    addMatrix(B11, B12, tempB, k);
    int** M6 = multiplyStrassen(tempA, tempB, k);
    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, tempA, k);
    addMatrix(B21, B22, tempB, k);
    int** M7 = multiplyStrassen(tempA, tempB, k);
    // C11 = M1 + M4 - M5 + M7
    int** C11 = createMatrix(k);
    addMatrix(M1, M4, tempA, k);
    subtractMatrix(tempA, M5, tempB, k);
    addMatrix(tempB, M7, C11, k);
    // C12 = M3 + M5
    int** C12 = createMatrix(k);
    addMatrix(M3, M5, C12, k);
    // C21 = M2 + M4
    int** C21 = createMatrix(k);
    addMatrix(M2, M4, C21, k);
    // C22 = M1 - M2 + M3 + M6
    int** C22 = createMatrix(k);
    subtractMatrix(M1, M2, tempA, k);
    addMatrix(tempA, M3, tempB, k);
    addMatrix(tempB, M6, C22, k);
    // Group parts back into result matrix C
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            C[i][j]         = C11[i][j];
            C[i][j + k]     = C12[i][j];
            C[i + k][j]     = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
    // Cleanup dynamic memory
    freeMatrix(A11, k); freeMatrix(A12, k); freeMatrix(A21, k); freeMatrix(A22, k);
    freeMatrix(B11, k); freeMatrix(B12, k); freeMatrix(B21, k); freeMatrix(B22, k);
    freeMatrix(tempA, k); freeMatrix(tempB, k);
    freeMatrix(M1, k); freeMatrix(M2, k); freeMatrix(M3, k); freeMatrix(M4, k);
    freeMatrix(M5, k); freeMatrix(M6, k); freeMatrix(M7, k);
    freeMatrix(C11, k); freeMatrix(C12, k); freeMatrix(C21, k); freeMatrix(C22, k);
    return C;
}
#endif
