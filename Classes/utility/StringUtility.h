#pragma once
#include "string"
#include "vector"
#include "stdlib.h"

class StringUtility{
public:
	void static WStrToUTF8(std::string& dest, const std::wstring& src);
	std::string static WStrToUTF8(const std::wstring& str);

	static std::vector<std::string> split(std::string str, std::string pattern);


	static void Unicode2Char(std::string& dest, const std::string& src);
	static std::string& Unicode2Char(const std::string& src);

	static void UnicodeStrToUTF8Str(std::string& dest, const std::string& src);
	static std::string& UnicodeStrToUTF8Str(const std::string& src);

	static std::wstring decodeUnicode(const std::string& theString);

	//static void format(std::string& dest,const char* format,...);
	
	//static std::wstring str2wstr(std::string str);

    
};