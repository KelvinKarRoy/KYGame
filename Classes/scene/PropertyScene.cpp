//
//  PropertyScene.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/1.
//
//  人物属性页面，气死了 本来年前就解决了的 妈蛋的！

#include "PropertyScene.hpp"

#include "HomeScene.hpp"
#include "DialogLayer.h"
#include "FriendListScene.hpp"

#include "../model/Player.h"

Player PropertyScene::onePlayer;

PropertyScene::PropertyScene()
{
    player = &onePlayer;
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
    
    //从服务器读取用户信息
    HttpUtility::getInstance(this)->loadPlayerInformation(player->getPlayerID(), player);
    
    //重绘图像
    redraw();
    
    //获取加点按钮，绑定回调
    for(int i=1;i<=5;++i)
    {
        static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByTag(10000+i))
        ->addTouchEventListener(this,toucheventselector(PropertyScene::onAddClicked));
    }
    
    //获取加点确定和取消按钮，绑定回调
    static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_ok"))
    ->addTouchEventListener(this,toucheventselector(PropertyScene::onOKClicked));
    static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_cancel"))
    ->addTouchEventListener(this,toucheventselector(PropertyScene::onCancelClicked));
    
    
    
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
    if(cpid == 0) strcpy(temp,"cp：无");
        else std::sprintf(temp, "cp：%d",cpid);
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
    std::sprintf(temp, "攻/受：%s",cpid==0?"":(role?"攻":"受"));
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
    
    //升级进度条
    auto expLoadingBar = static_cast<cocos2d::ui::LoadingBar*>(rootNode->getChildByName("LoadingBar_exp"));
    expLoadingBar ->setPercent(player->getExpRate()*100);
    
}


//画雷达图
void PropertyScene::drawRadar()
{
    auto radar = static_cast<Layout*>(rootNode->getChildByName("Panel_radar"));
    
    if(radar->getChildByName("radar")!=nullptr) radar->removeChildByName("radar");
    
    // 填充的多边形
    CCDrawNode* frame = CCDrawNode::create();
    frame->setName("radar");
    radar->addChild(frame, 2);
    frame->setPosition(cocos2d::Vec2(0,0));
    
    //读取radar获得对应的值
    GCCsvHelper *csv = new GCCsvHelper();
    std::string path= FileUtils::getInstance()->getWritablePath();
    path+="db/radar.csv";
    csv->openAndResolveFile(path.c_str());
    
    //auto attributes = player->getAttributes();
    
    auto rate1 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_ACTION]+attributes[Player::ATTRIBUTE::EXP_ACTION], 1));
    auto rate2 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_BEAUTY]+attributes[Player::ATTRIBUTE::EXP_BEAUTY], 1));
    auto rate3 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_BOYABLITY]+attributes[Player::ATTRIBUTE::EXP_BOYABLITY], 1));
    auto rate4 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_LEADERSHIP]+attributes[Player::ATTRIBUTE::EXP_LEADERSHIP], 1));
    auto rate5 = atof(csv->getData(attributes[Player::ATTRIBUTE::BASE_POPULARITY]+attributes[Player::ATTRIBUTE::EXP_POPULARITY], 1));
    
    
    delete csv;
    
    CCPoint rectangle[5];
    rectangle[0] = ccp(210, 184+210*rate1);
    rectangle[1] = ccp(210+210*rate2, 184+68*rate2);
    rectangle[2] = ccp(210+130*rate3, 184-179*rate3);
    rectangle[3] = ccp(210-130*rate4, 184-179*rate4);
    rectangle[4] = ccp(210-210*rate5,184+68*rate5);
    
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
            if(Self::getInstance() == this->player)
                cocos2d::Director::getInstance()->replaceScene(HomeScene::createScene());//回到主页面
            else
                cocos2d::Director::getInstance()->replaceScene(FriendListScene::createScene());//回到好友页面
            break;
           
    }
    
}


//判断是否可以加点
bool PropertyScene::isAddable()
{
    //计算总基础属性
    int totalBaseProperty = 5+4*Self::getInstance()->getLevel();
    return (player == Self::getInstance())&&(attributes[Self::ATTRIBUTE::BASE_ACTION]
    +attributes[Self::ATTRIBUTE::BASE_BEAUTY]
    +attributes[Self::ATTRIBUTE::BASE_BOYABLITY]
    +attributes[Self::ATTRIBUTE::BASE_LEADERSHIP]
    +attributes[Self::ATTRIBUTE::BASE_POPULARITY]< totalBaseProperty);
    
}

