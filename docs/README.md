# 🎮 Blood Asset Manager: An Asset Manager for Video Games 🎮
##  .\Blood Asset Manager - Contains the Unity Project
##  .\projects\Bloodmask_Asset_Manager - Contains the DLL

## 🎯 Introduction
The Blood Asset Manager is a tool developed for Middleware class. This tool is designed to help game developers manage assets for their video games. It provides functionality for browsing files in a directory structure, creating .bloodasset files representing assets, and displaying information about these assets.

## 💻 Blood Asset Manager DLL Breakdown

### 📚 AssetManager Class
- Load: Accepts a path, and an optional asset type and asset name. Loads and caches it.
- Get: Retrieves already loaded or caches new assets.
- Unload: Unloads an asset and removes it from the cache.
###  AssetSerializer Class

- Serialize: Writes the serialized form of the GameAsset to a file.
- Deserialize: Reads the .bloodasset file and returns a GameAsset object.

###  File Class
- Various file operations and details.
###  Folder Class
- Methods for folder operations.
###  GameAsset Class
- Designed specifically for game assets. Methods for compressing, encrypting, and more.

## 🎮 Command-Line Parameters

> [!NOTE]
> Example: <application_executable> -path "D:\Videos"

🖊️ Note: Always include a - before the parameter name.

🎯 Retrieving Parameters in the Application
Use CommandLineArgs.GetArg("parameter_name").


> [!NOTE]
>🛠️ To Simulate Parameters in Unity Editor 
> Use the EditorCommandLineArgs class.
> 
### Functionality
- Browsing Files: Navigate through the filesystem.
- Creating Assets: Represented by .bloodasset JSON files.
- Displaying Asset Information: Metadata can be read and displayed.
### Next Steps
- Robust metadata management
- Additional features for asset manipulation
- Further integration with game development workflows
