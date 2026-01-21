#include "framework/Actor.h"
#include "spaceship/Spaceship.h"
#include "framework/MathUtility.h"

namespace ly{   
    Spaceship::Spaceship(World* world, const std::string& texturePath)
        : Actor{world, texturePath},
        mVelocity {},
        mHealthComp {100.f, 100.f},
        mBlinkTime {0.f},
        mBlinkDuration {2.f},
        mBlinkColorOffset {255,0,0,255}
    {

    }

    void Spaceship::Tick(float deltatime){
        Actor::Tick(deltatime);
        AddActorLocationOffset(GetVelocity() * deltatime);
        UpdateBlink(deltatime);
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

    void Spaceship::Blink(){
        if(mBlinkTime == 0){
            mBlinkTime = mBlinkDuration;
        }
    }

    void Spaceship::UpdateBlink(float deltatime){
        if(mBlinkTime > 0){
            mBlinkTime -= deltatime;
            mBlinkTime = mBlinkTime > 0.f ? mBlinkTime : 0.f;

            GetSprite().setColor(LerpColor(sf::Color::White, mBlinkColorOffset, mBlinkTime));
        }
    }

    void Spaceship::OnHealthChanged(float amt, float health, float maxHealth){
        // LOG("Spaceship Health Changed by: %f, and is now %f/%f", amt, health, maxHealth);
    }

    void Spaceship::OnTakenDamage(float amt, float health, float maxHealth){
        Blink();
        // LOG("Spaceship Taken Damage by: %f, and is now %f/%f", amt, health, maxHealth);
    }

    void Spaceship::Blow(){
        Destroy();
        // LOG("Spaceship is destroyed");
    }
}