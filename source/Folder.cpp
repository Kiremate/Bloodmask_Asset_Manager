#include "../headers/Folder.h"

blood_manager::Folder::Folder(const std::string& path) : File(path)
{
    if (!boost::filesystem::is_directory(_path))
    {
        throw std::runtime_error("Path is not a directory.");
    }
}
void blood_manager::Folder::Copy(const std::string& destPath) {
	boost::filesystem::copy(_path, destPath, boost::filesystem::copy_options::recursive);
}

void blood_manager::Folder::Move(const std::string& destPath)
{
    boost::filesystem::rename(_path, destPath);
}

void blood_manager::Folder::Delete()
{
    boost::filesystem::remove_all(_path);
}

std::vector<blood_manager::File> blood_manager::Folder::GetFiles() const
{
    std::vector<File> files;
    for (auto& entry : boost::filesystem::directory_iterator(_path))
    {
        if (boost::filesystem::is_regular_file(entry))
        {
            files.push_back(File(entry.path().string()));
        }
    }
    return files;
}

std::vector<blood_manager::Folder> blood_manager::Folder::GetFolders() const
{
    std::vector<Folder> folders;
    for (auto& entry : boost::filesystem::directory_iterator(_path))
    {
        if (boost::filesystem::is_directory(entry))
        {
            folders.push_back(Folder(entry.path().string()));
        }
    }
    return folders;
}

void blood_manager::Folder::Create()
{
    boost::filesystem::create_directory(_path);
}

void blood_manager::Folder::Rename(const std::string& newName)
{
    boost::filesystem::rename(_path, _path.parent_path() / newName);
}