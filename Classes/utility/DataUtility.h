#pragma once

#include "external/json/document.h"
#include "external/json/writer.h"
#include "external/json/reader.h"
#include "external/json/stringbuffer.h"


#include "cocos2d.h"

#include "HttpUtility.h"
#include "StringUtility.h"
//#include "../model/Self.h"

using namespace std;

class DataUtility
{
public:
	struct{
		std::string account;
		std::string password;
	}m_player;
	static DataUtility* getInstance();
	static bool decodeFlagData(std::string flagInfo);//Ω‚Œˆ∑µªÿ÷µŒ™boolµƒjson◊÷∑˚¥Æ
	static std::pair<std::vector<std::string>, std::vector<std::string>> 
		decodeQuestionData(std::string responseDataStr);//Ω‚ŒˆŒ Ã‚∫Õ¥∞∏µƒjson◊÷∑˚¥Æ
	
	static void decodeInformation(std::string responseDataStr);//解析玩家信息
    static void decodePlayerID(std::string responseDataStr);//解析玩家ID
    static void decodeNotice(std::string responseDataStr);//解析公告
    static void decodeMail(std::string responseDataStr);//解析邮件
    static void decodeFriends(std::string responseDataStr);//加载friends列表信息
    
private:
	static DataUtility* dataUtility;
	static rapidjson::Document* document;
	
	DataUtility();
	~DataUtility();
};

