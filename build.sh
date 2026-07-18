#!/bin/bash

NDK_PATH="${ANDROID_NDK_HOME:-$HOME/Android/Sdk/ndk/25.2.9519653}"

mkdir -p build
cd build

cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=$NDK_PATH/build/cmake/android.toolchain.cmake \
    -DANDROID_ABI=arm64-v8a \
    -DANDROID_PLATFORM=android-21 \
    -DCMAKE_BUILD_TYPE=Release

make -j$(nproc)
