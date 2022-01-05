#include <windows.h>
#include <iostream>
#pragma comment(lib,"user32.lib")


int main()
{
    MessageBoxA(NULL, "hello", "hello", MB_OK);
    MessageBoxA(NULL, "hello", "hello", MB_OK);
    MessageBoxA(NULL, "um hello?", "helllooo", MB_OK);
    MessageBoxA(NULL, "hmmm this", "isn't working", MB_OK);
    return 0;
}