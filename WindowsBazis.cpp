//-----------------------------------------------------------------------------
//	WindowsBazis.cpp
//	������ ���������� ������� ���������� ���� � Windows
//-----------------------------------------------------------------------------

#include <Windows.h>

//-----------------------------------------------------------------------------
//	�������:
//	MainWinProc
//		- ����� ���������� ��������� ���������
//-----------------------------------------------------------------------------

LRESULT CALLBACK MainWinProc(
	HWND		hwnd,				// ���������� ����
	UINT		msg,				// ������������� �������
	WPARAM		wparam,				// �������������� ����������
	LPARAM		lparam)				// �������������� ����������
{
	switch (msg)
	{
	case WM_PAINT:
		break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	default:
		break;
	}
	return (DefWindowProc(hwnd, msg, wparam, lparam));
}

//-----------------------------------------------------------------------------
//	�������
//	WinMain
//		- ������� ����� ����������
//-----------------------------------------------------------------------------
int WINAPI WinMain(
	HINSTANCE	hInstance,			// ���������� ���� (������������ �� ��� �����������)
	HINSTANCE	hPrevInstance,		// �� ������������ (��� �������� ������������� �����)
	LPSTR		lpCmdLine,			// ��������� �� ��������� ������, ������� ���� ����� �� ������ ����������� �������
	int			nCmdShow)			// ���������, ��� ���� ����� ������������ �� �������� ��� �������� (Win32 API)
{
	WNDCLASSEX windowsClass;
	windowsClass.cbSize = sizeof(WNDCLASSEX);
	windowsClass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
	windowsClass.lpfnWndProc = MainWinProc;
	windowsClass.cbClsExtra = 0;
	windowsClass.cbWndExtra = 0;
	windowsClass.hInstance = hInstance;
	windowsClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowsClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowsClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	windowsClass.lpszMenuName = NULL;
	windowsClass.lpszClassName = L"WINDOWSCLASS";
	windowsClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&windowsClass)) return 0;

	HWND hwnd;
	if (!(hwnd = CreateWindowEx(
		NULL, L"WindowsClass", L"������� ���� ��� DirectX",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 500, 400,
		NULL, NULL,	hInstance, NULL)))
	{
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	// ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);

	MSG	msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
