#include "SpriteActor.h"

SpriteActor::SpriteActor(const char* textureFilePath)
{
    TexturePath = textureFilePath;
}

SpriteActor::~SpriteActor() {
    UnloadTexture(Texture);
}

void SpriteActor::Init() {
    Texture = LoadTexture(TexturePath);
}

void SpriteActor::Draw() {
    DrawTextureEx(Texture, Position, Rotation, 1.0f, WHITE);
}

void SpriteActor::Destroy() {
    UnloadTexture(Texture);
}
