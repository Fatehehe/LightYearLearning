#include "player/PlayerSpaceship.h"
#include "SFML/System.hpp"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"

namespace ly{
    
    PlayerSpaceship::PlayerSpaceship(World *owningWorld, const std::string &path)
        : Spaceship{owningWorld, path},
        mMoveInput{},
        mSpeed{2.f},
        mShooter{new BulletShooter{this, .1f}}
    {
        SetTeamID(1);
    }

    void PlayerSpaceship::Tick(float deltatime)
    {
        Spaceship::Tick(deltatime);
        HandleInput();
        ConsumeInput(deltatime);
    }

    void PlayerSpaceship::Shoot()
    {
        if(mShooter){
            mShooter->Shoot();
        }
    }

    void PlayerSpaceship::HandleInput()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            mMoveInput.y = -1.f;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            mMoveInput.y = 1.f;
        } 
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            mMoveInput.x = -1.f;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            mMoveInput.x = 1.f;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Shoot();
        }

        ClampInputOnEdge();

        NormalizeInput();
    }

    void PlayerSpaceship::NormalizeInput()
    {
        Normalized(mMoveInput);
        // LOG("MOVE input is now: %f, %f", mMoveInput.x, mMoveInput.y);
    }

    void PlayerSpaceship::ClampInputOnEdge()
    {
        sf::Vector2f actorLocation = GetActorLocation();
        if(actorLocation.x < 0 && mMoveInput.x == -1){
            mMoveInput.x = 0.f;
        }

        if(actorLocation.x > GetWindowSize().x && mMoveInput.x == 1.f){
            mMoveInput.x = 0.f;
        }

         if(actorLocation.y < 0 && mMoveInput.y == -1){
            mMoveInput.y = 0.f;
        }

        if(actorLocation.y > GetWindowSize().y && mMoveInput.y == 1.f){
            mMoveInput.y = 0.f;
        }
    }

    void PlayerSpaceship::ConsumeInput(float deltatime)
    {
        SetVelocity(mMoveInput * mSpeed);
        mMoveInput.x = mMoveInput.y = 0.f;
    }
}