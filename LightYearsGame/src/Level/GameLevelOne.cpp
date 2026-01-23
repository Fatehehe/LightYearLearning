#include "Level/GameLevelOne.h"
#include "gameplay/WaitStage.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "player/PlayerSpaceship.h"
#include "framework/AssetManager.h"
#include "Enemy/Vanguard.h"
#include "Enemy/UFO.h"
#include "gameplay/GameStage.h"
#include "framework/TimerManager.h"
#include "Enemy/VanguardStage.h"
#include "Enemy/TwinBladeStage.h"
#include "Enemy/HexagonStage.h"

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
        weak<UFO> newUFO_test = SpawnActor<UFO>(sf::Vector2f{0.f,0.f});
        newUFO_test.lock()->SetActorLocation({GetWindowSize().x/2.f, GetWindowSize().y/2.f});
    }

    void GameLevelOne::InitGameStages(){
        AddStage(shared<WaitStage>{new WaitStage{this, 20.f}});
        AddStage(shared<HexagonStage>{new HexagonStage{this}});

        AddStage(shared<WaitStage>{new WaitStage{this, 20.f}});
        AddStage(shared<VanguardStage>{new VanguardStage{this}});

        AddStage(shared<WaitStage>{new WaitStage{this, 20.f}});
        AddStage(shared<TwinBladeStage>{new TwinBladeStage{this}});
    }
}
