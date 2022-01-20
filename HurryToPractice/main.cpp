#include"test.h"

const std::wstring strVerTest = L"1.1.1.1000";

std::wstring raiseVersion_ini(std::wstring strVer)
{
	if (RAISEVER::raiseVersion(strVer))
	{
		return strVer;
	}
	return L"";
}

TEST(testCase, test)
{
	EXPECT_EQ(raiseVersion_ini(strVerTest), L"1.1.1.1005");
}

TEST(testCase, test2)
{
	EXPECT_EQ(raiseVersion_ini(strVerTest), L"1.1.1.1045");
}



int main(int argc,char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	return 0;
}
