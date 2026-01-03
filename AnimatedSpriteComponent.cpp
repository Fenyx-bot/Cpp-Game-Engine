#include "AnimatedSpriteComponent.h"
#include "Actor.h"
#include "iostream"

#define MAX_FRAME_DELAY 20
#define MIN_FRAME_DELAY 1

AnimatedSpriteComponent::AnimatedSpriteComponent(const char* path, int animframes)
{
    animFrames = animframes;
    texturePath = path;
}

void AnimatedSpriteComponent::Init()
{
    std::cout << "init AnimSprite component" << std::endl;
    imTexture = LoadImageAnim(texturePath, &animFrames);
    texture = LoadTextureFromImage(imTexture);
}

void AnimatedSpriteComponent::Destroy()
{
    UnloadTexture(texture);
}

void AnimatedSpriteComponent::Draw()
{
    frameCounter++;

    if (frameCounter >= frameDelay) {
        currentAnimFrame++;
        if (currentAnimFrame >= animFrames) currentAnimFrame = 0;

        nextFrameDataOffset = texture.width * texture.height * 4 * currentAnimFrame;

        UpdateTexture(texture, ((unsigned char*)imTexture.data) + nextFrameDataOffset);

        frameCounter = 0;
    }

    DrawTexture(texture,
        (int)owner->Position.x,
        (int)owner->Position.y,
        WHITE);
}
