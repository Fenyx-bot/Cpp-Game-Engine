#pragma once
#include "Actor.h"
#include <raylib.h>

class SpriteActor : public Actor
{
public:
    SpriteActor(const char* textureFilePath);
    ~SpriteActor();

    void Init() override;
    void Destroy() override;
    void Draw() override;

private:
    const char* TexturePath;
    Texture2D Texture;
};
