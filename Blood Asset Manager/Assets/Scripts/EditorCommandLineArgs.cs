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
