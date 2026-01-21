#include "Enemy/EnemySpaceship.h"

namespace ly{
    EnemySpaceship::EnemySpaceship(World *world, const std::string &texturePath, float collisionDamage)
        :Spaceship{world, texturePath},
        mCollisionDamage{collisionDamage}
    {
        SetTeamID(2); // Enemy team ID
    }

    void EnemySpaceship::Tick(float deltatime)
    {
        Spaceship::Tick(deltatime);
        if(IsActorOutOfWindowBound(GetActorGlobalBounds().width)){
            Destroy();
        }
    }

    void EnemySpaceship::OnActorBeginOverlap(Actor *otherActor)
    {
        Spaceship::OnActorBeginOverlap(otherActor);
        if(IsOtherHostile(otherActor)){
            otherActor->ApplyDamage(mCollisionDamage);
        }
    }
}

