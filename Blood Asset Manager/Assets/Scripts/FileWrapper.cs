using System;
using System.Runtime.InteropServices;
using static AssetManager;

public class FileWrapper
{
#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN
    private const string DllName = "Bloodmask_Asset_Manager_DLL";
#elif UNITY_EDITOR_OSX || UNITY_STANDALONE_OSX
    private const string DllName = "Bloodmask_Asset_Manager_DLL.dylib";
#elif UNITY_STANDALONE_LINUX
    private const string DllName = "Bloodmask_Asset_Manager_DLL.so";
#endif

    [DllImport(DllName)]
    public static extern IntPtr File_Create(string path);

    [DllImport(DllName)]
    public static extern void File_Destroy(IntPtr file);

    [DllImport(DllName)]
    public static extern IntPtr File_CreateAndWrite(string path);

    [DllImport(DllName)]
    public static extern void File_Write(IntPtr file, string content);

    [DllImport(DllName)]
    public static extern IntPtr AssetManager_Create();

    [DllImport(DllName)]
    public static extern void AssetManager_Destroy(IntPtr assetManager);

    [DllImport(DllName)]
    public static extern IntPtr AssetManager_Load(IntPtr assetManager, string path);

    [DllImport(DllName)]
    public static extern IntPtr AssetManager_Get(IntPtr assetManager, string path);

    [DllImport(DllName)]
    public static extern void SerializeAsset(IntPtr gameAsset, string filepath);

    [DllImport(DllName)]
    public static extern IntPtr DeserializeAsset(string filepath);

    [DllImport(DllName, CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
    public static extern int AssetManager_Load_WithType(IntPtr assetManager, string path, int assetType, string assetName, out IntPtr outAsset);

    [DllImport(DllName)]
    public static extern void GameAsset_Destroy(IntPtr gameAsset);

    [DllImport(DllName)]
    public static extern int AssetSerializer_Serialize(IntPtr gameAsset, [MarshalAs(UnmanagedType.LPStr)] string filepath);

    [DllImport(DllName)]
    public static extern IntPtr AssetSerializer_Deserialize(string filepath);

    [DllImport(DllName)]
    public static extern string GameAsset_GetMetadata(IntPtr gameAsset);
}
