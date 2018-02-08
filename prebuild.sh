#!/bin/bash

export PATH="$PWD/depot_tools:$PATH"
cd skia

python tools/git-sync-deps
gn gen out/Static --args='is_debug=false　target_cpu="x64" is_official_build=true skia_use_system_libjpeg_turbo=false skia_use_system_libpng=false skia_use_system_libwebp=false skia_use_system_icu=false'
ninja -C out/Static

