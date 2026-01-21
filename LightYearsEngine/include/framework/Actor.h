#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/Object.h"

class b2Body;

namespace ly{
    class World;
    class Actor: public Object
    {
    public:
        Actor(World* owningWorld, const std::string& texturePath = "");
        virtual ~Actor();
        void BeginPlayInternal();
        void TickInternal(float deltatime);
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
        void SetTexture(const std::string& texturePath);
        void Render(sf::RenderWindow& window);

        void SetActorLocation(const sf::Vector2f& newLoc);
        void SetActorRotation(const float newRot);
        void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
        void AddActorRotationOffset(const float offsetAmt);
        
        sf::Vector2f GetActorLocation() const;
        float GetActorRotation() const;
        sf::Vector2f GetActorForwardDirection() const;
        sf::Vector2f GetActorRightDirection() const;
        sf::FloatRect GetActorGlobalBounds() const;

        sf::Vector2u GetWindowSize() const;

        const World* GetWorld() const {return mOwningWorld;}
        World* GetWorld() {return mOwningWorld;}

        bool IsActorOutOfWindowBound() const;

        void SetEnablePhysics(bool enable);

        virtual void OnActorBeginOverlap(Actor* otherActor);
        virtual void OnActorEndOverlap(Actor* otherActor);
        virtual void Destroy() override;
        static uint8 GetNeutralTeamID() { return neutralTeamID; }

        void SetTeamID(uint8 newTeamID) { mTeamID = newTeamID; }

        uint8 GetTeamID() const { return mTeamID; }
        bool IsOtherHostile(Actor* other) const;

        virtual void ApplyDamage(float amt);

        sf::Sprite& GetSprite() { return mSprite; }
		const sf::Sprite& GetSprite() const { return mSprite; }

    private:
        void InitializePhysics();
        void UninitializePhysics();
        void CenterPivot();

        void UpdatePhysicsBodyTransform();

        World* mOwningWorld;
        bool mBegunPlay;

        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;

        b2Body* mPhysicBody;
        bool mPhysicsEnabled;

        uint8 mTeamID;
        const static uint8 neutralTeamID = 255;
    };
}