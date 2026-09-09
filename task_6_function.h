#ifndef TASK_6_FUNCTION_H
#define TASK_6_FUNCTION_H
#include <iostream>
using namespace std;
inline void printMode(const int arr[], int size) 
{
    if (size <= 0) 
    {
        cout << "Empty array\n";
        return;
    }
    // Step 1: Find the maximum frequency of any element
    int maxFreq = 0;
    for (int i = 0; i < size; ++i) 
    {
        int count = 0;
        for (int j = 0; j < size; ++j) 
        {
            if (arr[j] == arr[i]) 
            {
                count++;
            }
        }
        if (count > maxFreq) 
        {
            maxFreq = count;
        }
    }
    // Step 2: Output element(s) matching the maximum frequency (avoiding duplicate prints)
    cout << "Mode(s): ";
    for (int i = 0; i < size; ++i) 
    {
        // Check if this element was already printed earlier
        bool alreadyPrinted = false;
        for (int k = 0; k < i; ++k) 
        {
            if (arr[k] == arr[i]) 
            {
                alreadyPrinted = true;
                break;
            }
        }
        if (!alreadyPrinted) 
        {
            int count = 0;
            for (int j = 0; j < size; ++j) 
            {
                if (arr[j] == arr[i]) 
                {
                    count++;
                }
            }
            if (count == maxFreq) 
            {
                cout << arr[i] << " ";
            }
        }
    }
    cout << "\n";
}
#endif
