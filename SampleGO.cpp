#include "Precompiled.h"

#include "SampleGO.h"
#include "Core/GameObjects/IGameObject.h"
#include "Core/GameObjects/IGameObjectData.h"
#include "Core/GameObjects/GameObjectFactory.h"
#include "Core/Logging/Logger.h"
#include "Engine/GameObjects/GameObject.h"
#include "HealthComponent.h"
#include <iostream>

class SampleGOData : public IGameObjectData
{
public:

public:
	SampleGOData()
	{}

	int load()
	{
		return 0;
	}

	~SampleGOData()
	{
	}
};

class SampleGOImp : public SampleGO, public GameObject<SampleGOImp, SampleGOData>
{

public:
	static IGameObject::IdType TypeId()
	{
		return "SampleGO";
	}

	//-------------------------------------------------------------------------
	//
	SampleGOImp(const GameObjectDataRef &aDataRef)
		: GameObject(aDataRef)
	{}

public:
	virtual void onSpawn(const physx::PxTransform &aPose) override
	{
		LOG_INFO("on spawn");

		HealthComponentRef health = ensureComponent<HealthComponent>();
		health->setHealth(1.0f);
	}

	//-------------------------------------------------------------------------
	//
	virtual void onUnspawn() override
	{
		removeAllComponents();
	}
};

//-----------------------------------------------------------------------------
//
IGameObject::IdType SampleGO::TypeId()
{
	return SampleGOImp::TypeId();
}

RegisterGameObjectType<SampleGOImp> gRegisterActor;

