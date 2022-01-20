#include "test.h"

bool RAISEVER::raiseVersion(std::wstring& strVer)
{

	std::vector<std::wstring> vec{};
	if (!splitStringWToSeqContainer(strVer.c_str(), vec, L"."))
	{
		return false;
	}

	strVer.clear();
	for (auto it = vec.begin(); it != vec.end() - 1; it++)
		strVer += (*it + L".");

	int ver = _wtoi(vec.back().c_str()) + 5;

	strVer += std::to_wstring(ver);

	return true;

}