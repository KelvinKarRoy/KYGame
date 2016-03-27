//
//  FoodScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/27.
//
//

#include "FoodScene.hpp"

#include "HomeScene.hpp"

#include "../utility/HttpUtility.h"
#include "../utility/GCCsvHelper.hpp"

#include "../model/Self.h"

Player FoodScene::onePlayer;

FoodScene::FoodScene()
{
    player = &onePlayer;
}

FoodScene::~FoodScene()
{
}


FoodScene* FoodScene::create(int playerID)
{
    FoodScene *pRet = new(std::nothrow) FoodScene();
    if(Self::getInstance()->getPlayerID() == playerID)
    {
        pRet->setPlayer(Self::getInstance());
    }else
    {
        pRet->setPlayer(&onePlayer);
        onePlayer.setPlayerID(playerID);
    }
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

Scene* FoodScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = FoodScene::create();
    
    scene->addChild(layer);
    
    return scene;
    
}

bool FoodScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    /*获取屏幕大小*/
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    /**************加载UI***************/
    rootNode = cocos2d::CSLoader::createNode("csb/FoodScene.csb");
    
    //调整UI大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    this->addChild(rootNode);
    
    auto backButton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_back"));
    
    backButton->addTouchEventListener(this,toucheventselector(FoodScene::clickBackCallback));
    
    drawFoods();
    
    HttpUtility::getInstance(this)->loadPlayerInformation(player->getPlayerID(), player);
    
    
    return true;
}

//加载自己信息回调
void FoodScene::onUpdateInfo()
{
    char temp[120];
    static_cast<LoadingBar*>(rootNode->getChildByName("Panel_info")->getChildByName("LoadingBar_PVRate"))
    ->setPercent(player->getVP());
    
    sprintf(temp,"%d",player->getVP());
    static_cast<Text*>(rootNode->getChildByName("Panel_info")->getChildByName("Text_VP"))->setString(temp);
    
    sprintf(temp,"蟹圆币: %d",player->getMoney());
    static_cast<Text*>(rootNode->getChildByName("Panel_info")->getChildByName("Text_money"))->setString(temp);
    
    sprintf(temp,"荣誉值: %d",player->getHonor());
    static_cast<Text*>(rootNode->getChildByName("Panel_info")->getChildByName("Text_honor"))->setString(temp);
}


void FoodScene::clickBackCallback(Ref*, TouchEventType type)
{
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
        break;
        case TouchEventType::TOUCH_EVENT_CANCELED:
        break;
        case TouchEventType::TOUCH_EVENT_MOVED:
        break;
        case TouchEventType::TOUCH_EVENT_ENDED:
        Director::getInstance()->replaceScene(HomeScene::createScene());//切换到主页面
        break;
        
    }
}



void FoodScene::drawFoods()
{
    auto foodList = static_cast<ListView*>(rootNode->getChildByName("ListView_food"));
    
    Size listSize = foodList->getContentSize();
    
    //读取food获得对应的值
    GCCsvHelper *csv = new GCCsvHelper();
    std::string path= FileUtils::getInstance()->getWritablePath();
    path+="db/food.csv";
    csv->openAndResolveFile(path.c_str());
    
    for(int i=1;i < csv->getRowLength();++i)
    {
        Food food;
        food.m_id = atoi(csv->getData(i, 0));
        food.m_name = csv->getData(i, 1);
        food.m_brief = csv->getData(i, 2);
        food.m_vp = atoi(csv->getData(i, 3));
        food.m_exp = atoi(csv->getData(i, 4));
        food.m_money = atoi(csv->getData(i, 5));
        food.m_honor = atoi(csv->getData(i, 6));
        
        foods.push_back(food);
        
        auto foodPanel = cocos2d::ui::Layout::create();
        
        foodPanel->setContentSize(Size(listSize.width,listSize.height/3));
        
        log("%s",food.m_name.c_str());
        
        char temp[30];
        sprintf(temp, "food%d.png",i);
        
        auto foodSprite = Sprite::create(temp);
        
        foodSprite->setAnchorPoint(Point(0,0.5));
        foodSprite->setPosition(listSize.width/10, listSize.height/3/2);
        foodSprite->setScale(listSize.height/4/foodSprite->getContentSize().width,listSize.height/4/foodSprite->getContentSize().height);
        foodPanel->addChild(foodSprite);
        
        auto nameText = Text::create(food.m_name.c_str(), "wending.TTF", 60);
        nameText->cocos2d::Node::setPosition(listSize.height/4 + listSize.width/4,listSize.height/3/7*6);
        nameText->setAnchorPoint(Point(0,0.5));
        foodPanel->addChild(nameText);
        
        sprintf(temp,"饥饿值: %d",food.m_vp);
        auto vpText = Text::create(temp, "wending.TTF", 42);
        vpText->cocos2d::Node::setPosition(listSize.height/4 + listSize.width/4,listSize.height/3/7*4);
        vpText->setAnchorPoint(Point(0,0.5));
        foodPanel->addChild(vpText);
        
        auto briefText = Text::create(food.m_brief.c_str(), "wending.TTF", 42);
        briefText->cocos2d::Node::setPosition(listSize.height/4 + listSize.width/4,listSize.height/3/7*5);
        briefText->setAnchorPoint(Point(0,0.5));
        foodPanel->addChild(briefText);
        
        sprintf(temp,"经验值: %d",food.m_exp);
        auto expText = Text::create(temp, "wending.TTF", 42);
        expText->cocos2d::Node::setPosition(listSize.height/4 + listSize.width/4,listSize.height/3/7*3);
        expText->setAnchorPoint(Point(0,0.5));
        foodPanel->addChild(expText);
        
        if(food.m_money>0) sprintf(temp,"花费: %d",food.m_money);
        else strcpy(temp, "非卖品！");
        auto moneyText = Text::create(temp, "wending.TTF", 42);
        moneyText->cocos2d::Node::setPosition(listSize.height/4 + listSize.width/4,listSize.height/3/7*1);
        moneyText->setAnchorPoint(Point(0,0.5));
        foodPanel->addChild(moneyText);
        
        sprintf(temp,"荣誉值: %d",food.m_honor);
        auto honorText = Text::create(temp, "wending.TTF", 42);
        honorText->setAnchorPoint(Point(0,0.5));
        honorText->cocos2d::Node::setPosition(listSize.height/4 + listSize.width/4,listSize.height/3/7*2);
        foodPanel->addChild(honorText);
        
        foodList->addChild(foodPanel);
        
        
    }
    delete csv;
    
    
    
}

