Blood Asset Manager: An Asset Manager for Video Games

.\Blood Asset Manager - Contains the Unity Project
\projects\Bloodmask_Asset_Manager - Contains the DLL


Introduction
The Blood Asset Manager is a tool developed for Middleware. This tool is designed to help game developers manage assets for their video games. It provides functionality for browsing files in a directory structure, creating .bloodasset files representing assets, and displaying information about these assets.


Blood Asset Manager DLL Breakdown
AssetManager Class
The AssetManager class is the core of the DLL. It manages the loading, caching, and unloading of game assets.

This is achieved through the following key functions:

Load: Accepts a path, and an optional asset type and asset name. If the asset hasn't been loaded already, it loads and caches it in the _assets map. It returns a shared pointer to the loaded asset.
Get: Accepts a path, and an optional asset type and asset name. If the asset is already loaded, it returns the cached asset. If not, it loads and caches the asset before returning it.
Unload: Accepts a path, and if the asset is currently loaded, it unloads the asset and removes it from the cache.
AssetSerializer Class
The AssetSerializer class is responsible for serializing and deserializing GameAsset instances to and from .bloodasset files.

Its main functions are:

Serialize: Accepts a GameAsset object and a filepath. It writes the serialized form of the GameAsset to the specified filepath.
Deserialize: Accepts a filepath. It reads the .bloodasset file at the specified filepath and returns a GameAsset object.
File Class
The File class provides a simplified interface for common file operations and is a wrapper for the boost::filesystem library.

It offers the following key functions:

GetName, GetPath, GetSize, GetExtension, GetCreationTime, GetLastAccessTime, GetLastWriteTime: These functions return various details about the file.
Copy, Move, Write, Rename, Create, Delete: These functions perform various file operations.
API
The DLL also exposes a C-style API to allow interaction with Unity or other applications. The API provides creation and destruction functions for File and AssetManager instances, along with a set of functions for interacting with assets.


Folder Class
The Folder class is another wrapper for the boost::filesystem library, and it simplifies common operations related to folders.

Here are the main functions provided:

Copy, Move, Delete: These override methods from the File class for specific functionality on folders.
GetFiles: This returns a list of the files contained within the specified folder.
GetFolders: This returns a list of the subfolders contained within the specified folder.
Create: This method creates a new folder at the specified path.
Rename: This method renames the specified folder.
GameAsset Class
The GameAsset class is a subclass of File and is designed specifically to manage game assets. It incorporates AssetType which could be a texture, model, sound, or video.

Here are the key functions:

GetType, GetName: These methods return the asset's type and name.
Convert: This method converts the asset to a specified format.
Compress, Decompress: These methods compress and decompress the asset.
Encrypt, Decrypt: These methods encrypt and decrypt the asset.
GeneratePreview: This method generates a preview of the asset.
GetMetadata: This method returns the asset's metadata.
Merge, Split, Rename: These methods merge multiple assets, split an asset, or rename the asset.
Load, Unload: These methods load and unload the asset.
As with the previous classes, the Folder and GameAsset classes both provide important functionality for manipulating folders and game assets in a simplified, cross-platform manner. The DLL's users can use these classes to handle common tasks without needing to delve into the intricacies of the underlying filesystem library.


Command-Line Parameters
Blood Asset Manager also supports command-line parameters. This allows you to specify certain settings or behaviors when you start the application.

Usage
You can use command-line parameters with the Blood Asset Manager application by specifying them when you run the application's executable. Here's an example:

<application_executable> -path "D:\\Videos"
In the above command, replace <application_executable> with the actual name of the Blood Asset Manager executable file. This command will start the application and set the path to "D:\\Videos".

Note: When specifying command-line parameters, always include a - before the parameter name. If the parameter requires a value, provide it directly after the parameter name.

Retrieving Parameters in the Application
You can retrieve the value of a command-line parameter in the application using the CommandLineArgs.GetArg("parameter_name") function. For example, CommandLineArgs.GetArg("path") would return "D:\\Videos" if you started the application with the -path "D:\\Videos" parameter.

Simulating Parameters in Unity Editor
For easy testing in the Unity Editor, you can simulate command-line arguments with the EditorCommandLineArgs class. Here's an example of how it simulates the -path parameter:


#if UNITY_EDITOR
using UnityEditor;
using UnityEngine;

public class EditorCommandLineArgs
{
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    static void RunBeforeSceneLoads()
    {
        // In editor mode, we'll simulate the command-line arguments
        CommandLineArgs.SetArgs(new[] { "-path", "D:\\Videos" });
    }
}
#endif
This feature allows for greater flexibility and automation when using Blood Asset Manager, especially when integrating it with scripts or other applications.


Functionality
Browsing Files: Blood Asset Manager provides an interface for navigating through the filesystem.
Creating Assets: Assets can be created from any file and are represented by .bloodasset JSON files that store metadata about the asset.
Displaying Asset Information: The metadata stored in .bloodasset files can be read and displayed.
How it Works
Blood Asset Manager uses a combination of a Unity frontend and a backend DLL written in C++.

The Unity frontend provides the graphical user interface, file browsing functionality.
The backend DLL is responsible for the actual serialization and deserialization of the asset metadata. This DLL is called by the Unity scripts to create and read .bloodasset files.
Next Steps
Future developments for the Blood Asset Manager may include more robust metadata management, additional features for asset manipulation, and further integration with game development workflows.