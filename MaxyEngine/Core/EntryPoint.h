#pragma once

#include "Application.h"

extern Maxy::Core::Application* Maxy::Core::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Maxy::Core::CreateApplication();
    app->Run();
    delete &app;
    return 0;
}