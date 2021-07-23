#pragma once 

namespace Maxy
{
    class WindowProps
    {
    public:
        WindowProps(const unsigned int width, const unsigned int height, std::string title)
            : m_Width(width), m_Height(height), m_Title(title) { }
    
        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }
        inline std::string GetTitle() const { return m_Title; }

    private:
        std::string m_Title;
        const unsigned int m_Width;
        const unsigned int m_Height;
    };
}