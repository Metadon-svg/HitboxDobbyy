#pragma once
#include "dobby.h"

class HookManager {
public:
    static bool Init();
    static bool Hook(void* target, void* replacement, void** original);
    static bool Unhook(void* target);
};
