#include <iostream>
#include "find_indices.h"

int main() {
    std::cout << "=== Running Specified Test Cases ===\n\n";

    // Test Case 1: Multiple occurrences
    {
        int arr[] = {1, 3, 7, 3, 5, 3, 9};
        int size = sizeof(arr) / sizeof(arr[0]);
        int target = 3;

        std::cout << "Test 1 (Multiple occurrences): ";
        printIndices(arr, size, target); 
        // Expected Output: 1 3 5
    }

    // Test Case 2: Key not present
    {
        int arr[] = {10, 20, 30, 40, 50};
        int size = sizeof(arr) / sizeof(arr[0]);
        int target = 99;

        std::cout << "Test 2 (Key not present):     ";
        printIndices(arr, size, target); 
        // Expected Output: Key not present
    }

    // Test Case 3: Empty array
    {
        int arr[0] = {};
        int size = 0;
        int target = 5;

        std::cout << "Test 3 (Empty array):         ";
        printIndices(arr, size, target); 
        // Expected Output: Empty array
    }

    return 0;
}
