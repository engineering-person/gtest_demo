#include <gtest/gtest.h>

// 普通测试用例
TEST(MathTest, AddCase)
{
    int a = 1;
    int b = 2;
    EXPECT_EQ(a + b, 3);   // 断言相等，失败不终止
    ASSERT_EQ(a + b, 3);   // 断言相等，失败直接退出当前用例
}

TEST(MathTest, LessCase)
{
    EXPECT_LT(10, 20);
}
/*
est 提供了一个现成的 `main()` 实现，在 `gtest_main` 库：

- 如果你链接 `gtest_main` → **不用写 main**
- 如果你只链接 `gtest`（没有链接 gtest_main）→ **必须自己写这个 main**
# 方式A：用gtest自带main，不用手写main.cpp
target_link_libraries(run_test PRIVATE GTest::gtest GTest::gtest_main)

# 方式B：自己提供main函数，只链接gtest
target_link_libraries(run_test PRIVATE GTest::gtest)
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

*/

