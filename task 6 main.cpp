#include <iostream>
#include "task_6_function.h"
using namespace std;
int main() {
    // Test Case 1: Array with unique mode
    {
        int arr[] = {1, 3, 3, 3, 2, 5, 2};
        int size = sizeof(arr) / sizeof(arr[0]);
        cout << "Test 1 (Unique mode): ";
        printMode(arr, size);
    }
    // Test Case 2: Array with multiple modes
    {
        int arr[] = {1, 2, 2, 3, 3, 4};
        int size = sizeof(arr) / sizeof(arr[0]);
        cout << "Test 2 (Multiple modes): ";
        printMode(arr, size);
    }
    // Test Case 3: Empty array
    {
        int arr[0] = {};
        int size = 0;
        cout << "Test 3 (Empty array): ";
        printMode(arr, size);
    }
    return 0;
}
