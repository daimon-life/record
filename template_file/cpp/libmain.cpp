#include <iostream>

void Lib_Initialise()
{
	std::cout << "Init lib " << __LINE__ << std::endl;
}

void Lib_DeInitialise()
{
	std::cout << "Deinit lib " << __LINE__ << std::endl;
}

// Windows dllmain
#if defined(WIN32) || defined(WIN64)
#include <windows.h>
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
