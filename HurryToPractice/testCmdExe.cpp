#include"pch.h"
#include "testCmdExe.h"


DWORD TestCmdExe::execExe(const std::wstring& exePath,const std::wstring& params)
{
	DWORD exitCode = -1;
	std::error_code ec;

	if (std::filesystem::exists(exePath.c_str(), ec))
	{
		STARTUPINFOW suiw{};
		suiw.cb = sizeof(suiw);
		PROCESS_INFORMATION pi{};
		std::wstring cmdLine = exePath + params;
		auto bSuc = ::CreateProcessW(NULL, cmdLine.data(), NULL, NULL, FALSE, 0, 0, NULL, &suiw, &pi);

		if (bSuc)
		{
			while (true)
			{
				auto wait = WaitForSingleObject(pi.hProcess, 50);

				if (WAIT_OBJECT_0 == wait)
				{
					GetExitCodeProcess(pi.hProcess, &exitCode);
					break;
				}
			}
		}
	}
	return exitCode;
}