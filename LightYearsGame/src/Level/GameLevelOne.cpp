#include "Level/GameLevelOne.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "player/PlayerSpaceship.h"
#include "framework/AssetManager.h"
#include "Enemy/Vanguard.h"
#include "gameplay/GameStage.h"
#include "framework/TimerManager.h"
#include "Enemy/VanguardStage.h"
#include "Enemy/TwinBladeStage.h"

namespace ly{
    GameLevelOne::GameLevelOne(Application* owningApp)
    : World{owningApp}
    {
        testPlayerSpaceship = SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(320.f, 240.f));
        testPlayerSpaceship.lock()->SetActorRotation(0.f);
    }

    void GameLevelOne::BeginPlay()
    {
        
    }

    void GameLevelOne::InitGameStages(){
        AddStage(shared<TwinBladeStage>{new TwinBladeStage{this}});
        AddStage(shared<VanguardStage>{new VanguardStage{this}});
    }
}
