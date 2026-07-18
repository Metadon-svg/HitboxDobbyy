#pragma once
#include <cstdint>

namespace ChatHooks {
    bool Init();
    bool RegisterCommand(const char* cmd, void* handler);
    bool HookSendMessage(uintptr_t func_addr);
    bool HookReceiveMessage(uintptr_t func_addr);
    void SendChatMessage(const char* msg);
}
