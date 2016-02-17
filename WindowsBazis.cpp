//-----------------------------------------------------------------------------
//	WindowsBazis.cpp
//	данное приложение создает простейшее окно в Windows
//-----------------------------------------------------------------------------

#include <Windows.h>

//-----------------------------------------------------------------------------
//	функция:
//	MainWinProc
//		- здесь происходит обработка сообщений
//-----------------------------------------------------------------------------

LRESULT CALLBACK MainWinProc(
	HWND		hwnd,				// дескриптор окна
	UINT		msg,				// идентификатор события
	WPARAM		wparam,				// дополнительная информация
	LPARAM		lparam)				// дополнительная информация
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
//	функция
//	WinMain
//		- входная точка приложения
//-----------------------------------------------------------------------------
int WINAPI WinMain(
	HINSTANCE	hInstance,			// дескриптор окна (генерируется ОС для ослеживания)
	HINSTANCE	hPrevInstance,		// не используется (для обратной совместимости нужен)
	LPSTR		lpCmdLine,			// указатель на командную строку, которая идет сразу за именем запускаемой команды
	int			nCmdShow)			// указывает, как окно будет отображаться на мониторе при создании (Win32 API)
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
		NULL, L"WindowsClass", L"Базовое окно для DirectX",
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
