using System;
using System.IO;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using TMPro;

public class AssetManager : MonoBehaviour
{
    public GameObject ButtonTemplate;
    public GameObject buttonParent;
    public string StartingPath = ".";

    private string currentPath;
    public enum AssetType
    {
        Texture,
        Model,
        Sound,
        Video,
    }

    void Start()
    {
        var cmdPath = CommandLineArgs.GetArg("path");
        if (!string.IsNullOrEmpty(cmdPath))
        {
            currentPath = Path.GetFullPath(cmdPath);
        }
        else
        {
            currentPath = Path.GetFullPath(StartingPath);
        }
        UpdateFileBrowser(currentPath);
    }

    public void ButtonClicked(string path)
    {
        if (Directory.Exists(path))
        {
            currentPath = path;
            UpdateFileBrowser(currentPath);
        }
        else if (File.Exists(path))
        {
            string bloodAssetPath = path + ".bloodasset";
            if (File.Exists(bloodAssetPath))
            {
                // Read the contents of the .bloodasset file directly
                string bloodAssetContents = File.ReadAllText(bloodAssetPath);
                Debug.Log(bloodAssetContents);

                // The following lines are commented out for now
                //GameAssetWrapper gameAssetInstance = GameAssetWrapper.Deserialize(bloodAssetPath);
                //string metadata = gameAssetInstance.GetMetadata();
                //Debug.Log(metadata);
            }
            else
            {
                Debug.LogError("No serialized GameAsset found for file " + path);
            }
        }
    }

    private void UpdateFileBrowser(string directoryPath)
    {
        foreach (Transform child in buttonParent.transform)
        {
            Destroy(child.gameObject);
        }

        var directories = Directory.GetDirectories(directoryPath);
        foreach (var dir in directories)
        {
            GameObject button = Instantiate(ButtonTemplate, buttonParent.transform);
            button.GetComponentInChildren<TextMeshProUGUI>().text = dir;
            button.GetComponent<Button>().onClick.AddListener(() => ButtonClicked(dir));
            button.SetActive(true);
        }
        var files = Directory.GetFiles(directoryPath);
        foreach (var file in files)
        {
            string extension = Path.GetExtension(file).ToLower();
            if (extension == ".bloodasset") continue;  // Ignore .bloodasset files
            GameObject button = Instantiate(ButtonTemplate, buttonParent.transform);
            button.GetComponentInChildren<TextMeshProUGUI>().text = file;
            button.GetComponent<Button>().onClick.AddListener(() => ButtonClicked(file));
            button.SetActive(true);

            AssetType assetType;
            switch (extension)
            {
                case ".png":
                case ".jpg":
                    assetType = AssetType.Texture;
                    break;
                case ".fbx":
                case ".obj":
                    assetType = AssetType.Model;
                    break;
                case ".wav":
                case ".mp3":
                    assetType = AssetType.Sound;
                    break;
                case ".mp4":
                case ".mkv":
                case ".avi":
                case ".mov":
                    assetType = AssetType.Video;
                    break;
                default:
                    Debug.LogError("Unknown asset type for file extension " + extension);
                    continue;
            }

            string assetName = Path.GetFileNameWithoutExtension(file);
            GameAssetWrapper gameAssetInstance = new GameAssetWrapper(file, (int)assetType, assetName);
            gameAssetInstance.Serialize(file + ".bloodasset");
        }
    }
    void OnApplicationQuit()
    {
        var files = Directory.GetFiles(currentPath);
        foreach (var file in files)
        {
            string extension = Path.GetExtension(file).ToLower();
            if (extension == ".bloodasset")
            {
                File.Delete(file);
            }
        }
    }
}
