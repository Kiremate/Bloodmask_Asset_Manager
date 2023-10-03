/**
@author bloodmask
@date 23/01/26
@brief The Folder class is a wrapper for the boost::filesystem library,
 * providing a simplified interface for common folder operations such as
 * creating, deleting and renaming folders, as well as listing the files and 
 * subfolders contained within a folder.
 * Additionally, it provides methods for retrieving information about a folder such as its name and path.
 * Detailed Description:
 * The Folder class is designed to make it easy to perform common 
 * folder operations in a cross-platform manner.
 * It uses the boost::filesystem library to handle folder operations,
 * and wraps it with a simpler interface that is easy to use.
 * The class has a constructor that takes a single argument,
 * the path of the folder to be manipulated. The path can be either an absolute or relative path.
 * The class provides several methods for retrieving information about a folder.
 * The GetName() method returns the name of the folder without the path.
 * The GetPath() method returns the full path of the folder.
 * The GetFiles() method returns a list of the files contained within the folder.
 * The GetFolders() method returns a list of the subfolders contained within the folder.
 * The class also provides several methods for performing common folder operations.
 * The Create() method creates a new folder at the specified path.
 * The Delete() method deletes the folder at the specified path.
 * The Rename() method takes a single argument, the new name, and renames the folder.
*/
#pragma once
#include "File.h"
#include "Api.h"
#include <vector>

namespace blood_manager {
    class BLOOD_MANAGER_API Folder : File {
    public:
        Folder(const std::string& path);
        Folder() = default;
        // Override base class methods as needed
        void Copy(const std::string& destPath) override;
        void Move(const std::string& destPath) override;
        void Delete() override;

        // Additional methods specific to Folder
        std::vector<File> GetFiles() const;
        std::vector<Folder> GetFolders() const;
        void Create();
        void Rename(const std::string& newName);
    };
}