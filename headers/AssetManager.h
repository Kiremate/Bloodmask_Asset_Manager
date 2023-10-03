#pragma once
#include "GameAsset.h"
#include <map>
#include <memory>
#include <string>
/// <summary>
/// The AssetManager class is responsible for managing the loading, caching, and unloading of game assets. 
/// Its role in the architecture is to provide a central point for accessing and managing game assets, 
/// ensuring that assets are loaded only once and reused throughout the game to save memory and improve performance.
/// </summary>
namespace blood_manager {
    class AssetManager {
    public:
        // Load and cache an asset
        /*Load: Given an asset's path, this method loads the asset, caches it in the _assets map, 
        and returns a std::shared_ptr to the loaded asset. 
        If the asset is already loaded, it returns the cached asset.*/
        std::shared_ptr<GameAsset> Load(const std::string& path);
        std::shared_ptr<GameAsset> Load(const std::string& path, AssetType assetType, const std::string& assetName);

        // Retrieve an asset by its identifier (path)
        /*Get: Given an asset's path, this method returns 
        a std::shared_ptr to the loaded asset if it is already in the cache.
        If the asset is not loaded, it loads the asset, caches it, and then returns it.*/
        std::shared_ptr<GameAsset> Get(const std::string& path);
        std::shared_ptr<GameAsset> Get(const std::string& path, AssetType assetType, const std::string& assetName);

        // Unload an asset by its identifier (path)
        /*Unload: Given an asset's path, this method unloads the asset and removes it from the cache if it is currently loaded.*/
        void Unload(const std::string& path);

    private:
        // A map to store the loaded assets, indexed by their unique identifier (path)
        std::shared_ptr<GameAsset> CreateGameAssetFromPath(const std::string& path);
        std::map<std::string, std::shared_ptr<GameAsset>> _assets;
    };
}
