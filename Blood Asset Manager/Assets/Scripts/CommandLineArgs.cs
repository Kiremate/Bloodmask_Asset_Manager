using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CommandLineArgs : MonoBehaviour
{
    // A dictionary to hold command-line arguments
    private static Dictionary<string, string> args;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    static void RunBeforeSceneLoads()
    {
        // Parse command-line arguments
        args = new Dictionary<string, string>();
        var arguments = System.Environment.GetCommandLineArgs();

        for (int i = 0; i < arguments.Length; ++i)
        {
            var arg = arguments[i];
            if (arg.StartsWith("-"))
            {
                var value = i < arguments.Length - 1 ? arguments[i + 1] : null;
                value = (value != null && value.StartsWith("-")) ? null : value;

                // Add argument to dictionary, trimming the '-' character from the start
                args[arg.Substring(1)] = value;
            }
        }
    }

    public static string GetArg(string name)
    {
        string value = null;
        args?.TryGetValue(name, out value);
        return value;
    }
    public static void SetArgs(string[] arguments)
    {
        args = new Dictionary<string, string>();

        for (int i = 0; i < arguments.Length; ++i)
        {
            var arg = arguments[i];
            if (arg.StartsWith("-"))
            {
                var value = i < arguments.Length - 1 ? arguments[i + 1] : null;
                value = (value != null && value.StartsWith("-")) ? null : value;
                // Add argument to dictionary, trimming the '-' character from the start
                args[arg.Substring(1)] = value;
            }
        }
    }
}
