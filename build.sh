#! /usr/bin/env bash
g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` sand.cpp -o sand`python3-config --extension-suffix`
