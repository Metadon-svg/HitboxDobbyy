#include "chat_hooks.h"
#include "hook_manager.h"
#include <string.h>

static void* orig_send_message = nullptr;
static void* orig_receive_message = nullptr;

static struct {
    const char* cmd;
    void* handler;
} s_commands[32];
static int s_cmd_count = 0;

int hooked_send_message(void* chat, const char* msg) {
    for (int i = 0; i < s_cmd_count; i++) {
        if (strncmp(msg, s_commands[i].cmd, strlen(s_commands[i].cmd)) == 0) {
            return 0;
        }
    }
    typedef int (*orig_fn)(void*, const char*);
    return ((orig_fn)orig_send_message)(chat, msg);
}

void hooked_receive_message(void* chat, const char* msg, int color) {
    typedef void (*orig_fn)(void*, const char*, int);
    ((orig_fn)orig_receive_message)(chat, msg, color);
}

namespace ChatHooks {

bool Init() {
    return true;
}

bool RegisterCommand(const char* cmd, void* handler) {
    if (s_cmd_count >= 32) return false;
    s_commands[s_cmd_count].cmd = cmd;
    s_commands[s_cmd_count].handler = handler;
    s_cmd_count++;
    return true;
}

bool HookSendMessage(uintptr_t func_addr) {
    return HookManager::Hook(func_addr, (void*)hooked_send_message, &orig_send_message);
}

bool HookReceiveMessage(uintptr_t func_addr) {
    return HookManager::Hook(func_addr, (void*)hooked_receive_message, &orig_receive_message);
}

void SendChatMessage(const char* msg) {
    if (orig_send_message) {
        typedef void (*fn)(void*, const char*);
    }
}

} // namespace ChatHooks
