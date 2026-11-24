#!/bin/bash
set -e

cd build
ctest --output-on-failure
echo "✅ 所有单元测试通过"
