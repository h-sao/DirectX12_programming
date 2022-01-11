// step01:
// Show blank window
//   written by Akiko Kawai
// ===========================================
// include
#include<Windows.h>
#include<tchar.h>
#include<iostream>

// ===========================================
// definition
const unsigned int window_width = 1280;
const unsigned int window_height = 720;

// ===========================================
// function

/// <summary>
/// Show debug formatted string to console
/// remarks only debug mode
/// </summary>
/// <param name="format">format (%d, %f, ...)</param>
/// <param name="">variable length parameter</param>
void DebugOutputFormatString(const char* format, ...)
{
    va_list valist;
    va_start(valist, format);
    vprintf(format, valist);
    va_end(valist);
}

/// <summary>
/// Make Window procedure
/// </summary>
/// <param name="hwnd"></param>
/// <param name="msg"></param>
/// <param name="wparam"></param>
/// <param name="lparam"></param>
/// <returns></returns>
LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    if (msg == WM_DESTROY) {          // call when discard window
        PostQuitMessage(0);   // tell OS app finessing
        return 0;
    }
    return DefWindowProc(hwnd, msg, wparam, lparam);    //
}

/// <summary>
/// main
/// </summary>
/// <returns></returns>
int main()
{
    DebugOutputFormatString("Show window test.");

    // ---------------------------------
    // make/register window class
    WNDCLASSEX w = {};
    w.cbSize = sizeof(WNDCLASSEX);
    w.lpfnWndProc = (WNDPROC)WindowProcedure;    // setting callback
    w.lpszClassName = _T("DirectXTest");         // application class name
    w.hInstance = GetModuleHandle(0);            // get handle (anything name is OK)
    RegisterClassEx(&w);                         // register application class

    RECT wrc = { 0,0, window_width, window_height };
    AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);  // set window size

    // ---------------------------------
    // make windows object
    HWND hwnd = CreateWindow(w.lpszClassName,  // set class name
        _T("DX12 Test"),                       // title bar character
        WS_OVERLAPPEDWINDOW,                   // title bar border window
        CW_USEDEFAULT,                         // display x pos
        CW_USEDEFAULT,                         // display y pos
        wrc.right - wrc.left,                  // window w
        wrc.bottom - wrc.top,                  // windows h
        nullptr,                               // parent window handle
        nullptr,                               // menu handle
        w.hInstance,                           // call application handle
        nullptr);                              // add parameter

    ShowWindow(hwnd, SW_SHOW);    // show window

    MSG msg = {};
    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        // end of application?
        if (msg.message == WM_QUIT) {
            break;
        }
    }

    // remove
    UnregisterClass(w.lpszClassName, w.hInstance);

    return 0;
}

// ===========================================
// End of file