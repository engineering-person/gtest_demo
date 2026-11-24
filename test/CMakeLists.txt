# 查找gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 测试程序
add_executable(run_test test_main.cpp)
target_link_libraries(run_test GTest::gtest GTest::gtest_main)

# 注册给ctest，让流水线脚本可以用ctest跑
enable_testing()
add_test(NAME AllGTest COMMAND run_test)
