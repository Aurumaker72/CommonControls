#include "button.h"
#include <Windows.h>

namespace Button {

	LRESULT CALLBACK wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	void register_global()
	{
		WNDCLASS wndclass = {0};

		wndclass.style = CS_DBLCLKS | CS_PARENTDC | CS_HREDRAW | CS_VREDRAW;
		wndclass.lpfnWndProc = (WNDPROC)wndproc;
		wndclass.hInstance = GetModuleHandle(nullptr);
		wndclass.hCursor = LoadCursor(NULL, (LPTSTR)IDC_IBEAM);
		wndclass.lpszClassName = class_name;
		RegisterClass(&wndclass);
	}

}
