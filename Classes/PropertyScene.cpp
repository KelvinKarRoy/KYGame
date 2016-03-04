//
//  PropertyScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/1.
//
//  人物属性页面，气死了 本来年前就解决了的 妈蛋的！

#include "PropertyScene.hpp"


PropertyScene::PropertyScene()
{
    setPlayer(Self::getInstance());
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
    
}

