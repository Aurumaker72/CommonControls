#include "button.h"
#include <Windows.h>

namespace Button {

	LRESULT CALLBACK wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	void register_global()
	{
		WNDCLASS AnsiWndCls;

		AnsiWndCls.style = CS_DBLCLKS | CS_PARENTDC;
		AnsiWndCls.lpfnWndProc = (WNDPROC)wndproc;
		AnsiWndCls.cbClsExtra = 0;
		AnsiWndCls.cbWndExtra = 0;
		AnsiWndCls.hInstance = GetModuleHandle(0);
		AnsiWndCls.hIcon = NULL;
		AnsiWndCls.hCursor = LoadCursor(NULL, (LPTSTR)IDC_IBEAM);
		AnsiWndCls.hbrBackground = NULL;
		AnsiWndCls.lpszMenuName = NULL;
		AnsiWndCls.lpszClassName = class_name;
	}

}
