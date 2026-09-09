#ifndef TASK_4_FUNCTION_H
#define TASK_4_FUNCTION_H
using namespace std;
inline int getLength(const char* str) 
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}
inline int findPattern(const char* text, const char* pattern) 
{
    int textLen = getLength(text);
    int patternLen = getLength(pattern);
    // Edge Case: Empty pattern matches at index 0
    if (patternLen == 0) 
    {
        return 0;
    }
    // Outer loop shifts pattern across text
    for (int i = 0; i <= textLen - patternLen; ++i) 
    {
        int j = 0;
        // Inner loop checks character match
        while (j < patternLen && text[i + j] == pattern[j]) 
        {
            j++;
        }
        //Whole pattern matched
        if (j == patternLen) 
        {
            return i;
        }
    }
    return -1; //Pattern not found
}
#endif
