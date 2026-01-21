#pragma once
#include "framework/Core.h"

namespace ly{
    class Explosion{
    public:
        Explosion(int particleAmt = 20, 
            float lifeTimeMin = 5.f, 
            float lifeTimeMax = 15.f,
            float sizeMin = 1.f,
            float sizeMax = 2.f,
            float speedMin = 10.f,
            float speedMax = 50.f,
            const sf::Color& ParticleColor = sf::Color{255,128,0,255},
            const List<std::string>& mParticleImagePaths = {
                "SpaceShooterRedux/PNG/Effects/star1.png",
                "SpaceShooterRedux/PNG/Effects/star2.png",
                "SpaceShooterRedux/PNG/Effects/star3.png",
            }
        );

        void SpawnExplosion(World* world, const sf::Vector2f& location);

    private:
        int mParticleAmt;
        float mLifeTimeMin;
        float mLifeTimeMax;
        float mSizeMin;
        float mSizeMax;
        float mSpeedMin;
        float mSpeedMax;
        sf::Color mParticleColor;

        List<std::string> mParticleImagePaths;
    };
}