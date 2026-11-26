# 查找gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 测试程序
aux_source_directory(. SRC_LIST)
add_executable(run_test ${SRC_LIST})
target_link_libraries(run_test GTest::gtest GTest::gtest_main)


target_include_directories(run_test PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(run_test cal)

# 注册给ctest，让流水线脚本可以用ctest跑
enable_testing()
add_test(NAME AllGTest COMMAND run_test)
