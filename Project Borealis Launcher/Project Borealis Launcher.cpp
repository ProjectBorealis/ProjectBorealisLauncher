// Project Borealis Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <string>

int main(int argc, char* argv[])
{
	FreeConsole();
	std::string commandLineStr = "";
	for (int i = 1; i < argc; i++) commandLineStr.append(argv[i]).append(" ");
	// -vulkanpresentmode=VkPresentModeKHR (0 for no vsync)
	commandLineStr.append(" -dx12"); // " -opengl4", " -vulkan" or " -dx10" or comment out
	int slength = (int)commandLineStr.length() + 1;
	const char* cmdLineCStr = commandLineStr.c_str();
	int len = MultiByteToWideChar(CP_ACP, 0, cmdLineCStr, slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, cmdLineCStr, slength, buf, len);
	if (ShellExecute(
		NULL, // No parent window
		L"open",
		L".\\WindowsNoEditor\\ProjectBorealis.exe",
		std::wstring(buf).c_str(),
		NULL, // cwd
		10 // Let application decide
	))
	{
		printf("Executed with Code %d", GetLastError());
		return 0;
	}
	printf("Failed with Error %d", GetLastError());
	return 1;
}

