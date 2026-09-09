#ifndef TASK_5_FUNCTION_H
#define TASK_5_FUNCTION_H
using namespace std;
inline int** generatePascalsTriangle(int n) 
{
    if (n <= 0) return nullptr;
    int** triangle = new int*[n];
    for (int i = 0; i < n; ++i) 
    {
        triangle[i] = new int[i + 1];
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; ++j) 
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}
inline void freeTriangle(int** triangle, int n) 
{
    if (!triangle) return;
    for (int i = 0; i < n; ++i) 
    {
        delete[] triangle[i];
    }
    delete[] triangle;
}

#endif
