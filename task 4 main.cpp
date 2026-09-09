#include <iostream>
#include "task_4_function.h"
using namespace std;
void runTest(const char* text, const char* pattern, const char* testName, int expected) {
    int result = findPattern(text, pattern);
    cout << testName << "\n";
    cout << "  Text:     \"" << text << "\"\n";
    cout << "  Pattern:  \"" << pattern << "\"\n";
    cout << "  Result:   " << result;
    cout << " (Expected: " << expected << ") ";
    if (result == expected) 
        cout << "[PASS]\n\n";
    else 
        cout << "[FAIL]\n\n";
}
int main() 
{
    cout << "=== String Pattern Matching (Naive Algorithm) ===\n\n";
    //Test Case 1: Pattern at the beginning
    runTest("hello world", "hello", "Test 1: Pattern at the beginning", 0);
    //Test Case 2: Pattern at the end
    runTest("hello world", "world", "Test 2: Pattern at the end", 6);
    // Test Case 3: Pattern not present
    runTest("hello world", "python", "Test 3: Pattern not present", -1);
    //Test Case 4: Empty pattern
    runTest("hello world", "", "Test 4: Empty pattern", 0);
    return 0;
}
