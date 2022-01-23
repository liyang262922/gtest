#include<iostream>
#include<gtest/gtest.h>
#include "testRegex.h"

TEST(testRegex,test1)
{
	EXPECT_EQ(isPe(L"helios.dll"), true);
}

TEST(testRegex, test2)
{
	EXPECT_EQ(isPe(L"helios.exe"), true);
}


TEST(testRegex, test3)
{
	EXPECT_EQ(isPe(L"helios.sys"), true);
}

TEST(testRegex, test4)
{
	EXPECT_EQ(isPe(L"helios.xml"), false);
}

TEST(testRegex, test5)
{
	EXPECT_EQ(isPe(L"helios.DLL"), true);
}

TEST(testRegex, test6)
{
	EXPECT_EQ(isPe(L"heliosdll"), false);
}


int main(int argc,char** argv)
{
	//testing::InitGoogleTest(&argc, argv);
	//RUN_ALL_TESTS();

	isPe(L"heliosfdddldll");

	getchar();
	return 0;
}
