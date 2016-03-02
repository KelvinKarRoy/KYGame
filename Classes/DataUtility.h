#pragma once

#include "external/json/document.h"
#include "external/json/writer.h"
#include "external/json/reader.h"
#include "external/json/stringbuffer.h"


#include "cocos2d.h"

#include "StringUtility.h"
#include "Self.h"

using namespace std;

class DataUtility
{
public:
	struct{
		std::string account;
		std::string password;
	}m_player;
	static DataUtility* getInstance();
	static bool decodeFlagData(std::string flagInfo);//解析返回值为bool的json字符串
	static std::pair<std::vector<std::string>, std::vector<std::string>> 
		decodeQuestionData(std::string responseDataStr);//解析问题和答案的json字符串
	
	void decodeInformation(std::string responseDataStr);//解析信息
	void decodeStatus(std::string responseDataStr);//解析状态

private:
	static DataUtility* dataUtility;
	static rapidjson::Document* document;
	
	DataUtility();
	~DataUtility();
};

