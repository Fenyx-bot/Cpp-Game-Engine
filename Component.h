#pragma once

class Actor;

class Component
{
public:
    virtual ~Component() = default;

    virtual void Init() {}
    virtual void Update(float dt) {}
    virtual void Destroy() {}

    void SetOwner(Actor* actor) { owner = actor; }

protected:
    Actor* owner = nullptr;
};