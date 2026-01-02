#pragma once
#include "LogicActor.h"

class Player : public LogicActor
{
public:
	Player();
	~Player();

	void OnInit() override;
	void OnUpdate(float dt) override;
	void OnDestroy() override;

private:

};