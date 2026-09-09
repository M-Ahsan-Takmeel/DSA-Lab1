#ifndef TASK_3_FUNCTION_H
#define TASK_3_FUNCTION_H
#include <iostream>
using namespace std;
// Implementation function: loops through a plain array and prints matching indices
inline void printIndices(const int arr[], int size, int target) {
    bool found = false;

    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] == target) 
        {
            cout << i << " ";
            found = true;
        }
    }

    if (size == 0) 
    {
        cout << "Empty array";
    }
    else if (!found) 
    {
        cout << "Key not present";
    }
    cout << "\n";
}
#endif
