#include <Windows.h>
#include <iostream>

using namespace std;

int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d){
  LPCSTR t = "C:\\Downloads\\b.zip\\z\\thing.dll";
  HANDLE b = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 000);
  LPVOID x = VirtualAllocEx(b, 0, strlen(t) + 1, MEM_COMMIT, PAGE_READWRITE);
  WriteProcessMemory(b, x, (LPVOID)t, strlen(t) + 1, 0);
  HANDLE thread = CreateRemoteThread(b, 0, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32.dll"), "LoadLibraryA"), t, 0, 0);
  WaitForSingleObject(thread, INFINITE);
  cout << "DLL Injected!" << endl;
  VirtualFreeEx(t, x, strlen(t) + 1, MEM_RELEASE);
}
