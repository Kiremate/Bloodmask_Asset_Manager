/**
 * @author bloodmask
 * @date 23/01/26
 * @brief The File class is a wrapper for the boost::filesystem library, 
 * providing a simplified interface for common file operations such as
 * copying, moving, and deleting files. Additionally, 
 * it provides methods for retrieving information about a file such as its name, path, 
 * size, extension, creation time, last access time, and last write time.
 * 
 * Detailed Description:
 * The File class is designed to make it easy to perform common file operations in a cross-platform manner.
 * 
 * It uses the boost::filesystem library to handle file operations,
 * and wraps it with a simpler interface that is easy to use.
 *
 * The class has a constructor that takes a single argument, 
   the path of the file to be manipulated. The path can be either an absolute or relative path.
 *
 * The class provides several methods for retrieving information about a file. 
 * The GetName() method returns the name of the file without the path or extension. 
 * The GetPath() method returns the full path of the file. 
 * The GetSize() method returns the size of the file in bytes. 
 * The GetExtension() method returns the file extension, including the dot. 
 * The GetCreationTime() method returns the creation time of the file as a string in the format YYYY-MM-DD HH:MM:SS. 
 * The GetLastAccessTime() method returns the last access time of the file as a string in the format YYYY-MM-DD HH:MM:SS. 
 * The GetLastWriteTime() method returns the last write time of the file as a string in the format YYYY-MM-DD HH:MM:SS.
 *
 * The class also provides several methods for performing common file operations. 
 * The Copy() method takes a single argument, the destination path, and copies the file to that location. 
 * The Move() method takes a single argument, the destination path, and moves the file to that location.
 */
#pragma once
#include <string>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include "Api.h"
namespace blood_manager {
    class BLOOD_MANAGER_API File {
    public:
        // Todo el codigo maquina de todas las funciones no inline
        // se va a meter en la dll
        File(const std::string& path);
        virtual ~File() = default;
        std::string GetName() const;
        std::string GetPath() const;
        std::int64_t GetSize() const;
        std::string GetExtension() const;
        std::string GetCreationTime() const;
        std::string GetLastAccessTime() const;
        std::string GetLastWriteTime() const;

        virtual void Copy(const std::string& destPath);
        virtual void Move(const std::string& destPath);
        virtual void Write(const std::string& content);
        virtual void Rename(const std::string& newName);
        virtual void Create();
        virtual void Delete();
  
    protected:
        boost::filesystem::wpath _path;
    };
}