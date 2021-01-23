#include <cstdio>

// Windows dllmain
#if defined(WIN32) || defined(WIN64)
#include <windows.h>
void Lib_Initialise();
void Lib_DeInitialise();
BOOL APIENTRY DllMain(HANDLE hMoudle, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Lib_Initialise();
		break;
	case DLL_PROCESS_DETACH:
		Lib_DeInitialise();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
#endif
// Macos and linux dllmain
#if defined(__APPLE__) || defined(__linux__)
void Lib_Initialise() __attribute__((constructor));
void Lib_DeInitialise() __attribute__((destructor));
#endif

void Lib_Initialise()
{
	printf("Init lib %d\n",__LINE__);
}

void Lib_DeInitialise()
{
	printf("Deinit lib %d\n",__LINE__);
}
