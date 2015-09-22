#pragma once
//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Core/Components/IComponentInterface.h"
#include <memory>

//=============================================================================
// INTERFACE IWeaponComponentInterface
//=============================================================================
class IWeaponComponentInterface : virtual public IComponentInterface
{
public:
	static IdType TypeId();

public:
	virtual void fire() = 0;
};

typedef std::shared_ptr<IWeaponComponentInterface> WeaponComponentInterfaceRef;
