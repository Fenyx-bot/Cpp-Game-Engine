#include "Player.h"
#include "Engine.h"
#include "SpriteComponent.h"
#include "AnimatedSpriteComponent.h"

Player::Player() {
	AddComponent<AnimatedSpriteComponent>("Horse1.gif", 0);
	std::cout << "Adding player sprite!" << std::endl;
	Position = { 100, 100 };
	Size = { 32, 32 };
}

Player::~Player() {
}

void Player::OnInit() {
	Position = { Engine::GetWindowSize().x / 2, Engine::GetWindowSize().y / 2};
}

void Player::OnUpdate(float dt) {
	if (IsKeyDown(KEY_D)) {
		Position.x += 1.0f;
	}
	if (IsKeyDown(KEY_A)) {
		Position.x -= 1.0f;
	}
	if (IsKeyDown(KEY_W)) {
		Position.y -= 1.0f;
	}
	if (IsKeyDown(KEY_S)) {
		Position.y += 1.0f;
	}
	//std::cout << "Player ready! (" << Position.x << "|" << Position.y << ")" << std::endl;
}

void Player::OnDestroy() {


}

