#pragma once

#if defined _WIN32
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
#elif defined (__APPLE__)
#endif

#define BIT(x) (1 << x)