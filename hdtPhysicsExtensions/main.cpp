#include "skse/PluginAPI.h"
#include "skse/skse_version.h"
#include "skse/SafeWrite.h"
#include "skse/GameAPI.h"

#include <Windows.h>
#include <fstream>
#include <detours.h>

#include "World.h"
#include "HookArmor.h"
#include "HookWeapon.h"
#include "HookRender.h"
#include "HookHair.h"
#include "HookMenu.h"
#include "HookMessage.h"
#include "HookMemory.h"
#include "ResourceManager.h"
#include "log.h"

PluginHandle g_pluginHandle = kPluginHandle_Invalid;

BOOL WINAPI DllMain(HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
	switch(dwReason)
	{
	case DLL_PROCESS_ATTACH:
		
		DisableThreadLibraryCalls((HMODULE)hDllHandle);
		
		DetourRestoreAfterWith();  
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		
		ResourceManager::get();
		HookArmor();
		HookWeapon();
		HookRender();
		HookHair();
		HookMessage(hDllHandle);
		HookMemory();

		DetourTransactionCommit();

		HDTLogDebug("Hooked!!");
		CWorld::getSingleton();

		break;

	case DLL_PROCESS_DETACH:
				
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		
		DehookArmor();
		DehookWeapon();
		DehookRender();
		DehookHair();
		DehookMessage();
		DehookMemory();
		
		DetourTransactionCommit();

		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	};

	return TRUE;
}

extern "C"
{

bool SKSEPlugin_Query(const SKSEInterface * skse, PluginInfo * info)
{
	HDTLogRaw(PLUGIN_NAME);

	// populate info structure
	info->infoVersion =	PluginInfo::kInfoVersion;
	info->name =		PLUGIN_NAME;
	info->version =		1;

	// store plugin handle so we can identify ourselves later
	g_pluginHandle = skse->GetPluginHandle();

	if(skse->isEditor)
	{
		HDTLogError("loaded in editor, marking as incompatible");

		return false;
	}
	else if(skse->runtimeVersion < RUNTIME_VERSION_1_9_32_0)
	{
		HDTLogError("unsupported runtime version %08X", skse->runtimeVersion);

		return false;
	}

	// ### do not do anything else in this callback
	// ### only fill out PluginInfo and return true/false

	// supported runtime version
	HDTLogInfo("Queue OK");

	MenuManager * mm = MenuManager::GetSingleton();
	if (mm) mm->MenuOpenCloseEventDispatcher()->AddEventSink(&g_freezeEventHandler);

	return true;
}

bool SKSEPlugin_Load(const SKSEInterface* skse)
{
	HDTLogInfo("SKSEPlugin_Load");
	return true;
}

};
