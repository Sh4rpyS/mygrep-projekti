@echo off
g++ -o mygrep.exe src/*.cpp -Iinclude -static -static-libgcc -std=c++20

echo script done