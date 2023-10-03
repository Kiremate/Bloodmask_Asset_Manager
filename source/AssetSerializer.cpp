#include "../headers/AssetSerializer.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace blood_manager {

    void AssetSerializer::Serialize(const GameAsset& asset, const std::string& filepath) {
        try {
            nlohmann::json j;

            j["type"] = static_cast<int>(asset.GetType());
            j["name"] = asset.GetName();

            std::ofstream of(filepath);
            if (!of.is_open()) {
                throw std::runtime_error("Unable to open file for writing: " + filepath);
            }
            of << j.dump();
            of.close();
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught in Serialize: " << e.what() << '\n';
            throw;  // rethrow the exception for the caller to handle
        }
    }

    GameAsset AssetSerializer::Deserialize(const std::string& filepath) {
        std::ifstream ifile(filepath);
        if (!ifile.is_open()) {
            throw std::runtime_error("Unable to open file for reading: " + filepath);
        }

        nlohmann::json j;
        ifile >> j;

        if (!j.contains("type") || !j["type"].is_number_integer() || !j.contains("name") || !j["name"].is_string()) {
            throw std::runtime_error("Invalid JSON structure in file: " + filepath);
        }

        AssetType type = static_cast<AssetType>(j["type"].get<int>());
        std::string name = j["name"].get<std::string>();

        return GameAsset(filepath, type, name);
    }

} // namespace blood_manager
