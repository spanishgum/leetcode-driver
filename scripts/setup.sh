#!/bin/sh

mkdir -p dist
cd dist
conan install .. -s os="Linux" -s compiler="clang" --build spdlog --build fmt
