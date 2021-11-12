#include <mxpch.hpp>
#include "FileSystem.hpp"

#include <fstream>
#include "Logger.hpp"

namespace Maxy
{
    FileSystem::FileSystem()
    {
    }

    FileSystem::~FileSystem()
    {
    }

    std::string FileSystem::ReadFile(const char *filePath)
    {
        try
        {
            // ? Which one is better

            std::ifstream file(filePath);
            std::string result((std::istreambuf_iterator<char>(file)),
                               (std::istreambuf_iterator<char>()));

            return result;

            // ? IDK
            // FILE *file = fopen(filePath, "rt");
            // fseek(file, 0, SEEK_END);
            // unsigned long length = ftell(file);
            // char *data = new char[length + 1];
            // memset(data, 0, length + 1);
            // fseek(file, 0, SEEK_SET);
            // fread(data, 1, length, file);
            // fclose(file);

            // std::string result(data);
            // delete[] data;
            // return result;
        }
        catch (const std::exception &exception)
        {
            MAXY_ERROR(exception.what());
            return exception.what();
        }
    }
}