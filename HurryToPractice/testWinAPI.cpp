#include "pch.h"
#include "testWinAPI.h"
#pragma comment(lib,"Shlwapi.lib")

std::wstring getExeDirPath()
{
	wchar_t szFilePath[MAX_PATH] = {};
	::GetModuleFileNameW(nullptr, szFilePath, MAX_PATH);

	::PathRemoveFileSpecW(szFilePath);


	return std::wstring(szFilePath);

	
}