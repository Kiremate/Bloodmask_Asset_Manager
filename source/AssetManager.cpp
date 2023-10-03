#include "../headers/AssetManager.h"

namespace blood_manager {
    std::shared_ptr<GameAsset> AssetManager::Load(const std::string& path) {
        // Check if the asset is already loaded
        auto it = _assets.find(path);
        if (it != _assets.end()) {
            // If the asset is already loaded, return the cached asset
            return it->second;
        }

        // If the asset is not loaded, create a new GameAsset, load it, and store it in the cache
        std::shared_ptr<GameAsset> asset = CreateGameAssetFromPath(path);
        asset->Load();
        _assets[path] = asset;

        return asset;
    }

    std::shared_ptr<GameAsset> AssetManager::Load(const std::string& path, AssetType assetType, const std::string& assetName)
    {
        // Check if the asset is already loaded
        auto it = _assets.find(path);
        if (it != _assets.end()) {
            // If the asset is already loaded, return the cached asset
            return it->second;
        }

        // If the asset is not loaded, create a new GameAsset, load it, and store it in the cache
        std::shared_ptr<GameAsset> asset = std::make_shared<GameAsset>(path, assetType, assetName);
        asset->Load();
        _assets[path] = asset;

        return asset;
    }

    std::shared_ptr<GameAsset> AssetManager::Get(const std::string& path) {
        // Check if the asset is already loaded
        auto it = _assets.find(path);
        if (it != _assets.end()) {
            // If the asset is already loaded, return the cached asset
            return it->second;
        }

        // If the asset is not loaded, load it and return it
        return Load(path);
    }

    std::shared_ptr<GameAsset> AssetManager::Get(const std::string& path, AssetType assetType, const std::string& assetName)
    {
        // Check if the asset is already loaded
        auto it = _assets.find(path);
        if (it != _assets.end()) {
            // If the asset is already loaded, return the cached asset
            return it->second;
        }

        // If the asset is not loaded, load it and return it
        return Load(path, assetType, assetName);
    }

    void AssetManager::Unload(const std::string& path) {
        // Check if the asset is loaded
        auto it = _assets.find(path);
        if (it != _assets.end()) {
            // If the asset is loaded, unload it and remove it from the cache
            it->second->Unload();
            _assets.erase(it);
        }
    }
    std::shared_ptr<GameAsset> AssetManager::CreateGameAssetFromPath(const std::string& path) {
        // Determine the asset type and name based on the file extension or content
        AssetType assetType;
        std::string assetName;
        // Here we use the file extension as an example
        std::string extension = path.substr(path.find_last_of(".") + 1);

        if (extension == "png" || extension == "jpg" || extension == "jpeg") {
            assetType = AssetType::Texture;
        }
        else if (extension == "obj" || extension == "fbx") {
            assetType = AssetType::Model;
        }
        else if (extension == "wav" || extension == "mp3" || extension == "ogg") {
            assetType = AssetType::Sound;
        }
        else {
            // Handle Unknown extensions...
        }

        assetName = path.substr(path.find_last_of("/") + 1); // Assuming the asset name is the filename

        return std::make_shared<GameAsset>(path, assetType, assetName);
    }

}
