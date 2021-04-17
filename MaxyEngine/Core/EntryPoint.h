#pragma once

#include "Application.h"
#include "Logger.h"

extern Maxy::Core::Application* Maxy::Core::CreateApplication();

int main(int argc, char** argv)
{
    Maxy::Core::Logger::Init();
    MAXY_CORE_INFO("Logger initialized!");

    auto app = Maxy::Core::CreateApplication();
    app->Run();
    delete &app;
    return 0;
}