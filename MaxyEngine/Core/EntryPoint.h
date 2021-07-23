#pragma once

#include "Core/Application.h"
#include "Core/Logger.h"

extern Maxy::Application *Maxy::CreateApplication();

int main(int argc, char **argv)
{
    Maxy::Logger::Init();
    MAXY_CORE_INFO("Logger initialized!");

    auto app = Maxy::CreateApplication();
    app->Run();
    // delete &app;
    return 0;
}