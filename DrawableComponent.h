// DrawableComponent.h
#pragma once
#include "Component.h"

class DrawableComponent : public Component
{
protected:
    virtual void Draw() = 0;

    friend class Engine; // only engine can draw
};
