//
//  WaitLayer.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/5.
//
//

#include "WaitLayer.hpp"



WaitLayer::WaitLayer()
{
}


WaitLayer::~WaitLayer()
{
}


cocos2d::Scene* WaitLayer::createScene()
{
    auto scene = cocos2d::Scene::create();
    
    auto layer = WaitLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool WaitLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    /*获取大小*/
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    /**************读取UI***************/
    rootNode = cocos2d::CSLoader::createNode("csb/WaitLayer.csb");
    
    //设置UI大小
    rootNode->setScale(visibleSize.width / rootNode->getContentSize().width, visibleSize.height / rootNode->getContentSize().height);
    
    //加载动画
    auto action = cocos2d::CSLoader::createTimeline("csb/WaitLayer.csb");
    rootNode->runAction(action);
    action->gotoFrameAndPlay(0, 40, true);
    
    addChild(rootNode);
    
    //吞噬下层事件
    auto callback = [](cocos2d::Touch * ,cocos2d::Event *)
    {
        return true;
    };
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = callback;
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

    
    
    return true;
}



