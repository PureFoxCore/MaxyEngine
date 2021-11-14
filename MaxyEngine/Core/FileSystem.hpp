#pragma once

#include <string>
#include <vector>

namespace Maxy
{
    class FileSystem
    {
    public:
        static const std::string ReadFile(const std::string filePath);
        static void WriteFile(const std::string filePath, const std::string content);
        static void AppendFile(const std::string filePath, const std::string content);

        static const std::string ReadBinaryFile(const std::string filePath);
        static void WriteBinaryFile(const std::string filePath, const std::string content);

        template <typename T>
        static void WriteBinaryFile(const std::string filePath, const std::vector<T> content);
    };
}