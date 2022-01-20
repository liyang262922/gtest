#include "pch.h"
#include "testRegex.h"

bool _isPe(std::wstring filename)
{
	std::wstring pattern = L"^.*\\.(EXE|DLL|SYS|exe|dll|sys)";
	std::wregex express(pattern);

	return std::regex_match(filename, express);
}