#pragma once

#include "spaceship/Spaceship.h"

namespace ly{
    class EnemySpaceship : public Spaceship{
    public:
        EnemySpaceship(World* world, const std::string& texturePath, float collisionDamage = 200.f);
        virtual void Tick(float deltatime) override;
    private:
        float mCollisionDamage;
        virtual void OnActorBeginOverlap(Actor* otherActor) override;
    };
}