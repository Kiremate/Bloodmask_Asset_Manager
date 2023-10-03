//#pragma once
//
//#include <string>
//#include <vector>
//#include "File.h"
//#include "Folder.h"
//#include "Api.h"
//
//namespace blood_manager {
//
//    class BLOOD_MANAGER_API FileSystem {
//    public:
//        FileSystem() = default;
//
//        // Higher-level methods to interact with the file system
//        File CreateFile(const std::string& path);
//        Folder CreateFolder(const std::string& path);
//
//        void CopyFile(const std::string& srcPath, const std::string& destPath);
//        void CopyFolder(const std::string& srcPath, const std::string& destPath);
//
//        void MoveFile(const std::string& srcPath, const std::string& destPath);
//        void MoveFolder(const std::string& srcPath, const std::string& destPath);
//
//        void DeleteFile(const std::string& path);
//        void DeleteFolder(const std::string& path);
//
//        void RenameFile(const std::string& path, const std::string& newName);
//        void RenameFolder(const std::string& path, const std::string& newName);
//
//        std::vector<File> GetFilesInFolder(const std::string& folderPath) const;
//        std::vector<Folder> GetFoldersInFolder(const std::string& folderPath) const;
//    };
//
//}
