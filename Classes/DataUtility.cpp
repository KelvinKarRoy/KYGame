#include "DataUtility.h"

DataUtility* DataUtility::dataUtility = DataUtility::getInstance();

rapidjson::Document* DataUtility::document = new rapidjson::Document();

DataUtility::DataUtility()
{
}


DataUtility::~DataUtility()
{
}


DataUtility* DataUtility::getInstance()
{
	if (dataUtility == nullptr)
	{
		dataUtility = new DataUtility();
	}
	return dataUtility;
}


//解析json字符串
bool DataUtility::decodeFlagData(std::string flagInfo)
{
	
	document->Parse<0>(flagInfo.c_str());
	//解析错误
	CCASSERT(!document->HasParseError(), "Parsing to document failure.");

	CCLOG("%s", "Parsing to document succeeded.");
	//是否含有data
	CC_ASSERT(document->IsObject() && document->HasMember("data"));
	
	const rapidjson::Value & dataString = (*document)["data"];
	//data内是否有flag
	CC_ASSERT(dataString.IsObject() && dataString.HasMember("flag"));

	//获取flag
	const rapidjson::Value & flag = dataString["flag"];

	CC_ASSERT(flag.IsBool());

	return flag.GetBool();
}


std::pair<std::vector<std::string>, std::vector<std::string>> 
DataUtility::decodeQuestionData(std::string questionInfo)//解析问题和答案的json字符串
{
	std::vector<std::string> questionVector;
	std::vector<std::string> answerVector;

	questionInfo = StringUtility::WStrToUTF8(StringUtility::decodeUnicode(questionInfo));//对json字符串中的unicode编码进行转换

	CCLOG("%s",questionInfo.c_str());

	document->Parse<0>(questionInfo.c_str());
	//解析错误
	CCASSERT(!document->HasParseError(), "Parsing to document failure.");

	CCLOG("%s", "Parsing to document succeeded.");
	//是否含有data
	CC_ASSERT(document->IsObject() && document->HasMember("data"));

	const rapidjson::Value & dataString = (*document)["data"];
	//data内是否有question_answer
	CC_ASSERT(dataString.IsObject() && dataString.HasMember("question_answer"));

	//获取question_answer
	const rapidjson::Value & question_answer = dataString["question_answer"];
	//是否是数组
	CC_ASSERT(question_answer.IsArray());

	for (unsigned int i = 0; i < question_answer.Size(); i++) {

		const rapidjson::Value & temp = question_answer[i];

		CC_ASSERT(temp.HasMember("question") && temp.HasMember("answer"));

		const rapidjson::Value & question = temp["question"];
		CC_ASSERT(question.IsString());
		//CCLOG(StringUtility::UnicodeStrToUTF8Str((question.GetString())).c_str());
		questionVector.push_back(question.GetString());

		const rapidjson::Value & answer = temp["answer"];
		CC_ASSERT(answer.IsString()); 
		answerVector.push_back(answer.GetString());
	}
	return std::pair<std::vector<std::string>, std::vector<std::string>>(questionVector, answerVector);
}

void DataUtility::decodeInformation(std::string responseDataStr)
{
	responseDataStr = StringUtility::WStrToUTF8(StringUtility::decodeUnicode(responseDataStr));//对json字符串中的unicode编码进行转换

	CCLOG("%s", responseDataStr.c_str());

	document->Parse<0>(responseDataStr.c_str());
	//解析错误
	CCASSERT(!document->HasParseError(), "Parsing to document failure.");

	CCLOG("%s", "Parsing to document succeeded.");
	//是否含有data
	CC_ASSERT(document->IsObject() && document->HasMember("data"));

	const rapidjson::Value & dataString = (*document)["data"];
	
	//data内是否有
	CC_ASSERT(dataString.IsObject() 
		&& dataString.HasMember("id")
		&& dataString.HasMember("role")
		&& dataString.HasMember("speakable")
		&& dataString.HasMember("playable")
		&& dataString.HasMember("name"));

	//获取
	const rapidjson::Value & vID = dataString["id"];
	const rapidjson::Value & vRole = dataString["role"];
	const rapidjson::Value & vSpeakable = dataString["speakable"];
	const rapidjson::Value & vPlayable = dataString["playable"];
	const rapidjson::Value & vName = dataString["name"];


	//是否是数组
	CC_ASSERT(vID.IsInt()
		&& vRole.IsBool()
		&& vSpeakable.IsBool()
		&& vPlayable.IsBool()
		&& vName.IsString());

	Self::getInstance()->setPlayerID(vID.GetInt());
	Self::getInstance()->setRole(vRole.GetBool());
	Self::getInstance()->setSpeakable(vSpeakable.GetBool());
	Self::getInstance()->setPlayable(vPlayable.GetBool());
	Self::getInstance()->setName(vName.GetString());

}

void DataUtility::decodeStatus(std::string responseDataStr)
{
	responseDataStr = StringUtility::WStrToUTF8(StringUtility::decodeUnicode(responseDataStr));//对json字符串中的unicode编码进行转换

	CCLOG("%s", responseDataStr.c_str());

	document->Parse<0>(responseDataStr.c_str());
	//解析错误
	CCASSERT(!document->HasParseError(), "Parsing to document failure.");

	CCLOG("%s", "Parsing to document succeeded.");
	//是否含有data
	CC_ASSERT(document->IsObject() && document->HasMember("data"));

	const rapidjson::Value & dataString = (*document)["data"];

	//data内是否有
	CC_ASSERT(dataString.IsObject()
		&& dataString.HasMember("money")
		&& dataString.HasMember("experiense")
		&& dataString.HasMember("popularity")
		&& dataString.HasMember("beauty")
		&& dataString.HasMember("boyablity")
		&& dataString.HasMember("leadership")
		&& dataString.HasMember("action")
		&& dataString.HasMember("clothID")
		&& dataString.HasMember("cardID")
		&& dataString.HasMember("honor")
		&& dataString.HasMember("skillID")
		&& dataString.HasMember("cpID")
		&& dataString.HasMember("top"));

	//获取
	const rapidjson::Value & vMoney = dataString["money"];
	const rapidjson::Value & vExperiense = dataString["experiense"];
	const rapidjson::Value & vPopularity = dataString["popularity"];
	const rapidjson::Value & vBeauty = dataString["beauty"];
	const rapidjson::Value & vBoyablity = dataString["boyablity"];
	const rapidjson::Value & vLeadership = dataString["leadership"];
	const rapidjson::Value & vAction = dataString["action"];
	const rapidjson::Value & vClothID = dataString["clothID"];
	const rapidjson::Value & vCardID = dataString["cardID"];
	const rapidjson::Value & vHonor = dataString["honor"];
	const rapidjson::Value & vSkillID = dataString["skillID"];
	const rapidjson::Value & vCpID = dataString["cpID"];
	const rapidjson::Value & vTop = dataString["top"];
	/*
	//是否是数组
	CC_ASSERT(vID.IsInt()
		&& vRole.IsBool()
		&& vSpeakable.IsBool()
		&& vPlayable.IsBool()
		&& vName.IsString());

	Self::getInstance()->setPlayerID(vID.GetInt());
	Self::getInstance()->setRole(vRole.GetBool());
	Self::getInstance()->setSpeakable(vSpeakable.GetBool());
	Self::getInstance()->setPlayable(vPlayable.GetBool());
	Self::getInstance()->setName(vName.GetString());
	*/
}