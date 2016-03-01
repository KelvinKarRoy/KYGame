#include "StringUtility.h"


void StringUtility::WStrToUTF8(std::string& dest, const std::wstring& src){
	dest.clear();

	for (size_t i = 0; i < src.size(); i++){
		wchar_t w = src[i];
		if (w <= 0x7f)
			dest.push_back((char)w);
		else if (w <= 0x7ff)
		{
			dest.push_back(0xc0 | ((w >> 6) & 0x1f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else if (w <= 0xffff)
		{
			dest.push_back(0xe0 | ((w >> 12) & 0x0f));
			dest.push_back(0x80 | ((w >> 6) & 0x3f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else if (sizeof(wchar_t) > 2 && w <= 0x10ffff)
		{
			dest.push_back(0xf0 | ((w >> 18) & 0x07)); // wchar_t 4-bytes situation  
			dest.push_back(0x80 | ((w >> 12) & 0x3f));
			dest.push_back(0x80 | ((w >> 6) & 0x3f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else
			dest.push_back('?');
	}
}
std::string StringUtility::WStrToUTF8(const std::wstring& str)
{
	std::string result;
	WStrToUTF8(result, str);
	return result;

}

//以某个字符分割string后存入string的vector
std::vector<std::string> StringUtility::split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//扩展字符串以方便操作 // 可以不用  
	int size = str.size();
	for (int i = 0; i<size; i++)
	{
		pos = str.find(pattern, i);
		if (pos<size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}



//unicode编码转成汉字
void StringUtility::Unicode2Char(std::string& dest, const std::string& src)
{
	std::string pattern = "\\u";
	std::vector<std::string> strVector = split(src,pattern);//以\u分割字符串
	
	std::wstring wstr;

	for (int i = 0; i < strVector.size(); ++i)
	{
		int nValue = 0;
		sscanf(strVector[i].c_str(), "%x", &nValue);
		wchar_t temp = nValue;
		wstr[i] = temp;
	}

	dest = WStrToUTF8(wstr);
}

std::string& StringUtility::Unicode2Char(const std::string& src)
{
	std::string dest;
	Unicode2Char(dest, src);
	return dest;
}

//本该读成wstring的字符串读成string了，修复之
void StringUtility::UnicodeStrToUTF8Str(std::string& dest, const std::string& src){
	std::wstring wstr;
	for (int i = 0 ; i < src.length(); ++i)
	{
		if (src[i] < 0)
		{

			int temp = (256 + src[i+1]) << 8 + ((src[i] < 0) ? (256 + src[i]) : src[i]);
			wstr.push_back(temp);
			i++;
		}else
		{
			wstr.push_back(src[i]);
		}

	}
	dest = WStrToUTF8(wstr);

}

std::string& StringUtility::UnicodeStrToUTF8Str(const std::string& src)
{
	std::string dest;
	UnicodeStrToUTF8Str(dest, src);
	return dest;
}


//将含有unicode编码的字符串转化为普通宽字符串
std::wstring StringUtility::decodeUnicode(const std::string& theString) {
	char aChar;
	int len = theString.length();
	std::wstring outBuffer;
	wchar_t aWChar;
	for (int x = 0; x < len;) {
		aChar = theString[x++];
		if (aChar == '\\') {
			aChar = theString[x++];
			if (aChar == 'u') {
				// Read the xxxx  
				int value = 0;
				for (int i = 0; i < 4; i++) {
					aChar = theString[x++];
					switch (aChar) {
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						value = (value << 4) + aChar - '0';
						break;
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
						value = (value << 4) + 10 + aChar - 'a';
						break;
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
						value = (value << 4) + 10 + aChar - 'A';
						break;
					default:
						break;
					}

				}
				outBuffer.push_back((wchar_t)value);
			}
			else {
				if (aChar == 't')
					aWChar = '\t';
				else if (aChar == 'r')
					aWChar = '\r';
				else if (aChar == 'n')
					aWChar = '\n';
				else if (aChar == 'f')
					aWChar = '\f';
				outBuffer.push_back(aWChar);
			}
		}
		else
			outBuffer.push_back((wchar_t)aChar);
	}
	return outBuffer;
}
/*
//格式化输入string
void StringUtility::format(std::string& dest, const char* format, ...)
{
	va_list arg_ptr;
	char temp[1024*10];
	_crt_va_start(arg_ptr, format);
	sprintf(temp, format, arg_ptr);
	_crt_va_end(arg_ptr);
	dest = temp;
}
*/
/*
//string转wstring
std::wstring StringUtility::str2wstr(std::string s)
{
	setlocale(0, "chs");
	const char* _Source = s.c_str();
	size_t _Dsize = s.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[]_Dest;
	setlocale(0, "C");
	return result;
}
*/