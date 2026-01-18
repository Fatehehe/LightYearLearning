#pragma once
#include "SFML/System.hpp"
#include "weapon/Shooter.h"

namespace ly{
    class BulletShooter: public Shooter{
    public:
        BulletShooter(Actor* owner, float cooldownTime = 5.f);
        virtual bool IsOnCooldown() const override;
    private:
        virtual void ShootImplt() override;
        sf::Clock mCooldownClock;
        float mCooldownTime;    
    };
}