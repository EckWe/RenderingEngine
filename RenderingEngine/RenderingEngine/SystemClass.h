#ifndef SYSTEMCLASS_H
#define SYSTEMCLASS_H
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include "inputclass.h"
#include "graphicsclass.h"

class SystemClass {
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void RUn();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;
};
//Function prototypes
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Globals
static SystemClass* ApplicationHandle = 0;

#endif