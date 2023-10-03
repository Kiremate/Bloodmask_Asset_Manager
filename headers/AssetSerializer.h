#pragma once
#include "GameAsset.h"
#include <string>

namespace blood_manager {

    class AssetSerializer {
    public:
        static void Serialize(const GameAsset& asset, const std::string& filepath);
        static GameAsset Deserialize(const std::string& filepath);
    };

} // namespace blood_manager
