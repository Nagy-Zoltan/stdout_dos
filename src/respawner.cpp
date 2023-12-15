#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <Windows.h>


int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    while (TRUE) {
        if (!CreateProcess(TEXT("stdout_dos.exe"),
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL, 
            &si,
            &pi)
            )
        {
            return 0;
        }

        WaitForSingleObject(pi.hProcess, INFINITE);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

	return 0;
}