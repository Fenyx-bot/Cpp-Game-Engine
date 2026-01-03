#pragma once
#include <raylib.h>
#include<vector>
#include<memory>
#include<iostream>
#include"Component.h"

class Component;

class Actor
{
public:
    virtual ~Actor() = default;

    Vector2 Position{};
    Vector2 Size{};
    float Rotation = 0.0f;

    void Init()
    {
        std::cout << "init actors" << std::endl;
        InitComponents();
        OnInit();
    }

    void Update(float dt)
    {
        UpdateComponents(dt);
        OnUpdate(dt);
    }

    void Destroy()
    {
        OnDestroy();
        DestroyComponents();
    };

     template<typename T, typename... Args>
     T* AddComponent(Args&&... args) {
         static_assert(std::is_base_of<Component, T>::value);

         auto comp = std::make_unique<T>(std::forward<Args>(args)...);
         T* ptr = comp.get();
         ptr->SetOwner(this);
         components.push_back(std::move(comp));
         return ptr;
     }

     const std::vector<std::unique_ptr<Component>>& GetComponents() const {
         return components;
     };

protected:
    virtual void OnInit() {};
    virtual void OnUpdate(float dt) {};
    virtual void OnDestroy() {};
    virtual void Draw() = 0;
    friend class Engine;
    std::vector<std::unique_ptr<Component>> components;

private:
    void InitComponents()
    {
        std::cout << "Init components" << std::endl;
        for (auto& c : components)
            c->Init();
    }

    void UpdateComponents(float dt)
    {
        for (auto& c : components)
            c->Update(dt);
    }

    void DestroyComponents()
    {
        for (auto& comp : components) {
            comp->Destroy();  // Calls your Component's Destroy() method
        }
    }
};
