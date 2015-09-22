#pragma once

//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "IWeaponComponentInterface.h"
#include "IDamageComponentInterface.h"
#include "Engine/GameObjects/GameObjectComponent.h"

//=============================================================================
// CLASS WeaponComponent
//=============================================================================
class WeaponComponent :
	public GameObjectComponent<WeaponComponent>,
	virtual public IWeaponComponentInterface
{
public:
	static IComponent::IdType TypeId();

	static IComponentInterface::IdType* Interfaces()
	{
		static IComponentInterface::IdType sInterfaces[] = {
			IWeaponComponentInterface::TypeId(),
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

public: // IWeaponComponentInterface
	virtual void fire() override;

public:
	WeaponComponent();
};

typedef std::shared_ptr<WeaponComponent> WeaponComponentRef;


