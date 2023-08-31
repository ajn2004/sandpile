#! /usr/bin/env bash
g++ gui.cpp ../sand.cpp -o output `pkg-config --cflags --libs opencv4`
./output
