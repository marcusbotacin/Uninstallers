// Enumerating MSI instances
// Developed by Marcus Botacin 

#include <Windows.h>
#include <iostream>
#include <Msi.h>

#pragma comment(lib, "msi.lib")

using namespace std;

int main()
{
	UINT ret;
	DWORD dwIndex = 0;
	char buff[39];
	printf("Printing installed apps\n");
	do{
		ret = MsiEnumProductsA(dwIndex,buff);
		if (ret==ERROR_SUCCESS){
			char name[1024];
			DWORD size = 1024;
			MsiGetProductInfoA(buff,"InstalledProductName",name,&size);
			printf("%s\n",name);
		}
		dwIndex++;
	}while(ret!=ERROR_NO_MORE_ITEMS);
	printf("Bye...\n");
	return 0;
}
