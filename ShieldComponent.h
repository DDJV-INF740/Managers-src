#pragma once

//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "IShieldComponentInterface.h"
#include "Engine/GameObjects/GameObjectComponent.h"

//=============================================================================
// CLASS ShieldComponent
//=============================================================================
class ShieldComponent :
	public engine::GameObjectComponent<ShieldComponent>,
	virtual public IShieldComponentInterface
{
public:
	static engine::IComponent::IdType TypeId();

	static IComponentInterface::IdType* Interfaces()
	{
		static IComponentInterface::IdType sInterfaces[] = {
			IShieldComponentInterface::TypeId(),
			0
		};

		return sInterfaces;
	}

public:
	virtual void setAbsorptionRatio(float iAbsorptionRatio);

public: // IShieldComponentInterface
	virtual float absorbDamage(float iDamage);

private:
	float _absorptionRatio;

public:
	ShieldComponent();
};

typedef std::shared_ptr<ShieldComponent> ShieldComponentRef;


