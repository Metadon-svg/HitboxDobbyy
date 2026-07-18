#include "hook_manager.h"

bool HookManager::Init() {
    return DobbyInit() == 0;
}

bool HookManager::Hook(void* target, void* replacement, void** original) {
    return DobbyHook(target, replacement, original) == 0;
}

bool HookManager::Unhook(void* target) {
    return DobbyUnhook(target) == 0;
}
