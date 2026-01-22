#include "Enemy/Vanguard.h"
// #include "weapon/BulletShooter.h"

namespace ly{
    Vanguard::Vanguard(World *world, const std::string &texturePath, const sf::Vector2f velocity)
    : EnemySpaceship{world, texturePath},
    mShooter {new BulletShooter{this, 1.f, {0.f, -50.f}}}
    {
        SetVelocity(velocity);
        SetActorRotation(180.f);
    }

    void Vanguard::Tick(float deltatime)
    {
        EnemySpaceship::Tick(deltatime);
        Shoot();
    }

    void Vanguard::Shoot()
    {
        mShooter->Shoot();
    }
}