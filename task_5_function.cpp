#include <iostream>
#include "task_5_function.h"
using namespace std;
void printAndFree(int** triangle, int n) 
{
    if (n <= 0 || !triangle) 
    {
        cout << "[]\n";
        return;
    }
    for (int i = 0; i < n; ++i) 
    {
        cout << "{ ";
        for (int j = 0; j <= i; ++j) 
        {
            cout << triangle[i][j] << (j < i ? ", " : " ");
        }
        cout << "}\n";
    }
    freeTriangle(triangle, n);
}
int main() 
{
    //Test Case 1: n = 0
    cout << "n = 0:\n";
    int** t0 = generatePascalsTriangle(0);
    printAndFree(t0, 0);
    //Test Case 2: n = 1
    cout << "\nn = 1:\n";
    int** t1 = generatePascalsTriangle(1);
    printAndFree(t1, 1);
    //Test Case 3: n = 5
    cout << "\nn = 5:\n";
    int** t5 = generatePascalsTriangle(5);
    printAndFree(t5, 5);
    return 0;
}
