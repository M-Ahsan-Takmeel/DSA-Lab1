#ifndef FIND_INDICES_H
#define FIND_INDICES_H

#include <iostream>

// Implementation function: loops through a plain array and prints matching indices
inline void printIndices(const int arr[], int size, int target) {
    bool found = false;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            std::cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        std::cout << "None";
    }
    std::cout << "\n";
}

#endif // FIND_INDICES_H
    printIndices(numbers, size, target);
    // Output: Indices: 1 3 5 

    return 0;
}
