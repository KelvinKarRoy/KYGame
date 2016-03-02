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
	static bool decodeFlagData(std::string flagInfo);//��������ֵΪbool��json�ַ���
	static std::pair<std::vector<std::string>, std::vector<std::string>> 
		decodeQuestionData(std::string responseDataStr);//��������ʹ𰸵�json�ַ���
	
	void decodeInformation(std::string responseDataStr);//������Ϣ
	void decodeStatus(std::string responseDataStr);//����״̬

private:
	static DataUtility* dataUtility;
	static rapidjson::Document* document;
	
	DataUtility();
	~DataUtility();
};

