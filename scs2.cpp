#define WIN32_LEAN_AND_MEAN 

#include <windows.h>
#include <thread>
#include <chrono>
#include <string>

#include "util/config.hpp"
#include "gui/overlay.hpp"
#include "util/MemMan.hpp"
#include "util/attributes.hpp"

LRESULT Wndproc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) {
		return 0;
	}
	switch (msg) {
	case WM_SYSCOMMAND: {
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;
	}

	case WM_DESTROY: {
		PostQuitMessage(0);
		return 0;
	}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void printProgressBar(HANDLE hConsole, int percent) {
	const int barWidth = 50;
	std::string bar = "[";
	int pos = barWidth * percent / 100;
	for (int i = 0; i < barWidth; ++i) {
		if (i < pos) bar += "=";
		else if (i == pos) bar += ">";
		else bar += " ";
	}
	bar += "]";
	SetConsoleTextAttribute(hConsole, 14);
	printf("\r%s %d%%", bar.c_str(), percent);
	fflush(stdout);
}

void printHeader(HANDLE hConsole) {
	SetConsoleTextAttribute(hConsole, 11);
	printf("\n===========================\n");
	printf("  Sneaky's CS2 Menu (SCS2)  \n");
	printf("===========================\n\n");
	SetConsoleTextAttribute(hConsole, 7);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printHeader(hConsole);

	// Memory and game related vars (used in entry and passed through overlay)
	int procId = MemMan.getPid(L"cs2.exe");
	SetConsoleTextAttribute(hConsole, 9);
	if (procId == 0)
		printf("[MemMan] Waiting For Counter Strike 2 to launch...\n");
	while (procId == 0) {
		procId = MemMan.getPid(L"cs2.exe");
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}
	SetConsoleTextAttribute(hConsole, 10);
	printf("[MemMan] Counter Strike 2 Found (%d)!\n", procId);
	SetConsoleTextAttribute(hConsole, 9);
	printf("[Config.hpp] Checking for config file...\n");
	if (config::exists()) {
		SetConsoleTextAttribute(hConsole, 10);
		printf("[Config.hpp] Config File Found! Loading preferred config...\n");
		config::load();
	}
	else {
		SetConsoleTextAttribute(hConsole, 12);
		printf("[Config.hpp] Config File Not Found! Loading Defaults...\n");
		config::create();
		config::save();
	}

	// simulate progress for config load - will implement actual functionality for each step eventually but im going to bed
	for (int i = 0; i <= 100; i += 20) {
		printProgressBar(hConsole, i);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	printf("\n");

	SetConsoleTextAttribute(hConsole, 9);
	printf("[scs2.cpp] Getting addresses...\n");
	MemoryManagement::moduleData client;
	client.module = MemMan.getModule(procId, L"client.dll");
	client.base = MemMan.getModuleBase(procId, "client.dll");
	while (client.base == 0 || client.module == 0) {
		client.module = MemMan.getModule(procId, L"client.dll");
		client.base = MemMan.getModuleBase(procId, "client.dll");
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}
	SetConsoleTextAttribute(hConsole, 10);
	printf("[scs2.cpp] Addresses found successfully!\n");

	SetConsoleTextAttribute(hConsole, 9);
	printf("[scs2.cpp] Creating overlay...\n");
	// Overlay
	overlayESP overlayClass;
	WNDCLASSEXW windowClass = overlayClass.createWindowClass(hInstance, Wndproc, L"SCS2");
	HWND window = overlayClass.createWindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

	SetConsoleTextAttribute(hConsole, 9);
	printf("[scs2.cpp] Drawing overlay...\n");
	overlayClass.makeFrameIntoClientArea();
	overlayClass.makeDeviceAndSwapChain();
	overlayClass.initWindow(nShowCmd);

	SetConsoleTextAttribute(hConsole, 9);
	printf("[overlay.cpp] Starting main loop...\n");
	overlayClass.renderLoop(client);

	return 0;
}