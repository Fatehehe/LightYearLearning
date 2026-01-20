#include "gameFramework/gameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
// #include "spaceship/Spaceship.h"
#include "player/PlayerSpaceship.h"
#include "framework/AssetManager.h"
#include "config.h"


ly::Application* GetApplication(){
    return new ly::GameApplication{};
}

namespace ly
{
    GameApplication::GameApplication()
    : Application{640, 480, "Light Years", sf::Style::Titlebar | sf::Style::Close}
    {
        AssetManager::Get().SetAssetRootDirectory(GetResourceDir());
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
        testPlayerSpaceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        // testPlayerSpaceship.lock()->SetTexture("/SpaceShooterRedux/PNG/playerShip1_blue.png");
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(320.f, 240.f));
        testPlayerSpaceship.lock()->SetActorRotation(0.f);
        // testPlayerSpaceship.lock()->SetVelocity(sf::Vector2f{0.f, -2.f});
        // counter = 0; 

        weak<Spaceship> testSpaceship = newWorld.lock()->SpawnActor<Spaceship>();
        testSpaceship.lock()->SetTexture("/SpaceShooterRedux/PNG/playerShip1_blue.png");
        testSpaceship.lock()->SetActorLocation(sf::Vector2f(100.f, 50.f));

        counter = 0;
    }   

    void GameApplication::Tick(float deltatime)
    {
        counter += deltatime;
        // LOG("Counter: %f", counter); 
        if(counter > 1000.f){
            if(!testPlayerSpaceship.expired()){
                testPlayerSpaceship.lock()->Destroy();
            }
        }
        // counter += deltatime;
        // if(counter > 100.f){
        //     if(!testPlayerSpaceship.expired()){
        //         testPlayerSpaceship.lock()->Destroy();
        //     }
        // }
    }
}
