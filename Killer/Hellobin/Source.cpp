// Identifies parent PID and terminate it
// Adapted by: Marcus Botacin
// Original sources over the code

#include<stdio.h>
#include<Windows.h>

ULONG_PTR GetParentProcessId() // By Napalm @ NetCore2K
{
 ULONG_PTR pbi[6];
 ULONG ulSize = 0;
 LONG (WINAPI *NtQueryInformationProcess)(HANDLE ProcessHandle, ULONG ProcessInformationClass,
  PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength); 
 *(FARPROC *)&NtQueryInformationProcess = 
  GetProcAddress(LoadLibraryA("NTDLL.DLL"), "NtQueryInformationProcess");
 if(NtQueryInformationProcess){
  if(NtQueryInformationProcess(GetCurrentProcess(), 0,
    &pbi, sizeof(pbi), &ulSize) >= 0 && ulSize == sizeof(pbi))
     return pbi[5];
 }
 return (ULONG_PTR)-1;
}

void getnamefrompid(int pid, char* parent)
{
	HANDLE Handle = OpenProcess(
        PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
        FALSE,
        pid /* This is the PID, you can find one from windows task manager */
    );
    if (Handle) 
    {
		DWORD size=200;
		QueryFullProcessImageNameA(Handle, 0,parent,&size);
	}
}

int main()
{
	char parent[200];
    // we only use this for debugging
    // showing users which process is the parent to be terminated
	getnamefrompid(GetParentProcessId(),parent);
	MessageBoxA(NULL,parent,"Uninstall\n",0);
    // actually finish the process
	TerminateProcess(OpenProcess(PROCESS_ALL_ACCESS,false,GetParentProcessId()),0);
	return 0;
}
