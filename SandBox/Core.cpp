#include <Maxy.h>

class SandBox : public Maxy::Core::Application
{
public:
    SandBox()
    {

    }

    ~SandBox()
    {

    }
};

Maxy::Core::Application* Maxy::Core::CreateApplication()
{
    return new SandBox;
}