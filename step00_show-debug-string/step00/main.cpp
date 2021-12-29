// step00:
// Show debug string
//   written by Akiko Kawai
// ===========================================

#include<Windows.h>

#include<iostream>

///@brief Show debug formatted string to console
///@param format (%d, %f, ...)
///@param variable length parameter
///@remarks only debug mode
void DebugOutputFormatString(const char* format, ...)
{
    va_list valist;
    va_start(valist, format);
    vprintf(format, valist);
    va_end(valist);
}

int main()
{
    DebugOutputFormatString("Show window test.");
    getchar();

    return 0;
}

// ===========================================
// End of file