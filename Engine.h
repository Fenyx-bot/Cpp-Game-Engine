#pragma once
#include<iostream>
#include<raylib.h>
#include<vector>
#include<memory>
#include"Actor.h"
#include"DrawableComponent.h"

class Engine
{
public:
	static Texture2D Background;

	static Vector2 GetWindowSize();
	void Run();
	void AddActor(std::unique_ptr<Actor> actor);

	Engine();
	virtual ~Engine();

protected:
	static Vector2 screenSize;

private:
	std::vector<std::unique_ptr<Actor>> actors;

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
};