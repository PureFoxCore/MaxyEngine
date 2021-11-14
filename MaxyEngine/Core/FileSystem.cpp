#include <mxpch.hpp>
#include "FileSystem.hpp"

#include <fstream>
#include "Logger.hpp"

namespace Maxy
{
    const std::string FileSystem::ReadFile(const std::string filePath)
    {
        try
        {
            std::ifstream file(filePath);
            std::string result((std::istreambuf_iterator<char>(file)),
                               (std::istreambuf_iterator<char>()));

            return result;
        }
        catch (const std::exception &exception)
        {
            MAXY_CORE_ERROR(exception.what());
            return exception.what();
        }
    }

    void FileSystem::WriteFile(const std::string filePath, const std::string content)
    {
        try
        {
            std::ofstream file(filePath);
            file << content;
            file.close();
        }
        catch (const std::exception &exception)
        {
            MAXY_CORE_ERROR(exception.what());
        }
    }

    void FileSystem::AppendFile(const std::string filePath, const std::string content)
    {
        try
        {
            std::ofstream file(filePath, std::ios_base::app);
            file << content;
            file.close();
        }
        catch (const std::exception &exception)
        {
            MAXY_CORE_ERROR(exception.what());
        }
    }

    const std::string FileSystem::ReadBinaryFile(const std::string filePath)
    {
        std::ifstream file(filePath, std::ios::in | std::ios::binary | std::ios::ate);
        std::streampos size = file.tellg();
        char *data = new char[size];
        file.seekg(0, std::ios::beg);
        file.read(data, size);
        file.close();

        std::string result(data);
        delete[] data;
        return result;
    }

    void FileSystem::WriteBinaryFile(const std::string filePath, const std::string content)
    {
        std::ofstream file(filePath, std::ios::out | std::ios::binary);
        // TODO(PureFoxCore): Suppress error [-Wsizeof-pointer-div]
        unsigned long size = sizeof(content.c_str()) / sizeof(*content.c_str());
        file.write(content.c_str(), size);
        file.close();
    }


    // ! TODO(PureFoxCore): Fix linking issue
    template <typename T>
    void FileSystem::WriteBinaryFile(const std::string filePath, const std::vector<T> content)
    {
        std::ofstream file(filePath, std::ios::out | std::ios::binary);
        file.write(reinterpret_cast<const char *>(&content), content.size() * sizeof(T));
    }
}