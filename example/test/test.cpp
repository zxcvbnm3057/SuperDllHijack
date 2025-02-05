// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <windows.h>

typedef int (*pfn_TestExport)(int, int);

int main()
{
	// HMODULE hLib = LoadLibraryA("dll.dll");
	HMODULE hLib = LoadLibraryA("fakedll.dll");
	if (hLib)
	{
		pfn_TestExport add = (pfn_TestExport)GetProcAddress(hLib, "TestExport");
		if (add)
		{
			std::cout << "1 + 1 = " << add(1, 1) << std::endl;
		}
		else
		{
			std::cout << "get export function address error " << std::endl;
		}
	}
	else
	{
		std::cout << "load dll error: " << GetLastError() << std::endl;
	}
	getchar();
	return 0;
}