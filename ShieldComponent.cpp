//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Precompiled.h"

#include "ShieldComponent.h"
#include "Core/GameObjects/IGameObject.h"

//=============================================================================
// CLASS ShieldComponent
//=============================================================================

ShieldComponent::ShieldComponent()
	: _absorptionRatio(0.0f)
{}


void ShieldComponent::setAbsorptionRatio(float iAbsorptionRatio)
{
	_absorptionRatio = iAbsorptionRatio;
}

float ShieldComponent::absorbDamage(float iDamage)
{
	float absorbedDamage = _absorptionRatio*iDamage;
	float remainingDamage = iDamage - absorbedDamage;
	if (remainingDamage > 0.0f)
		return remainingDamage;
	else
		return 0.0f;
}

//=============================================================================
// COMPONENT REGISTRATION
//=============================================================================
#include "Engine/Components/ComponentFactory.h"
IComponent::IdType ShieldComponent::TypeId() { return "ShieldComponent"; }
RegisterComponentType<ShieldComponent> *gRegisteredComponent = new RegisterComponentType<ShieldComponent>();

