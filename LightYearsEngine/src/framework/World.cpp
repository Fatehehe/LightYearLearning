#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"
#include "framework/Application.h"

namespace ly{
    World::World(Application* owningApp)
        : mOwningApp{owningApp}, 
        mBegunPlay{false},
        mActors{},
        mPendingActors{}
    {

    }

    void World::BeginPlayInternal()
    {
        if(!mBegunPlay){
            mBegunPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime)
    {
        for(shared<Actor> actor : mPendingActors){
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }

        mPendingActors.clear();

        for(auto iter = mActors.begin(); iter != mActors.end(); ){
            iter->get()->Tick(deltaTime);
            ++iter;
        }
        

        Tick(deltaTime);
    }

    void World::Render(sf::RenderWindow& window){
        for(auto& actor : mActors){
            actor->Render(window);
        }
    }

    World::~World()
    {
    }

    sf::Vector2u World::GetWindowSize() const
    {
        return mOwningApp->GetWindowSize();
    }

    void World::CleanCycle(){
         for(auto iter = mActors.begin(); iter != mActors.end(); ){
            if(iter->get()->IsPendingDestroy()){
                iter = mActors.erase(iter);
            }else{
                ++iter;
            }
        }
    }

    void World::BeginPlay()
    {
        LOG("Begin play!"); 
    }

    void World::Tick(float deltaTime)
    {
        // LOG("World ticking with delta time: %f", 1.f / deltaTime);
    }
}