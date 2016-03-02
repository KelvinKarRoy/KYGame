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
    //rootNode = CSLoader::createNode("csb/RegeditScene.csb");
    
    sqlite3 *pDB = NULL;
    char * errMsg = NULL;
    
    //int rc = sqlite3_open("KYGame", &pDB);
    
    return true;
}
