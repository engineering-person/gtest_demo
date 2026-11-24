#!/bin/bash
set -e

rm -rf build
mkdir build
cd build
cmake ..
make -j$(nproc)
echo "✅ 编译完成，产物在 build 目录"