//enable（参数为true）或unable（参数为false）加点按钮
void PropertyScene::enableAddButtons(bool isAddable)
{
    auto addActionButton = static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_addAction"));
    addActionButton->setEnabled(isAddable);
    addActionButton->setVisible(isAddable);
    
    auto addBeautyButton = static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_addBeauty"));
    addBeautyButton->setEnabled(isAddable);
    addBeautyButton->setVisible(isAddable);

    auto addBoyablityButton = static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_addBoyablity"));
    addBoyablityButton->setEnabled(isAddable);
    addBoyablityButton->setVisible(isAddable);

    auto addLeadershipButton = static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_addLeadership"));
    addLeadershipButton->setEnabled(isAddable);
    addLeadershipButton->setVisible(isAddable);

    auto addPopularityButton = static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_addPopularity"));
    addPopularityButton->setEnabled(isAddable);
    addPopularityButton->setVisible(isAddable);
    
    auto addOKButton = static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_ok"));
    addOKButton->setVisible((player == Self::getInstance()) && isPropertyChanged());
    addOKButton->setEnabled((player == Self::getInstance()) && isPropertyChanged());
    
    auto addCancelButton = static_cast<Button *>(rootNode->getChildByName("Panel_text")->getChildByName("Button_cancel"));
    addCancelButton->setVisible((player == Self::getInstance()) && isPropertyChanged());
    addCancelButton->setEnabled((player == Self::getInstance()) && isPropertyChanged());
    
}


//判断是否有加点
bool PropertyScene::isPropertyChanged()
{
    //原来的属性
    auto origin_attributes = player->getAttributes();
    return (origin_attributes[Self::ATTRIBUTE::BASE_ACTION] < attributes[Self::ATTRIBUTE::BASE_ACTION]
            ||origin_attributes[Self::ATTRIBUTE::BASE_BEAUTY] < attributes[Self::ATTRIBUTE::BASE_BEAUTY]
            ||origin_attributes[Self::ATTRIBUTE::BASE_BOYABLITY] < attributes[Self::ATTRIBUTE::BASE_BOYABLITY]
            ||origin_attributes[Self::ATTRIBUTE::BASE_LEADERSHIP] < attributes[Self::ATTRIBUTE::BASE_LEADERSHIP]
            ||origin_attributes[Self::ATTRIBUTE::BASE_POPULARITY] < attributes[Self::ATTRIBUTE::BASE_POPULARITY]);
    
}


//点击了加点按钮
void PropertyScene::onAddClicked(Ref* ref, TouchEventType type)
{
    if(type == TouchEventType::TOUCH_EVENT_ENDED)
    {
        int id = static_cast<Button*>(ref)->getTag();
        attributes[static_cast<Player::ATTRIBUTE>(id%10000)] +=1;
        fillText();
        drawRadar();
        enableAddButtons(isAddable());
    }
}


//点击了加点确定按钮
void PropertyScene::onOKClicked(Ref*, TouchEventType type)
{
    //将属性从attributes覆盖到player->getAttributes()
    player->setAttributes(attributes);
    //将Self->getAttributes上传服务器
    HttpUtility::getInstance(this)->saveStatus();
    //重绘图像
    redraw();
}

//点击了加点取消按钮
void PropertyScene::onCancelClicked(Ref*, TouchEventType type)
{
    //恢复Self上的状态
    attributes=player->getAttributes();
    //重绘图像
    redraw();
}

//重绘图像
void PropertyScene::redraw()
{
    //读取各属性值
    loadPeoperty();
    
    //填写属性
    fillText();
    
    //画雷达图
    drawRadar();
    
    //计算是否可以加点，enable或者unable加点按钮
    enableAddButtons((player==Self::getInstance())&&isAddable());
    
    fillText();
    drawRadar();
    enableAddButtons(isAddable());
}

//http请求成功后
void PropertyScene::onUpdateInfo()
{
    redraw();
}





