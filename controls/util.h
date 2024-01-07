#include <windows.h>

static void draw_quad(HDC hdc, RECT rect, COLORREF back_color, COLORREF border_color, int border_thickness)
{
    HBRUSH back_brush = CreateSolidBrush(back_color);
    HBRUSH border_brush = CreateSolidBrush(border_color);

    auto prev_object = SelectObject(hdc, border_brush);
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

    SelectObject(hdc, back_brush);
    Rectangle(hdc, rect.left + border_thickness, rect.top + border_thickness, rect.right - border_thickness, rect.bottom - border_thickness);
    
    SelectObject(hdc, prev_object);
    DeleteObject(back_brush);
    DeleteObject(border_brush);
}