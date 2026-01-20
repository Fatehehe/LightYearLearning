#include "gameplay/HealthComponent.h"
#include "framework/Core.h"

namespace ly
{
    HealthComponent::HealthComponent(float health, float maxHealth)
        : mHealth{health}, 
        mMaxHealth{maxHealth}
    {

    }

    void HealthComponent::ChangeHealth(float amt)
    {
        if(amt == 0.f) return;
        if(mHealth == 0.f) return;

        mHealth += amt;
        if(mHealth < 0.f){
            mHealth = 0.f;
        }

        if(mHealth > mMaxHealth){
            mHealth = mMaxHealth;
        }

        if(amt < 0.f){
            TakenDamage(-amt);
            if(mHealth <= 0.f){
                HealthEmpty();
            }
        }else{
            HealthRegen(amt);
        }
    }

    void HealthComponent::TakenDamage(float amt)
    {
        LOG("Taken Damage: %f, now health is %f/%f", amt, mHealth, mMaxHealth);
    }

    void HealthComponent::HealthEmpty()
    {
        LOG("Dead");
    }

    void HealthComponent::HealthRegen(float amt)
    {
        LOG("Taken Regen: %f, now health is %f/%f", amt, mHealth, mMaxHealth);
    }
} // namespace ly

