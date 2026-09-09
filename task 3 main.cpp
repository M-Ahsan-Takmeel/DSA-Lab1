#include <iostream>
#include "task_3_function.h"
using namespace std;
int main() {
    cout << "=== Running Specified Test Cases ===\n\n";
    // Test Case 1: Multiple occurrences
        int arr[] = {1, 3, 7, 3, 5, 3, 9};
        int size = sizeof(arr) / sizeof(arr[0]);
        int target = 3;
        cout << "Test 1 (Multiple occurrences): ";
        printIndices(arr, size, target); 
    // Test Case 2: Key not present
        int arr[] = {10, 20, 30, 40, 50};
        int size = sizeof(arr) / sizeof(arr[0]);
        int target = 99;
        cout << "Test 2 (Key not present):     ";
        printIndices(arr, size, target);
    // Test Case 3: Empty array
        const int* arr = nullptr;
        int size = 0;
        int target = 5;
        cout << "Test 3 (Empty array):         ";
        printIndices(arr, size, target); 
    return 0;
}
