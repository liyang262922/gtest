#pragma once
#include "pch.h"

namespace RAISEVER
{
	bool raiseVersion(std::wstring& strVer);

}




template<typename T>
bool splitStringWToSeqContainer(const wchar_t* srcString, T& resultContainer, const wchar_t* split)
{
	if (nullptr == srcString || nullptr == split || 0 == *srcString || 0 == *split || wcslen(split) > wcslen(srcString))
		return false;

	const wchar_t* begin = srcString;
	const wchar_t* p = wcsstr(begin, split);
	while (nullptr != p && 0 != *begin)
	{
		if (p - begin > 0) resultContainer.push_back(std::move(std::wstring(begin, p - begin)));
		begin = p + wcslen(split);

		p = wcsstr(begin, split);
	}

	if (0 != *begin) resultContainer.push_back(std::move(std::wstring(begin)));
	return true;
}