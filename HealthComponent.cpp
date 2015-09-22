//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Precompiled.h"
#include "HealthComponent.h"
#include "Core/GameObjects/IGameObject.h"
#include "IShieldComponentInterface.h"
#include <iostream>
#include <Core/Game/Game.h>
#include <Core/GameManagers/IGameSpawner.h>

//=============================================================================
// CLASS HealthComponent
//=============================================================================

HealthComponent::HealthComponent() : _health(1.0f)
{}


void HealthComponent::setHealth(float iHealth)
{
	_health = iHealth;
}

void HealthComponent::changeHealth(float iDeltaHealth)
{
	_health += iDeltaHealth;
	std::cout << "Health: " << _health << std::endl;
}

float HealthComponent::getHealth()
{
	return _health;
}

void HealthComponent::takeDamage(float iDamage)
{
	float damage = iDamage;
	changeHealth(-damage);
}


//=============================================================================
// COMPONENT REGISTRATION
//=============================================================================
#include "Engine/Components/ComponentFactory.h"
IComponent::IdType HealthComponent::TypeId() { return "HealthComponent"; }
RegisterComponentType<HealthComponent> *gRegisteredComponent = new RegisterComponentType<HealthComponent>();

