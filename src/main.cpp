#include <pthread.h>
#include <unistd.h>
#include "hitbox_patcher.h"
#include "utils/library_utils.h"
#include "memory/offsets.h"

void* main_thread(void*) {
    do { 
        sleep(1); 
    } while (!Utils::isLibraryLoaded(Offsets::LIB_NAME));

    usleep(500000);

    HitboxPatcher::Apply();

    pthread_exit(nullptr);
    return nullptr;
}

__attribute__((constructor))
void _init() {
    pthread_t ptid;
    pthread_create(&ptid, nullptr, main_thread, nullptr);
}
