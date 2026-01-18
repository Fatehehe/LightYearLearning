#include "framework/Core.h"
#include "framework/Application.h"
#include "framework/World.h" 
#include "framework/AssetManager.h"

namespace ly
{

    Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string &title, sf::Uint32 style)
        : mWindow{sf::VideoMode(windowWidth, windowHeight), title, style},
        mTargetFrameRate{60.0f},
        mTickClock{},
        currentWorld{nullptr},
        mCleanCycleClock{},
        mCleanCycleInterval{2.f}
    {
    }

    void Application::Run()
    {
        mTickClock.restart();
        float accumulatedTime = 0.0f;
        float targetDeltaTime = 1.0f / mTargetFrameRate;
        while (mWindow.isOpen())
        {
            sf::Event windowEvent;
            while(mWindow.pollEvent(windowEvent)){
                if(windowEvent.type == sf::Event::Closed){
                    mWindow.close();
                }
            }

            float frameDeltaTime = mTickClock.getElapsedTime().asSeconds();
            accumulatedTime += frameDeltaTime;
            while(accumulatedTime > targetDeltaTime){
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
            // LOG("Ticking at framerate: %f seconds", 1.f / frameDeltaTime);
        }
    }

    sf::Vector2u Application::GetWindowSize() const
    {
        return mWindow.getSize();
    }

    void Application::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
        
        if(currentWorld){
            currentWorld->TickInternal(deltaTime);
        }

        if(mCleanCycleClock.getElapsedTime().asSeconds() >= mCleanCycleInterval){
            mCleanCycleClock.restart();
            AssetManager::Get().CleanCycle();
            if(currentWorld){
                currentWorld->CleanCycle();
            }
        }
    }

    void Application::RenderInternal()
    {
        mWindow.clear();

        Render();

        mWindow.display();
    }

    void Application::Render()
    {
        if(currentWorld){
            currentWorld->Render(mWindow);
        }
    }

    void Application::Tick(float deltaTime)
    {
    }
}