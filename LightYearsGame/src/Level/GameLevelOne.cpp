#include "Level/GameLevelOne.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "player/PlayerSpaceship.h"
#include "framework/AssetManager.h"
#include "Enemy/Vanguard.h"
#include "gameplay/GameStage.h"
#include "framework/TimerManager.h"

namespace ly{
    GameLevelOne::GameLevelOne(Application* owningApp)
    : World{owningApp}
    {
        testPlayerSpaceship = SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(320.f, 240.f));
        testPlayerSpaceship.lock()->SetActorRotation(0.f);

        weak<Vanguard> testSpaceship = SpawnActor<Vanguard>();
        testSpaceship.lock()->SetActorLocation(sf::Vector2f(100.f, 50.f));
    }

    void GameLevelOne::BeginPlay()
    {
        timerHandle_Test = TimerManager::Get().SetTimer(GetWeakRef(), &GameLevelOne::TimerCallback_Test, 100.f, true);
        
    }

    void GameLevelOne::TimerCallback_Test()
    {
        LOG("callback called");
        TimerManager::Get().ClearTimer(timerHandle_Test);
    }

    void GameLevelOne::InitGameStages(){
        AddStage(shared<GameStage>{new GameStage{this}});
    }
}
