#pragma once

#include "Core/GameObjects/IGameObject.h"

class SampleGO : virtual public IGameObject
{
public:
	static IGameObject::IdType TypeId();
};

