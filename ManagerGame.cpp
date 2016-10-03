#include "Precompiled.h"

//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "ManagerGame.h"
#include <Engine/Game/GameEngine.h>
#include <PxPhysicsAPI.h>
#include "PlayerBehaviour.h"
#include "SampleGO.h"

#include <Core/Game/Game.h>
#include <Engine/Components/InputComponent.h>

#include <Engine/Tasks/RenderTask.h>
#include <Engine/Tasks/PlayerTask.h>
#include <Engine/Tasks/InputTask.h>
#include <Engine/Tasks/AITask.h>
#include <Engine/Tasks/PhysicsTask.h>
#include <Engine/Tasks/GameRulesTask.h>
#include <Engine/Tasks/TimeTask.h>
#include <Engine/Tasks/SpawnTask.h>

#include <Engine/Managers/RenderManager.h>
#include <Engine/Managers/WindowManager.h>
#include <Engine/Managers/CameraManager.h>
#include <Engine/Managers/SimulationManager.h>
#include <Engine/Managers/PlayerManager.h>
#include <Engine/Managers/AIManager.h>
#include <Engine/Managers/GameLoopManager.h>
#include <Engine/Managers/TimeManager.h>
#include <Engine/Managers/SpawnManager.h>

#include <Engine/Rendering/Camera.h>
#include "WeaponComponent.h"

using namespace physx;

//=============================================================================
// CLASS ManagerGame
//=============================================================================
class ManagerGame: public GameEngine
{
public:

	enum
	{
		TIMERTASK,
		INPUTTASK,
		PLAYERTASK,
		AITASK,
		PHYSICSTASK,
		GAMERULESTASK,
		RENDERTASK,
		SPAWNTASK,
	};


	ManagerGame()
	{
	}

	virtual bool init() override
	{
		ensureComponent<WindowManager>();
		ensureComponent<RenderManager>();
		ensureComponent<SimulationManager>();
		ensureComponent<SpawnManager>();
		ensureComponent<AIManager>();
		ensureComponent<PlayerManager>();
		ensureComponent<CameraManager>();
		ensureComponent<GameLoopManager>();
		ensureComponent<TimeManager>();

		addTask<SpawnTask>(SPAWNTASK);
		addTask<RenderTask>(RENDERTASK);
		addTask<PlayerTask>(PLAYERTASK);
		addTask<InputTask>(INPUTTASK);
		addTask<AITask>(AITASK);
		addTask<GameRulesTask>(GAMERULESTASK);
		addTask<PhysicsTask>(PHYSICSTASK);
		addTask<TimeTask>(TIMERTASK);

		GameEngine::init();
		loadLevel();
		return true;
	}

	virtual bool cleanup() override
	{
		unloadLevel();

		return GameEngine::cleanup();
	}


	~ManagerGame()
	{}

	void loadLevel();

	void unloadLevel()
	{
		// unspawn every remaining objects
		Game<ISpawnManager>()->unspawnAll();
		Game<ISpawnManager>()->update();
	}
};



GameEngineRef& IGameEngine::Instance()
{
	static GameEngineRef sGame(new ManagerGame);
	return sGame;
}


void ManagerGame::loadLevel()
{
	// spawn the player
	GameObjectRef _player = Game<ISpawnManager>()->spawn<SampleGO>(PxTransform(PxVec3(0, 0, 0)));
	_player->ensureComponent<KeyboardInputComponent>();
	_player->ensureComponent<PlayerComponent>()->setBehaviour(IBehaviourRef(new PlayerBehaviour));

	_player->ensureComponent<WeaponComponent>();

	Game<ISpawnManager>()->spawn<ICamera>(PxTransform(PxVec3(0, 0, 0)));

	// spawn an enemy
	Game<ISpawnManager>()->spawn<SampleGO>(PxTransform(PxVec3(0, 0, 0)));
}



