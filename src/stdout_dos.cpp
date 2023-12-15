#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <Windows.h>
#include <TlHelp32.h>

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
	return TRUE;
}


int main() {
	FreeConsole();
	SetConsoleCtrlHandler(CtrlHandler, TRUE);
	
	HANDLE hSnapshot;
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);
	BOOL consoleAttached;

	char hello[7] = "Hello\n";

	while (true) {
		hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		while (Process32Next(hSnapshot, &pe)) {
			consoleAttached = AttachConsole(pe.th32ProcessID);
			SetConsoleCtrlHandler(CtrlHandler, TRUE);
			if (consoleAttached) {
				HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				WriteConsoleA(hStdOut, hello, 7, NULL, NULL);
			}
			FreeConsole();
			SetConsoleCtrlHandler(CtrlHandler, TRUE);
		}
	}
	return 0;
}
