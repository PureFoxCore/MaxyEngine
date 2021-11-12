#pragma once

#include <string>

namespace Maxy
{
    class FileSystem
    {
    public:
        FileSystem();
        ~FileSystem();

        static std::string ReadFile(const char *filePath);
    };
}