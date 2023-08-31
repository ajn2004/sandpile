#! /usr/bin/env bash
g++ main.cpp ../sand.cpp -o output `pkg-config --cflags --libs opencv4`
echo "yolo"
./output
