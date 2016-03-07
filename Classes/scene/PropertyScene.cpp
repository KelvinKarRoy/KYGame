//
//  PropertyScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/1.
//
//  人物属性页面，气死了 本来年前就解决了的 妈蛋的！

#include "PropertyScene.hpp"

#include "LogInScene.h"

#include "../model/Player.h"


PropertyScene::PropertyScene()
{
    Player* player = Self::getInstance();
    setPlayer(player);
}


PropertyScene::~PropertyScene()
{
}


Scene* PropertyScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = PropertyScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool PropertyScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    /*获取大小*/
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /**************读取UI***************/
    rootNode = CSLoader::createNode("csb/PropertyScene.csb");
    
    //设置UI大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    addChild(rootNode);
    
    //绑定返回按钮回调
    auto backButton = static_cast<Button*>(rootNode->getChildByName("Button_back"));
    
    backButton->addTouchEventListener(this,toucheventselector(PropertyScene::onBackClicked));
    
    //读取各属性值
    loadPeoperty();
    
    //填写属性
    fillText();
    
    //画雷达图
    drawRadar();
    
    return true;
}



//读取各属性值
void PropertyScene::loadPeoperty()
{
    //读取各属性值
    attributes = player->getAttributes();//各个属性
    name = player->getName();
    id = player->getPlayerID();
    cpid = player->getCpID();
    clothid = player->getClothID();
    exp = player->getExp();
    honor = player->getHonor();
    level = player->getLevel();
    money = player->getMoney();
    role = player->getRole();
    top = player->getTop();
}

//填写属性
void PropertyScene::fillText()
{
    //填写昵称和id
    char temp[40];
    std::sprintf(temp, "昵称：%s(%d)",name.c_str(),id);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_name"))->setString(temp);
    
    //cpID
    std::sprintf(temp, "cp：%d",cpid);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_cpid"))->setString(temp);
    
    //等级
    std::sprintf(temp, "等级：%d",level);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_level"))->setString(temp);
    
    //荣誉值
    std::sprintf(temp, "荣誉值：%d",honor);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_honor"))->setString(temp);
    
    //角色
    std::sprintf(temp, "凯/源：%s",role?"凯":"源");
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_role"))->setString(temp);
    
    //攻受
    std::sprintf(temp, "攻/受：%s",role?"攻":"受");
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_top"))->setString(temp);
    
    //各个属性
    std::sprintf(temp, "演技：%d",attributes[Player::ATTRIBUTE::BASE_ACTION]+attributes[Player::ATTRIBUTE::EXP_ACTION]);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_action"))->setString(temp);
    
    std::sprintf(temp, "人气：%d",attributes[Player::ATTRIBUTE::BASE_POPULARITY]+attributes[Player::ATTRIBUTE::EXP_POPULARITY]);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_popularity"))->setString(temp);
    
    std::sprintf(temp, "颜值：%d",attributes[Player::ATTRIBUTE::BASE_BEAUTY]+attributes[Player::ATTRIBUTE::EXP_BEAUTY]);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_beauty"))->setString(temp);
    
    std::sprintf(temp, "男友力：%d",attributes[Player::ATTRIBUTE::BASE_BOYABLITY]+attributes[Player::ATTRIBUTE::EXP_BOYABLITY]);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_boyablity"))->setString(temp);
    
    std::sprintf(temp, "领导力：%d",attributes[Player::ATTRIBUTE::BASE_LEADERSHIP]+attributes[Player::ATTRIBUTE::EXP_LEADERSHIP]);
    static_cast<Text*>(rootNode->getChildByName("Panel_text")->getChildByName("Text_leadership"))->setString(temp);
}


//画雷达图
void PropertyScene::drawRadar()
{
    auto radar = static_cast<Layout*>(rootNode->getChildByName("Panel_radar"));
    
    // 填充的多边形
    CCDrawNode* frame = CCDrawNode::create();
    radar->addChild(frame, 2);
    frame->setPosition(cocos2d::Vec2(0,0));
    
    //读取radar获得对应的值
    GCCsvHelper *csv = new GCCsvHelper();
    std::string path= FileUtils::getInstance()->getWritablePath();
    path+="db/radar.csv";
    csv->openAndResolveFile(path.c_str());
    
    auto attributes = player->getAttributes();
    
    auto rate1 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_ACTION]+attributes[Player::ATTRIBUTE::EXP_ACTION], 1));
    auto rate2 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_BEAUTY]+attributes[Player::ATTRIBUTE::EXP_BEAUTY], 1));
    auto rate3 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_BOYABLITY]+attributes[Player::ATTRIBUTE::EXP_BOYABLITY], 1));
    auto rate4 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_LEADERSHIP]+attributes[Player::ATTRIBUTE::EXP_LEADERSHIP], 1));
    auto rate5 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_POPULARITY]+attributes[Player::ATTRIBUTE::EXP_POPULARITY], 1));
    
    
    delete csv;
    
    CCPoint rectangle[5];
    rectangle[0] = ccp(210, 179+210*rate1);
    rectangle[1] = ccp(210+210*rate2, 179+68*rate2);
    rectangle[2] = ccp(210+130*rate3, 179-179*rate3);
    rectangle[3] = ccp(210-130*rate4, 179-179*rate4);
    rectangle[4] = ccp(210-210*rate5,179+68*rate5);
    
    if(player->getRole())
    {//凯
        frame->drawPolygon(rectangle, 5, ccc4f(0, 0.5, 0.7, 0.3), 1, ccc4f(0, 0.5, 0.7, 1));
    }else
    {//源
        frame->drawPolygon(rectangle, 5, ccc4f(0, 0.7, 0.5, 0.3), 1, ccc4f(0, 0.7, 0.5, 1));
    }
    
}


//返回按钮的回调函数
void PropertyScene::onBackClicked(Ref*, TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_MOVED:
            break;
        case TouchEventType::TOUCH_EVENT_BEGAN:
            break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            Scene* scene = LogInScene::createScene();
            cocos2d::Director::getInstance()->replaceScene(scene);//回到登录页面
            break;
           
    }
    
}

