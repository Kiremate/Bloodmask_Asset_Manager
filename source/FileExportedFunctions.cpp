#include "../headers/FileExportedFunctions.h"
#include <iostream>

blood_manager::File* File_Create(const char* path) {
    return new blood_manager::File(path);
}

void File_Destroy(blood_manager::File* file) {
    delete file;
}

blood_manager::File* File_CreateAndWrite(const char* path) {
    blood_manager::File* file = new blood_manager::File(path);
    file->Create();
    return file;
}
void File_Write(blood_manager::File* file, const char* content) {
    file->Write(content);
}

blood_manager::AssetManager* AssetManager_Create() {
    return new blood_manager::AssetManager();
}

void AssetManager_Destroy(blood_manager::AssetManager* assetManager) {
    delete assetManager;
}

blood_manager::GameAsset* AssetManager_Load(blood_manager::AssetManager* assetManager, const char* path) {
    return assetManager->Load(path).get();
}
 
blood_manager::GameAsset* AssetManager_Get(blood_manager::AssetManager* assetManager, const char* path) {
    return assetManager->Get(path).get();
}

int AssetManager_Load_WithType(blood_manager::AssetManager* assetManager, const char* path, blood_manager::AssetType assetType, const char* assetName, blood_manager::GameAsset** outAsset) {
    if (assetManager == nullptr) {
        return -1;
    }
    if (path == nullptr) {
        return -2;
    }
    if (assetName == nullptr) {
        return -3;
    }

    try {
        std::shared_ptr<blood_manager::GameAsset> asset = assetManager->Load(std::string(path), assetType, std::string(assetName));
        *outAsset = asset.get();
        return 0;
    }
    catch (const std::exception&) {
        return -4;
    }
}

blood_manager::GameAsset* AssetManager_Get_WithType(blood_manager::AssetManager* assetManager, const char* path, blood_manager::AssetType assetType, const char* assetName) {
    return assetManager->Get(path, assetType, std::string(assetName)).get();
}

BLOOD_MANAGER_API int AssetSerializer_Serialize(blood_manager::GameAsset* asset, const char* filepath)
{
    if (asset == nullptr || filepath == nullptr) {
        return 1;
    }

    try {
        blood_manager::AssetSerializer::Serialize(*asset, filepath);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in Serialize: " << e.what() << '\n';
        return 2;
    }

    return 0;  // success
}


BLOOD_MANAGER_API blood_manager::GameAsset* AssetSerializer_Deserialize(const char* filepath)
{
    return new blood_manager::GameAsset(blood_manager::AssetSerializer::Deserialize(filepath));
}

