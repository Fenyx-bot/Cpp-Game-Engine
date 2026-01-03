#pragma once
#include "DrawableComponent.h"
#include <raylib.h>

class AnimatedSpriteComponent : public DrawableComponent
{
public:
    AnimatedSpriteComponent(const char* path, int animFrames);

    void Init() override;
    void Destroy() override;

protected:
    void Draw() override;

private:
    const char* texturePath;
    Image imTexture;
    Texture2D texture{};

    int animFrames = 0;

    unsigned int nextFrameDataOffset = 0;

    int currentAnimFrame = 0;
    int frameDelay = 8;
    int frameCounter = 0;
};
