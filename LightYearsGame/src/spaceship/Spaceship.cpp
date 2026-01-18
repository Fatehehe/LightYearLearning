#include "framework/Actor.h"
#include "spaceship/Spaceship.h"

namespace ly{   
    Spaceship::Spaceship(World* world, const std::string& texturePath)
        : Actor{world, texturePath},
        mVelocity {}
    {

    }

    void Spaceship::Tick(float deltatime){
        Actor::Tick(deltatime);
        AddActorLocationOffset(GetVelocity() * deltatime);
    }

    void Spaceship::SetVelocity(const sf::Vector2f& newVelocity){
        mVelocity = newVelocity;
    }

    void Spaceship::Shoot(){

    }
}