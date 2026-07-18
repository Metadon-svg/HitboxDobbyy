#pragma once
#include <cstdint>

// === ЗАГЛУШКА Dobby ===
// Заменить на настоящий dobby.h когда будет libdobby.a

inline int DobbyInit() { return 0; }
inline int DobbyHook(void* target, void* replacement, void** original) { return -1; }
inline int DobbyUnhook(void* target) { return -1; }
inline int DobbyDestroy(void* target) { return -1; }
