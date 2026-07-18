#include "hook_manager.h"

bool HookManager::s_initialized = false;

bool HookManager::Init() {
    if (s_initialized) return true;
    s_initialized = (DobbyInit() == 0);
    return s_initialized;
}

bool HookManager::Hook(uintptr_t target, void* replacement, void** original) {
    if (!s_initialized && !Init()) return false;
    return DobbyHook((DobbyAddr)target, (DobbyAddr)replacement, (DobbyAddr*)original) == 0;
}

bool HookManager::Unhook(uintptr_t target) {
    if (!s_initialized) return false;
    return DobbyUnhook((DobbyAddr)target) == 0;
}

bool HookManager::IsReady() {
    return s_initialized;
}
