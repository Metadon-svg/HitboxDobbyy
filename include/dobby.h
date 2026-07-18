#ifndef dobby_h
#define dobby_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef enum {
  DobbyRegisterSuccess,
  DobbyRegisterError
} DobbyRegisterStatus;

typedef uintptr_t DobbyAddr;

// Dobby API
int DobbyInit(void);
int DobbyHook(DobbyAddr address, DobbyAddr replace_func, DobbyAddr *origin_func);
int DobbyUnhook(DobbyAddr address);
int DobbyDestroy(DobbyAddr address);

// Helper API
int DobbyCodePatch(void *address, uint32_t *buffer, uint32_t buffer_size);
int DobbyMemoryPermission(void *address, int size, int permission);

// Symbol Resolver API
void *DobbySymbolResolver(const char *image_name, const char *symbol_name_pattern);

// Import Table Replace API
int DobbyImportTableReplace(char *image_name, char *symbol_name, DobbyAddr fake_func, DobbyAddr *orig_func);

#ifdef __cplusplus
}
#endif

#endif
