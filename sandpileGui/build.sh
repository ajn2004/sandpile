#! /usr/bin/env bash
g++ main.cpp sandpile/sand.cpp -o output `pkg-config --cflags --libs opencv4`
echo "yolo"
./output
