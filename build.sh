#!/bin/bash

set -eux

g++ -std=c++11 -I${PWD}/skia/include/core -I${PWD}/skia/include/config -I${PWD}/skia/include/utils -I${PWD}/skia/include/gpu -L${PWD}/skia/out/Static -lskia -lz -framework CoreFoundation -framework CoreGraphics -framework CoreText -framework CoreServices -o example example.cpp
