//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Precompiled.h"

#include "WeaponComponent.h"
#include "Core/GameObjects/IGameObject.h"
#include "IShieldComponentInterface.h"
#include <Core/Game/Game.h>
#include <Engine/Managers/SpawnManager.h>
#include "SampleGO.h"
#include <iostream>
#include <Core/Components/IInputInterface.h>
#include "Core/Logging/Logger.h"

//=============================================================================
// CLASS WeaponComponent
//=============================================================================

WeaponComponent::WeaponComponent()
{}

static bool isPlayer(const GameObjectRef go)
{
	return go->as<IInputInterface>() != nullptr;
}

void WeaponComponent::fire()
{
	GameSpawnerRef spawnManager = Game<ISpawnManager>();
	const std::set<GameObjectRef> gameObjects = spawnManager->gameObjects();

	// for now, all objects are SampleGO - we distinguish the player from the enemy
	// because the player has a IInputInterface interface
	if (gameObjects.size() == 1 && isPlayer(*gameObjects.begin()))
	{
		LOG_INFO("No more enemies");
	}
	else
	{
		for (auto goIter = gameObjects.begin(); goIter != gameObjects.end(); ++goIter)
		{
			if (isPlayer(*goIter))
				continue; // skip player


			DamageInterfaceRef damageInterface = (*goIter)->as<IDamageComponentInterface>();
			if (damageInterface != NULL)
			{
				damageInterface->takeDamage(0.25);
				LOG_INFO("pew!");
				break;
			}
		}
	}
}

//=============================================================================
// COMPONENT REGISTRATION
//=============================================================================
#include "Engine/Components/ComponentFactory.h"
IComponent::IdType WeaponComponent::TypeId() { return "WeaponComponent"; }
RegisterComponentType<WeaponComponent> *gRegisteredComponent = new RegisterComponentType<WeaponComponent>();

