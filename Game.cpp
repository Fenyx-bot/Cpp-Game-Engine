#include "Game.h"
#include "Player.h"

Game::Game() {}

Game::~Game() {}

void Game::Init() {
	Engine::AddActor(std::make_unique<Player>());
}

void Game::Update() {

}

void Game::Destroy() {


}
