#ifndef PASCALS_TRIANGLE_H
#define PASCALS_TRIANGLE_H
using namespace std;
// Generates Pascal's Triangle using a 2D dynamic array
inline int** generatePascalsTriangle(int n) {
    if (n <= 0) return nullptr;
    int** triangle = new int*[n];
    for (int i = 0; i < n; ++i) {
        triangle[i] = new int[i + 1];
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}
#endif
