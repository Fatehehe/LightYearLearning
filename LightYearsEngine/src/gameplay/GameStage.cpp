#include "gameplay/GameStage.h"
#include "framework/Core.h"
namespace ly
{
    GameStage::GameStage(World *world)
    : mWorld{world}
    {
    }

    void GameStage::StartStage()
    {
        LOG("Stage started");
    }

    void GameStage::TickStage(float deltaTime)
    {
        // LOG("Stage ticking");
    }

    void GameStage::FinishStage()
    {
        onStageFinished.Broadcast();
        mStageFinished = true; 
        StageFinished();
    }

    void GameStage::StageFinished()
    {
        LOG("Stage finished");
    }
}
