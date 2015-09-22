#pragma once
//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Core/Components/IComponentInterface.h"
#include <memory>
//=============================================================================
// INTERFACE IDamageComponentInterface
//=============================================================================
class IDamageComponentInterface : virtual public IComponentInterface
{
public:
	static IdType TypeId();

public:
	virtual void takeDamage(float iDamage) = 0;
};

typedef std::shared_ptr<IDamageComponentInterface> DamageInterfaceRef;