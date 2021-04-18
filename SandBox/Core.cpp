#include <Maxy.h>

class SandBox : public Maxy::Application
{
public:
    SandBox()
    {

    }

    ~SandBox()
    {

    }
};

Maxy::Application* Maxy::CreateApplication()
{
    return new SandBox;
}