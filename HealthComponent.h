#pragma once

//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "IHealthComponentInterface.h"
#include "IDamageComponentInterface.h"
#include "Engine/GameObjects/GameObjectComponent.h"

//=============================================================================
// CLASS HealthComponent
//=============================================================================
class HealthComponent :
	public GameObjectComponent<HealthComponent>,
	virtual public IHealthComponentInterface,
	virtual public IDamageComponentInterface
{
public:
	static IComponent::IdType TypeId();

	static IComponentInterface::IdType* Interfaces()
	{
		static IComponentInterface::IdType sInterfaces[] = {
			IHealthComponentInterface::TypeId(),
			IDamageComponentInterface::TypeId(),
			0
		};

		return sInterfaces;
	}

	virtual void onAttached(const GameObjectRef &iGameObject) override
	{
		GameObjectComponent::onAttached(iGameObject);
		_go = iGameObject;
	}

	virtual void onDetached(const GameObjectRef &iGameObject) override
	{
		_go.reset();
		GameObjectComponent::onDetached(iGameObject);
	}

private:
	GameObjectRef _go;

public: // IHealthComponentInterface
	virtual void setHealth(float iHealth) override;
	virtual void changeHealth(float iDeltaHealth) override;
	virtual float getHealth() override;

public: // IDamageComponentInterface
	virtual void takeDamage(float iDamage) override;

public:
	HealthComponent();

private:
	float _health;
};

typedef std::shared_ptr<HealthComponent> HealthComponentRef;


