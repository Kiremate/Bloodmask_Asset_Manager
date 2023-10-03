#pragma once

#include "File.h"
#include "Api.h"
#include "AssetManager.h"
#include "AssetSerializer.h"
extern "C" {
    BLOOD_MANAGER_API blood_manager::File* File_Create(const char* path);
    BLOOD_MANAGER_API void File_Destroy(blood_manager::File* file);
    BLOOD_MANAGER_API blood_manager::File* File_CreateAndWrite(const char* path);
    BLOOD_MANAGER_API void File_Write(blood_manager::File* file, const char* content);
    BLOOD_MANAGER_API blood_manager::AssetManager* AssetManager_Create();
    BLOOD_MANAGER_API void AssetManager_Destroy(blood_manager::AssetManager* assetManager);
    BLOOD_MANAGER_API blood_manager::GameAsset* AssetManager_Load(blood_manager::AssetManager* assetManager, const char* path);
    BLOOD_MANAGER_API blood_manager::GameAsset* AssetManager_Get(blood_manager::AssetManager* assetManager, const char* path);
    BLOOD_MANAGER_API int AssetManager_Load_WithType(blood_manager::AssetManager* assetManager, const char* path, blood_manager::AssetType assetType, const char* assetName, blood_manager::GameAsset** outAsset);
    BLOOD_MANAGER_API blood_manager::GameAsset* AssetManager_Get_WithType(blood_manager::AssetManager* assetManager, const char* path, blood_manager::AssetType assetType, const char* assetName);
    BLOOD_MANAGER_API int AssetSerializer_Serialize(blood_manager::GameAsset* asset, const char* filepath);
    BLOOD_MANAGER_API blood_manager::GameAsset* AssetSerializer_Deserialize(const char* filepath);
}