#include "button.h"

#include <assert.h>
#include <Windows.h>

namespace Button
{
    LRESULT CALLBACK wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        switch (msg)
        {
        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                RECT rect;
                HDC hdc = BeginPaint(hwnd, &ps);
                GetClientRect(hwnd, &rect);

                HBRUSH brush = CreateSolidBrush(RGB(255,0,0));
                SelectObject(hdc, brush);
                Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
                SelectObject(hdc, nullptr);
                DeleteObject(brush);
                
                EndPaint(hwnd, &ps);
                return 0;
            }
        }
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }

    void register_global()
    {
        WNDCLASS wndclass = {0};
        
        wndclass.style = CS_GLOBALCLASS | CS_HREDRAW | CS_VREDRAW;
        wndclass.lpfnWndProc = (WNDPROC)wndproc;
        wndclass.hInstance = GetModuleHandle(nullptr);
        wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndclass.lpszClassName = class_name;
        RegisterClass(&wndclass);
    }
}
