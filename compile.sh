#!/bin/bash

build_type=$1
case $build_type in
    'Debug' | 'Release' | 'RelWithDebInfo' | 'MinSizeRel')
        echo "Using ${build_type}"
        ;;
    *)
        echo "Using default 'Debug' build type"
        build_type='Debug'
        ;;
esac

cmake -S . -B build -DCMAKE_BUILD_TYPE="$build_type" -GNinja
cmake --build build
