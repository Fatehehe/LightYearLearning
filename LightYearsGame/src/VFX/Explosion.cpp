#include "framework/MathUtility.h"
#include "framework/World.h"
#include "VFX/Explosion.h"
#include "VFX/Particle.h"

namespace ly{

    Explosion::Explosion(int particleAmt, float lifeTimeMin, float lifeTimeMax, float sizeMin, float sizeMax, float speedMin, float speedMax, const sf::Color& ParticleColor,const List<std::string> &mParticleImagePaths)
        : mParticleAmt{particleAmt},
        mLifeTimeMin{lifeTimeMin},
        mLifeTimeMax{lifeTimeMax},
        mSizeMin{sizeMin},
        mSizeMax{sizeMax},
        mSpeedMin{speedMin},
        mSpeedMax{speedMax},
        mParticleColor{ParticleColor},
        mParticleImagePaths{mParticleImagePaths}
    {

    }

    void Explosion::SpawnExplosion(World* world, const sf::Vector2f& location)
	{
		if (!world)
		{
			return;
		}

		for(int i = 0; i < mParticleAmt; ++i)
		{
			std::string particleImagePath = mParticleImagePaths[(int)RandomRange(0, mParticleImagePaths.size())];
			weak<Particle> newParticle = world->SpawnActor<Particle>(particleImagePath);

			newParticle.lock()->RandomLifeTime(mLifeTimeMin, mLifeTimeMax);
			newParticle.lock()->SetActorLocation(location);
			newParticle.lock()->RandomSize(mSizeMin, mSizeMax);
			newParticle.lock()->RandomVelocity(mSpeedMin, mSpeedMax);
			newParticle.lock()->GetSprite().setColor(mParticleColor);
		}
	}
}

