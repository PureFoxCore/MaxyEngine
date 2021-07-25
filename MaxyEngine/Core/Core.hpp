#pragma once

#ifdef MAXY_PLATFORM_WINDOWS
#endif

#ifdef MAXY_PLATFORM_LINUX
#endif

#ifdef MAXY_PLATFORM_APPLE
#endif

#define BIT(x) (1 << x)
#define MAXY_BIND_EVENT_FN(event) std::bind(&event, this, std::placeholders::_1)