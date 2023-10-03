using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TestGameAsset : MonoBehaviour
{
    void Start()
    {
        try
        {
            // Specify a valid path, assetType, and assetName
            string path = "D:\\Videos\\3d_bars-1366x768.jpg";
            int assetType = 0; // Texture
            string assetName = "3d_bars-1366x768";
            GameAssetWrapper gameAssetInstance = null;
            try
            {
                gameAssetInstance = new GameAssetWrapper(path, (int)assetType, assetName);
            }
            catch (Exception ex)
            {
                Debug.LogError("Failed to create GameAssetWrapper: " + ex.Message);
            }
            Debug.Log("GameAssetWrapper created successfully");
            gameAssetInstance.Serialize(path + ".json");
            Debug.Log("Serialize called with path: " + path);
            Debug.Log("GameAsset serialized successfully");
        }
        catch (Exception e)
        {
            Debug.LogError("Error creating GameAssetWrapper: " + e);
        }
    }
}
