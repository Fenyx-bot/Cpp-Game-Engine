// SpriteComponent.h
#pragma once
#include "DrawableComponent.h"
#include <raylib.h>

class SpriteComponent : public DrawableComponent
{
public:
    SpriteComponent(const char* path);

    void Init() override;
    void Destroy() override;

protected:
    void Draw() override;

private:
    const char* texturePath;
    Texture2D texture{};
};
