#pragma once
//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Core/Components/IComponentInterface.h"

//=============================================================================
// INTERFACE IShieldComponentInterface
//=============================================================================
class IShieldComponentInterface : virtual public IComponentInterface
{
public:
	static IdType TypeId();

public:
	// Returns the left-over damage
	virtual float absorbDamage(float iDamage) = 0;
};