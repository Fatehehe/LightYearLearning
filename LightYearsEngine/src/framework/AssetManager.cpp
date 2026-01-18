#include "framework/AssetManager.h"

namespace ly{
    unique<AssetManager> AssetManager::assetManager{nullptr};

    AssetManager &AssetManager::Get()
    {
        if(!assetManager){
            assetManager = unique<AssetManager>{new AssetManager}; 
        }
        return *assetManager;
    }

    shared<sf::Texture> AssetManager::LoadTexture(const std::string &path)
    {
        auto found = mLoadedTexturMap.find(path);
        if(found != mLoadedTexturMap.end()){
            return found->second;
        }

        shared<sf::Texture> newTexture{new sf::Texture};
        if(newTexture->loadFromFile(mRootDirectory + path)){
            mLoadedTexturMap.insert({path, newTexture});
            return newTexture;
        }

        return shared<sf::Texture> {nullptr};
    }

     void AssetManager::CleanCycle()
    {
        for(auto iter = mLoadedTexturMap.begin(); iter != mLoadedTexturMap.end();){
            if(iter->second.unique()){
                LOG("Cleaning Texture: %s", iter->first.c_str());
                iter = mLoadedTexturMap.erase(iter);
            }else{
                ++iter;
            }
        }
    }

    void AssetManager::SetAssetRootDirectory(const std::string &directory)
    {
        mRootDirectory = directory;
    }

    AssetManager::AssetManager(): mRootDirectory{""}
    {
    }
}