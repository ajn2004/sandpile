#! /usr/bin/env bash
g++ gui.cpp gif.h ../sand.cpp -o output `pkg-config --cflags --libs opencv4`
./output
cp ./* /mnt/c/Users/Andrew/Documents/from_linux/
