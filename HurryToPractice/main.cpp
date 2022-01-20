#include"pch.h"
#include<gtest/gtest.h>
#include"testRegex.h"
#include"testWinAPI.h"
#include"testCmdExe.h"

#define GTEST

/*
TEST(testRegex, test1)
{
	EXPECT_EQ(_isPe(L"helios.DLL"), true);
	EXPECT_EQ(_isPe(L"helios.dll"), true);
	EXPECT_EQ(_isPe(L"helios.exe"), false);
	EXPECT_EQ(_isPe(L"helios.EXE"), false);
	EXPECT_EQ(_isPe(L"helios.SYS"), true);
	EXPECT_EQ(_isPe(L"helios.sys"), true);
}

TEST(testRegex, test2)
{
	EXPECT_EQ(_isPe(L"heliosexe"), false);
}

*/

const std::wstring exePath = L"C:\\Users\\26292\\Desktop\\tmp\\configXmlTool.exe";


TEST(testConfigXmlTool, test0)
{
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever lightmi.xml"), 0);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever cacert.pem"), 0);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever AegisMain.xml"), 0);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever OneDns.xml"), 0);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever conf.PlugSaaSEdr.xml"), 0);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever conf.Plugtd.xml"), 0);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever TbCardinal.dat"), 0);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever signlist.xml"), 0);
}

TEST(testConfigXmlTool, test1)
{
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever"), 1);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever hh  hh"), 1);
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -help hhhh"), 1);
}

TEST(testConfigXmlTool, test2)
{
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever Helios.dll"), 2);
}

TEST(testConfigXmlTool, test7)
{
	EXPECT_EQ(TestCmdExe::execExe(exePath, L" -raisenpever hdelios.xml"), 7);
}




int main(int argc,char** argv)
{
#ifdef GTEST
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
#elif
	std::wstring params = L" ";
	TestCmdExe::execExe(exePath, params);
#endif

	return 0;
}
