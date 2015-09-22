#pragma once
//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Core/Components/IComponentInterface.h"

//=============================================================================
// INTERFACE IHealthComponentInterface
//=============================================================================
class IHealthComponentInterface : virtual public IComponentInterface
{
public:
	static IdType TypeId();

public:
	virtual void setHealth(float iHealth) = 0;
	virtual void changeHealth(float iDeltaHealth) = 0;
	virtual float getHealth() = 0;
};