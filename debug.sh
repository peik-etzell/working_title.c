#!/bin/bash

./compile.sh Debug || exit
gdbserver localhost:1234 ./build/working_title
