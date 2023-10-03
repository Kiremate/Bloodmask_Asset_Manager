using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static AssetManager;

public class GameAssetWrapper
{
    private IntPtr _nativeHandle;

    public GameAssetWrapper(string path, int assetType, string assetName)
    {
        // Create an AssetManager instance
        IntPtr assetManagerPtr = FileWrapper.AssetManager_Create();
        if (assetManagerPtr == IntPtr.Zero)
        {
            throw new Exception("Failed to create AssetManager");
        }

        // Create a GameAsset instance
        int errorCode = FileWrapper.AssetManager_Load_WithType(assetManagerPtr, path, assetType, assetName, out _nativeHandle);
        if (errorCode != 0)
        {
            throw new Exception($"Failed to load game asset with error code: {errorCode}");
        }
    }

    public GameAssetWrapper(IntPtr nativeHandle)
    {
        _nativeHandle = nativeHandle;
    }

    ~GameAssetWrapper()
    {
        FileWrapper.GameAsset_Destroy(_nativeHandle);
    }

    public void Serialize(string filepath)
    {
        if (_nativeHandle == IntPtr.Zero)
        {
            Debug.LogError("GameAsset is null");
            return;
        }

        int status = FileWrapper.AssetSerializer_Serialize(_nativeHandle, filepath);
        if (status != 0)
        {
            Debug.LogError("Serialize failed with error code " + status);
        }
    }

    public static GameAssetWrapper Deserialize(string filepath)
    {
        IntPtr nativeHandle = FileWrapper.AssetSerializer_Deserialize(filepath);
        return new GameAssetWrapper(nativeHandle);
    }

    public string GetMetadata()
    {
        return FileWrapper.GameAsset_GetMetadata(_nativeHandle);
    }
}
