#include "framework/Actor.h"
#include "spaceship/Spaceship.h"

namespace ly{   
    Spaceship::Spaceship(World* world, const std::string& texturePath)
        : Actor{world, texturePath},
        mVelocity {},
        mHealthComp {100.f, 100.f}
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

    void Spaceship::BeginPlay(){
        Actor::BeginPlay();
        SetEnablePhysics(true);
        mHealthComp.onHealthChanged.BindAction(GetWeakRef(), &Spaceship::OnHealthChanged);
        mHealthComp.onTakenDamage.BindAction(GetWeakRef(), &Spaceship::OnTakenDamage);
        mHealthComp.onHealthEmpty.BindAction(GetWeakRef(), &Spaceship::Blow);
    }

    void Spaceship::ApplyDamage(float amt){
        mHealthComp.ChangeHealth(-amt);
    }

    void Spaceship::OnHealthChanged(float amt, float health, float maxHealth){
        // LOG("Spaceship Health Changed by: %f, and is now %f/%f", amt, health, maxHealth);
    }

    void Spaceship::OnTakenDamage(float amt, float health, float maxHealth){
        // LOG("Spaceship Taken Damage by: %f, and is now %f/%f", amt, health, maxHealth);
    }

    void Spaceship::Blow(){
        Destroy();
        // LOG("Spaceship is destroyed");
    }
}