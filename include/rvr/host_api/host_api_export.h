// Copyright 2026, Iurii Sernivka.

#pragma once

// Windows
#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef RVR_HOST_API_BUILD
        #define RVR_HOST_API __declspec(dllexport)
    #else
        #define RVR_HOST_API __declspec(dllimport)
    #endif

// Linux/macOS
#else
    #ifdef RVR_HOST_API_BUILD
        #define RVR_HOST_API __attribute__((visibility("default")))
    #else
        #define RVR_HOST_API
    #endif
#endif
