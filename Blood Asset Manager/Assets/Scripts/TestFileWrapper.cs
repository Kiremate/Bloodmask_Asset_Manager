using System;
using System.Runtime.InteropServices;
using UnityEngine;

public class TestFileWrapper : MonoBehaviour
{
    void Start()
    {
        // Create a File instance using the FileWrapper
        string path = "example.txt";
        IntPtr fileInstance = FileWrapper.File_CreateAndWrite(path);

        // Write some content to the file
        FileWrapper.File_Write(fileInstance, "Hello, world!");

        Debug.Log("File created and written at: " + path);

        // Destroy the File instance when done
       //FileWrapper.File_Destroy(fileInstance);
    }
}
