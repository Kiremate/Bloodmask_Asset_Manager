#include "../headers/File.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <boost/filesystem/operations.hpp>
#if defined(_WIN32)
#include <windows.h>
#else
#include <sys/stat.h>
#include <unistd.h>
#endif
blood_manager::File::File(const std::string& path) : _path(path)
{
}
std::string blood_manager::File::GetName() const
{
	return _path.filename().string();
}

std::string blood_manager::File::GetPath() const
{
	return _path.string();
}

std::int64_t blood_manager::File::GetSize() const
{
	return boost::filesystem::file_size(_path);
}

std::string blood_manager::File::GetExtension() const
{
	return _path.extension().string();
}

std::string blood_manager::File::GetCreationTime() const
{
#if defined(_WIN32)
	HANDLE hFile = CreateFile(_path.c_str(), GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return "";

	FILETIME ftCreation;
	if (GetFileTime(hFile, &ftCreation, NULL, NULL) == 0)
		return "";

	CloseHandle(hFile);

	SYSTEMTIME stUTC, stLocal;
	if (FileTimeToSystemTime(&ftCreation, &stUTC) == 0)
		return "";

	if (SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal) == 0)
		return "";

	char buffer[32];
	if (sprintf_s(buffer, "%04d-%02d-%02d %02d:%02d:%02d", 
		stLocal.wYear, stLocal.wMonth, stLocal.wDay,
		stLocal.wHour, stLocal.wMinute, stLocal.wSecond) < 0)
		return "";

	return buffer;
#else
	struct stat attrib;
	if (stat(m_path.c_str(), &attrib) != 0)
		return "";

	char buffer[32];
	tm* time = gmtime(&(attrib.st_ctime));
	if (strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", time) <= 0)
		return "";

	return buffer;
#endif
}

std::string blood_manager::File::GetLastAccessTime() const
{
#if defined(_WIN32)
	HANDLE hFile = CreateFile(_path.c_str(), GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return "";

	FILETIME ftAccess;
	if (GetFileTime(hFile, NULL, &ftAccess, NULL) == 0)
		return "";

	CloseHandle(hFile);

	SYSTEMTIME stUTC, stLocal;
	if (FileTimeToSystemTime(&ftAccess, &stUTC) == 0)
		return "";

	if (SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal) == 0)
		return "";

	char buffer[32];
	if (sprintf_s(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
		stLocal.wYear, stLocal.wMonth, stLocal.wDay,
		stLocal.wHour, stLocal.wMinute, stLocal.wSecond) < 0)
		return "";

	return buffer;
#else
	// Linux implementation
	if (stat(m_path.c_str(), &attrib) != 0)
		return "";
	char buffer[32];
	tm* time = gmtime(&(attrib.st_atime));
	if (strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", time) <= 0)
		return "";
	return buffer;
#endif
}

// @Warning : This function is not implemented on Linux localtime_s is not
// available in all platforms
std::string blood_manager::File::GetLastWriteTime() const
{
	std::time_t writetime = boost::filesystem::last_write_time(_path);
	std::tm* timeinfo = new std::tm();
	localtime_s(timeinfo,&writetime);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
	std::string result(buffer);
	delete timeinfo;
	return result;
}

void blood_manager::File::Copy(const std::string& destPath)
{
	assert(boost::filesystem::exists(_path));
	assert(boost::filesystem::exists(destPath));
	boost::filesystem::copy(_path, destPath, boost::filesystem::copy_options::overwrite_existing);
}

void blood_manager::File::Move(const std::string& destPath)
{
	// I don't like to use try catch but I don't know how to handle this error otherwise
	 try 
	 { 
		 boost::filesystem::rename(_path, destPath);
	 } 
	 catch (const boost::filesystem::filesystem_error& ex) 
	 { 
		 assert(false && ex.what()); 
	 } 
}

void blood_manager::File::Write(const std::string& content)
{
	boost::filesystem::ofstream ofs(_path, std::ios::out | std::ios::binary);
	if (ofs.is_open()) {
		ofs << content;
		ofs.close();
	}
	else {
		throw std::runtime_error("Unable to open file for writing.");
	}
}

void blood_manager::File::Rename(const std::string& newName)
{
	// Obtain the parent path (directory) of the file
	boost::filesystem::path parentPath = _path.parent_path();

	// Construct a new path with the new name in the original directory
	boost::filesystem::path newPath = parentPath / newName;

	// Rename the file
	try
	{
		boost::filesystem::rename(_path, newPath);
		_path = newPath; // Update _path member to the new file location
	}
	catch (const boost::filesystem::filesystem_error& ex)
	{
		assert(false && ex.what());
	}
}

void blood_manager::File::Create()
{
	boost::filesystem::ofstream newFile(_path);
}

void blood_manager::File::Delete()
{
	assert(boost::filesystem::remove(_path));
}
