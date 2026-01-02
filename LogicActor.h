#pragma once
#include "Actor.h"
#include "Component.h"

class LogicActor : public Actor
{
public:
	virtual void OnUpdate(float dt) override = 0;

protected:
	void Draw() override {}
};
