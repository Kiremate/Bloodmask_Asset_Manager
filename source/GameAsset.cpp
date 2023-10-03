#include "../headers/GameAsset.h"
#include <iostream>

namespace blood_manager {

    void GameAsset::Convert(const std::string& newFormat) {
        // TODO Implement conversion logic based on the asset type and desired format
        // Need to use external libraries or tools to handle specific formats
    }

    void GameAsset::Compress() {
        // TODO Implement compression logic
        // Needlibraries like zlib or similar to compress asset data
    }

    void GameAsset::Decompress() {
        // TODO Implement decompression logic
        // Need libraries like zlib or similar to decompress asset data
    }

    void GameAsset::Encrypt() {
        // TODO Implement encryption logic
        // Need libraries like OpenSSL or similar to encrypt asset data
    }

    void GameAsset::Decrypt() {
        // TODO Implement decryption logic
        // Need libraries like OpenSSL or similar to decrypt asset data
    }

    void GameAsset::GeneratePreview() {
        // TODO Implement preview generation logic based on the asset type
        // Depending on the Asset type
    }

    std::string GameAsset::GetMetadata() {
        // TODO Implement metadata retrieval logic
        // This could involve reading metadata from the file or generating it based on the asset type
        return "";
    }

    void GameAsset::Merge(const std::string& path) {
        // TODO Implement merge logic based on the asset type
    }

    void GameAsset::Split() {
        // TODO Implement split logic based on the asset type
        // This involve breaking a texture atlas into individual textures
    }

    void GameAsset::Rename(const std::string& newName) {
        // Call the parent class Rename method to rename the file
        File::Rename(newName);
        // Update the asset name
        _name = newName;
    }

    void GameAsset::Load() {
        // TODO Implement loading logic based on the asset type
    }

    void GameAsset::Unload() {
        // TODO Implement unloading logic based on the asset type
    }
}