#pragma once

#include "Enemy/EnemySpaceship.h"
#include "weapon/BulletShooter.h"

namespace ly{
    class BulletShooter;
    class TwinBlade: public EnemySpaceship{
    public:
        TwinBlade(World* world, const std::string& texturePath = "SpaceShooterRedux/PNG/Enemies/enemyBlack1.png", const sf::Vector2f velocity = {0.f, 0.8f});
        virtual void Tick(float deltaTime) override;
        virtual void Shoot() override;
    private:
        unique<BulletShooter> mShooterLeft;
        unique<BulletShooter> mShooterRight;
    
    };
}