#pragma once
#include"Engine.h"

class Game : public Engine {
public:
	Game();
	~Game();

	
protected:
	void Init() override;
	void Update() override;
	void Destroy() override;
};