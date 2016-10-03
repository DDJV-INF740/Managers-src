#include "Precompiled.h"
//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include <Core/Game/IGameEngine.h>
#include <windows.h>
#include <tchar.h>
//-----------------------------------------------------------------------------
// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	engine::IGameEngine::Instance()->init();

	while (engine::IGameEngine::Instance()->run())
	{}

	engine::IGameEngine::Instance()->cleanup();

	return 0;
}

//-----------------------------------------------------------------------------
//
int _tmain(int argc, _TCHAR* argv[])
{
	return WinMain(GetModuleHandle(NULL), 0, nullptr, true);
}




