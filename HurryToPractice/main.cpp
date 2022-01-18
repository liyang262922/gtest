#include<iostream>
#include<gtest/gtest.h>

int add(int a, int b)
{
	return a + b;
}

TEST(testCase, test0)
{
	EXPECT_EQ(add(2, 3), 6);
}

TEST(testCase, test1)
{
	EXPECT_EQ(add(3, 3), 6);
}

TEST(testCase, test2)
{
	EXPECT_EQ(add(6, 3), 6);
}


int main(int argc,char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;
}