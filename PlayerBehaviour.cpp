#include "Precompiled.h"

#include "PlayerBehaviour.h"

#include <Core/GameObjects/IGameObject.h>
#include <Engine/Components/InputComponent.h>
#include <Engine/Managers/SpawnManager.h>
#include <Core/Game/Game.h>
#include <Core/GameManagers/ITimeManager.h>
#include <Core/Logging/Logger.h>
#include <Engine/Components/SimulationComponent.h>
#include <PxPhysicsAPI.h>
#include <iostream>
#include "IWeaponComponentInterface.h"

using namespace physx;

void PlayerBehaviour::update( const GameObjectRef &iGameObject )
{
	std::shared_ptr<IKeyboardInputInterface> keyboardInput = iGameObject->as<IKeyboardInputInterface>();

	static float kRotateStep = 0.02f; // angle in radians
	if (keyboardInput->isPressed(ControllerKey::KEY_CTRLBUTTON))
	{
		WeaponComponentInterfaceRef weapon = iGameObject->as<IWeaponComponentInterface>();
		if (weapon == nullptr)
		{
			LOG_INFO("No weapon");
		}
		else
		{
			weapon->fire();
		}
	}
}
