#pragma once

#include <Windows.h>
#include <TlHelp32.h>

#include "Printa.h"
#include "Xorstr.h"





HWND window;
DWORD procId;
HANDLE hProcess;
uintptr_t Base;


bool GameOpen = false;

uintptr_t GetModuleBaseAddress(const char* modName) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry)) {
			do {
				if (!strcmp(modEntry.szModule, modName)) {
					CloseHandle(hSnap);
					return (uintptr_t)modEntry.modBaseAddr;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
}

bool AttachInfo()
{
	window = FindWindowA(NULL, xorstr("Counter-Strike: Global Offensive - Direct3D 9")); // window of prosses/game
	GetWindowThreadProcessId(window, &procId);
	Base = GetModuleBaseAddress(xorstr("client.dll")); // base of the game
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	while (window == NULL)
	{
		return false;
	}
	return true;
}
void Attach()
{

	while (AttachInfo() == NULL)
	{
		Printa.Loading("Please open Game");
		while (AttachInfo() == NULL)
		{

			GameOpen = false;
		}
	}
	std::cout << std::endl;

	Printa.OK("Found game!");

	Printa.Endl();

	Printa.PrintCol(" Window ", LIGHTCYAN);
	Printa.Arrow(BLUE);
	Printa.SetWhite();
	std::cout << "0x" << window << std::endl;

	Printa.PrintCol(" Base ", LIGHTCYAN);
	Printa.Arrow(BLUE);
	Printa.SetWhite();
	std::cout << "0x" << Base << std::endl;

	GameOpen = true;

}


// Read Function Template
template<typename T> T Read(SIZE_T address)
{
	T buffer;
	ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, sizeof(T), NULL);
	return buffer;
}

// Write Function Template  
template<typename T> void Write(SIZE_T address, T buffer)
{
	WriteProcessMemory(hProcess, (LPVOID)address, &buffer, sizeof(buffer), NULL);
}




