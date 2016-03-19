//
//  DataUtility.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/5.
//
//

#include "DataUtility.h"

#include "../model/Player.h"

#include "../scene/NoticeScene.hpp"

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


//Ω‚Œˆjson◊÷∑˚¥Æ
bool DataUtility::decodeFlagData(std::string flagInfo)
{
    
    document->Parse<0>(flagInfo.c_str());
    //Ω‚Œˆ¥ÌŒÛ
    CCASSERT(!document->HasParseError(), "Parsing to document failure.");
    
    CCLOG("%s", "Parsing to document succeeded.");
    // «∑Ò∫¨”–data
    CC_ASSERT(document->IsObject() && document->HasMember("data"));
    
    const rapidjson::Value & dataString = (*document)["data"];
    //dataƒ⁄ «∑Ò”–flag
    CC_ASSERT(dataString.IsObject() && dataString.HasMember("flag"));
    
    //ªÒ»°flag
    const rapidjson::Value & flag = dataString["flag"];
    
    CC_ASSERT(flag.IsBool());
    
    return flag.GetBool();
}


std::pair<std::vector<std::string>, std::vector<std::string>>
DataUtility::decodeQuestionData(std::string questionInfo)//Ω‚ŒˆŒ Ã‚∫Õ¥∞∏µƒjson◊÷∑˚¥Æ
{
    std::vector<std::string> questionVector;
    std::vector<std::string> answerVector;
    
    questionInfo = StringUtility::WStrToUTF8(StringUtility::decodeUnicode(questionInfo));//∂‘json◊÷∑˚¥Æ÷–µƒunicode±‡¬ÎΩ¯––◊™ªª
    
    CCLOG("%s",questionInfo.c_str());
    
    document->Parse<0>(questionInfo.c_str());
    //Ω‚Œˆ¥ÌŒÛ
    CCASSERT(!document->HasParseError(), "Parsing to document failure.");
    
    CCLOG("%s", "Parsing to document succeeded.");
    // «∑Ò∫¨”–data
    CC_ASSERT(document->IsObject() && document->HasMember("data"));
    
    const rapidjson::Value & dataString = (*document)["data"];
    //dataƒ⁄ «∑Ò”–question_answer
    CC_ASSERT(dataString.IsObject() && dataString.HasMember("question_answer"));
    
    //ªÒ»°question_answer
    const rapidjson::Value & question_answer = dataString["question_answer"];
    // «∑Ò « ˝◊È
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
    responseDataStr = StringUtility::WStrToUTF8(StringUtility::decodeUnicode(responseDataStr));//∂‘json◊÷∑˚¥Æ÷–µƒunicode±‡¬ÎΩ¯––◊™ªª
    
    CCLOG("%s", responseDataStr.c_str());
    
    document->Parse<0>(responseDataStr.c_str());
    //Ω‚Œˆ¥ÌŒÛ
    CCASSERT(!document->HasParseError(), "Parsing to document failure.");
    
    CCLOG("%s", "Parsing to document succeeded.");
    // «∑Ò∫¨”–data
    CC_ASSERT(document->IsObject() && document->HasMember("data"));
    
    const rapidjson::Value & dataString = (*document)["data"];
    
    //dataƒ⁄ «∑Ò”–
    CC_ASSERT(dataString.IsObject()
              && dataString.HasMember("role")
              && dataString.HasMember("speakable")
              && dataString.HasMember("playable")
              && dataString.HasMember("name")
              
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
    
    //ªÒ»°
    const rapidjson::Value & vRole = dataString["role"];
    const rapidjson::Value & vSpeakable = dataString["speakable"];
    const rapidjson::Value & vPlayable = dataString["playable"];
    const rapidjson::Value & vName = dataString["name"];
    
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
    
    // «∑Ò « ˝◊È
    CC_ASSERT( vRole.IsInt()
              && vSpeakable.IsInt()
              && vPlayable.IsInt()
              && vName.IsString()
              
              && vMoney.IsInt()
              && vExperiense.IsInt()
              && vPopularity.IsInt()
              && vBeauty.IsInt()
              && vBoyablity.IsInt()
              && vLeadership.IsInt()
              && vAction.IsInt()
              && vClothID.IsInt()
              && vCardID.IsInt()
              && vHonor.IsInt()
              && vSkillID.IsArray()
              && vCpID.IsInt()
              && vTop.IsInt()
              );
    
    HttpUtility::getInstance()->getPlayer()->setRole(vRole.GetInt());
    HttpUtility::getInstance()->getPlayer()->setSpeakable(vSpeakable.GetInt());
    HttpUtility::getInstance()->getPlayer()->setPlayable(vPlayable.GetInt());
    HttpUtility::getInstance()->getPlayer()->setName(vName.GetString());
    
    HttpUtility::getInstance()->getPlayer()->setMoney(vMoney.GetInt());
    HttpUtility::getInstance()->getPlayer()->setExp(vExperiense.GetInt());
    
    std::map<Player::ATTRIBUTE,int> attributes;
    
    attributes[Player::ATTRIBUTE::BASE_ACTION] = vAction.GetInt();
    attributes[Player::ATTRIBUTE::BASE_BEAUTY] = vBeauty.GetInt();
    attributes[Player::ATTRIBUTE::BASE_BOYABLITY] = vBoyablity.GetInt();
    attributes[Player::ATTRIBUTE::BASE_LEADERSHIP] = vLeadership.GetInt();
    attributes[Player::ATTRIBUTE::BASE_POPULARITY] = vPopularity.GetInt();
    
    HttpUtility::getInstance()->getPlayer()->setAttributes(attributes);
    
    HttpUtility::getInstance()->getPlayer()->setClothID(vClothID.GetInt());
    HttpUtility::getInstance()->getPlayer()->setCardID(vCardID.GetInt());
    HttpUtility::getInstance()->getPlayer()->setHonor(vHonor.GetInt());
    
    vector<int> vecSkills;
    
    for (int i = 0; i<vSkillID.Size(); ++i) {
        vecSkills.push_back(vSkillID[i].GetInt());
    }
    HttpUtility::getInstance()->getPlayer()->setSkillsID(vecSkills);
    HttpUtility::getInstance()->getPlayer()->setCpID(vCpID.GetInt());
    HttpUtility::getInstance()->getPlayer()->setTop(vTop.GetInt());
    
    HttpUtility::getInstance()->getPlayer()->expTolevel();//经验值转等级
    
    //最后要将衣服的附加属性加上去
}

//解析玩家ID
void DataUtility::decodePlayerID(std::string responseDataStr)
{
    responseDataStr = StringUtility::WStrToUTF8(StringUtility::decodeUnicode(responseDataStr));//∂‘json◊÷∑˚¥Æ÷–µƒunicode±‡¬ÎΩ¯––◊™ªª
    
    CCLOG("%s", responseDataStr.c_str());
    
    document->Parse<0>(responseDataStr.c_str());
    //Ω‚Œˆ¥ÌŒÛ
    CCASSERT(!document->HasParseError(), "Parsing to document failure.");
    
    CCLOG("%s", "Parsing to document succeeded.");
    // «∑Ò∫¨”–data
    CC_ASSERT(document->IsObject() && document->HasMember("data"));
    
    const rapidjson::Value & dataString = (*document)["data"];
    
    CC_ASSERT(dataString.IsObject() && dataString.HasMember("id"));
    
    const rapidjson::Value & vID = dataString["id"];
    
    CC_ASSERT(vID.IsInt());
    
    HttpUtility::getInstance()->getPlayer()->setPlayerID(vID.GetInt());
    
    
}


//解析公告
void DataUtility::decodeNotice(std::string responseDataStr)
{
    responseDataStr = StringUtility::WStrToUTF8(StringUtility::decodeUnicode(responseDataStr));//将json数据转成utf编码
    
    CCLOG("%s", responseDataStr.c_str());
    
    document->Parse<0>(responseDataStr.c_str());
    //是否解析错误
    CCASSERT(!document->HasParseError(), "Parsing to document failure.");
    
    CCLOG("%s", "Parsing to document succeeded.");
    //是否有成员“data”
    CC_ASSERT(document->IsObject() && document->HasMember("data"));
    
    const rapidjson::Value & dataString = (*document)["data"];
    
    CC_ASSERT(dataString.IsObject() && dataString.HasMember("notice"));
    
    const rapidjson::Value & noticeVector = dataString["notice"];
    
    CC_ASSERT(noticeVector.IsArray());
    
    std::vector<NoticeScene::Notice> notices;
    
    for (unsigned int i = 0; i < noticeVector.Size(); i++) {
        
        const rapidjson::Value & temp = noticeVector[i];
        
        CC_ASSERT(temp.HasMember("title") && temp.HasMember("text") && temp.HasMember("time"));
        
        const rapidjson::Value & vTitle = temp["title"];
        const rapidjson::Value & vText = temp["text"];
        const rapidjson::Value & vTime = temp["time"];
        
        CC_ASSERT(vTitle.IsString());
        CC_ASSERT(vText.IsString());
        CC_ASSERT(vTime.IsString());
        
        std::string title=vTitle.GetString(),text=vText.GetString(),time=vTime.GetString();
        
        NoticeScene::Notice notice;
        notice.m_title=title;
        notice.m_text=text;
        notice.m_time=time;
        
        notices.push_back(notice);
        
    }
    
    static_cast<NoticeScene*>(HttpUtility::getInstance()->getCallerLayer())->setNotice(notices);
    
}

