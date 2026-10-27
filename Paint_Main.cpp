#include<windows.h>

LRESULT WndProc(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM lParam)
{
	switch (msgId)
	{
	case WM_PAINT:
	{
		RECT rect;
		HDC hDc;
		PAINTSTRUCT ps;
		

		GetClientRect(hWnd, &rect);

		hDc = BeginPaint(hWnd, &ps);
		DrawText(hDc, "Hello",-1, &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(1);
		break;
	default:
		return DefWindowProc(hWnd, msgId, wParam, lParam);
	}
	return 0;
}
int WinMain(HINSTANCE hInstance, HINSTANCE HPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX wx;

	wx.cbSize = sizeof(WNDCLASSEX);
	wx.lpszClassName = "MyWindow";
	wx.hInstance = hInstance;
	wx.cbClsExtra = NULL;
	wx.cbWndExtra = NULL;
	wx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wx.lpfnWndProc = WndProc;
	wx.lpszMenuName = NULL;
	wx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wx.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClassEx(&wx);

	HWND hWnd = CreateWindowEx(0, "MyWindow", "Untitled", WS_OVERLAPPEDWINDOW, 100, 100, 600, 400, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, 1);

	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

