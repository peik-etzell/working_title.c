#!/usr/bin/env sh

case $1 in
    'Debug' | 'Release' | 'RelWithDebInfo' | 'MinSizeRel')
        echo "Using $1"
        export CMAKE_BUILD_TYPE="$1"
        ;;
    *)
        echo "Using default 'Debug' build type"
        export CMAKE_BUILD_TYPE='Debug'
        ;;
esac

cmake -S . -B build
cmake --build build
