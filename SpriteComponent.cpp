#include "SpriteComponent.h"
#include "Actor.h"
#include "iostream"

SpriteComponent::SpriteComponent(const char* path)
{
    texturePath = path;
}

void SpriteComponent::Init()
{
    std::cout << "init sprite component" << std::endl;
    texture = LoadTexture(texturePath);
}

void SpriteComponent::Destroy()
{
    UnloadTexture(texture);
}

void SpriteComponent::Draw()
{
    DrawTexture(texture,
        (int)owner->Position.x,
        (int)owner->Position.y,
        WHITE);
}
