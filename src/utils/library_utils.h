#pragma once
#include <string>
#include <dlfcn.h>
#include <link.h>
#include <string.h>
#include <cstdint>

namespace Utils {
    bool isLibraryLoaded(const char* libName);
    uintptr_t getAbsoluteAddress(const char* libName, uintptr_t offset);
}
