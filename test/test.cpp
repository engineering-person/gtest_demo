#include <gtest/gtest.h>

// 普通测试用例
TEST(HelloWorld, AddCase)
{
    int a = 1;
    int b = 2;
    EXPECT_EQ(a + b, 3);   // 断言相等，失败不终止
    ASSERT_EQ(a + b, 3);   // 断言相等，失败直接退出当前用例
}

TEST(HelloWorld, LessCase)
{
    EXPECT_LT(10, 20);
}