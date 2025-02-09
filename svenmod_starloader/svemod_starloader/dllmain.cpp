/**
 * Copyright - xWhitey, 2025.
 * dllmain.cpp - The file with our DLL entrypoint.
 *
 * svenmod_starloader (SvenMod wrapper for StarLoader) source file
 * Authors: xWhitey. Refer to common.hpp file for dependencies and their authors.
 * Do not delete this comment block. Respect others' work!
 */

#include "StdAfx.h"

void* g_pSelfHandle;

#define FILESYSTEM_INTERFACE_VERSION "VFileSystem009"
#define SVENMOD_INTERFACE_VERSION "SvenMod001"

class ISvenMod
{
public:
	virtual ~ISvenMod() {}

	virtual bool Init(void* pCommandLine, void* pFileSystem, void* pRegistry) = 0;
	virtual void Shutdown() = 0;
};

void* g_pFileSystemInterface;
ISvenMod* g_pSvenModInterface;

typedef void*(*_CreateInterface)(const char* _Name, int* _ReturnCode);

bool LoadFileSystem() {
	HMODULE hLibrary = LoadLibraryA("filesystem_stdio.dll");
	if (!hLibrary)
		return false;

	_CreateInterface pfnCreateInterface = (_CreateInterface) GetProcAddress(hLibrary, "CreateInterface");

	if (!pfnCreateInterface)
		return false;

	g_pFileSystemInterface = pfnCreateInterface(FILESYSTEM_INTERFACE_VERSION, NULL);

	if (!g_pFileSystemInterface)
		return false;

	return true;
}

bool LoadSvenMod() {
	HMODULE hLibrary = LoadLibraryA("svenmod.dll");
	if (!hLibrary)
		return false;

	_CreateInterface pfnCreateInterface = (_CreateInterface)GetProcAddress(hLibrary, "CreateInterface");

	if (!pfnCreateInterface)
		return false;

	g_pSvenModInterface = (ISvenMod*) pfnCreateInterface(SVENMOD_INTERFACE_VERSION, NULL);

	if (!g_pSvenModInterface)
		return false;

	return true;
}

//Can also be "ASIMain"
//it MUST be extern "C" because C++ has name mangling so GetProcAddress will fail
extern "C" void __declspec(dllexport) __cdecl InitializeASI() {
	if (!LoadFileSystem()) {
		MessageBoxA(NULL, "Failure loading filesystem module!", PLUGIN_NAME, MB_ICONERROR);

		return;
	}
	if (!LoadSvenMod()) {
		MessageBoxA(NULL, "Failure loading SvenMod module!", PLUGIN_NAME, MB_ICONERROR);

		return;
	}
	CommandLine()->CreateCmdLine(GetCommandLine());

	g_pSvenModInterface->Init(CommandLine(), g_pFileSystemInterface, Registry());
}

//Can also be DeinitializeASI
//it MUST be extern "C" because C++ has name mangling so GetProcAddress will fail
extern "C" void __declspec(dllexport) __cdecl ASIShutdown() {
	if (g_pSvenModInterface)
		g_pSvenModInterface->Shutdown();
}

DWORD WINAPI DllMain( _In_ void* _DllHandle, _In_ unsigned long _Reason, _In_opt_ void* _Reserved )
{
	if (_Reason == DLL_PROCESS_ATTACH)
	{
		g_pSelfHandle = _DllHandle;
	}

	return TRUE;
}