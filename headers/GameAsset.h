#pragma once
#include "File.h"
#include <string>

namespace blood_manager {
    enum class AssetType {
        Texture,
        Model,
        Sound,
        Video,
    };

    class GameAsset : public File {
    public:
        GameAsset(const std::string& path, AssetType type, const std::string& name)
            : File(path), _type(type), _name(name) {}
        GameAsset() : File(""), _type(AssetType::Texture), _name("") {}
        AssetType GetType() const { return _type; }
        std::string GetName() const { return _name; }

        void Convert(const std::string& newFormat);
        void Compress();
        void Decompress();
        void Encrypt();
        void Decrypt();
        void GeneratePreview();
        std::string GetMetadata();
        void Merge(const std::string& path);
        void Split();
        void Rename(const std::string& newName);

        void Load();
        void Unload();

    private:
        AssetType _type;
        std::string _name;
        // Add other metadata as needed
    };
}
