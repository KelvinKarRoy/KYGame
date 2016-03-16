#include "AppDelegate.h"
//#include "HelloWorldScene.h"
#include "scene/HomeScene.hpp"
#include "scene/LogInScene.h"
#include "scene/AboutScene.h"
#include "scene/AuthenticationScene.h"
#include "scene/RegeditScene.h"
#include "scene/PropertyScene.hpp"
#include "scene/WaitLayer.hpp"

#include <sys/stat.h>//系统库
#include <dirent.h>

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(2208, 1242);
//static cocos2d::Size designResolutionSize = cocos2d::Size(1024, 576);

static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("KYGame", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("KYGame");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    //director->setAnimationInterval(1.0 / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    Size frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    /*if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }*/
        //director->setContentScaleFactor(MIN(designResolutionSize.height/frameSize.height, designResolutionSize.width/frameSize.width));
    //log("%f",MIN(designResolutionSize.height/frameSize.height, designResolutionSize.width/frameSize.width));
    log("%f:%f",frameSize.height,frameSize.width);
    register_all_packages();
    
    //iOS将本地数据库移到沙盒
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    createDownLoadUrl("db/");
    if(!isFileExist("db/radar.csv"))    copyFile("db/radar.csv");
    if(!isFileExist("db/exp.csv"))    copyFile("db/exp.csv");
    if(!isFileExist("db/KYGame.db"))    copyFile("db/KYGame.db");
    
#endif

    // create a scene. it's an autorelease object
	auto scene = RegeditScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    
}


//创建数据库目录
std::string AppDelegate::createDownLoadUrl(std::string path){
    std::string pathToSave;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    pathToSave = CCFileUtils::sharedFileUtils()->getWritablePath();
    pathToSave += path;
    
    // Create the folder if it doesn't exist
    DIR *pDir = NULL;
    
    pDir = opendir (pathToSave.c_str());
    if (!pDir)
    {
        mkdir(pathToSave.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
    }
#else
    if ((GetFileAttributesA(pathToSave.c_str())) == INVALID_FILE_ATTRIBUTES)
    {
        CreateDirectoryA(pathToSave.c_str(), 0);
    }
#endif
    return pathToSave;
    
}

//拷贝文件
bool AppDelegate::copyFile(const std::string& filename)
{
    // 资源路径
    std::string sourcePath = FileUtils::getInstance()->fullPathForFilename(filename);
    Data data = FileUtils::getInstance()->getDataFromFile(sourcePath);
    
    // 可写路径
    std::string destPath = FileUtils::getInstance()->getWritablePath() + filename;
    FILE *fp = fopen(destPath.c_str(), "w+");
    if (fp)
    {
        size_t size = fwrite(data.getBytes(), sizeof(unsigned char), data.getSize(), fp);
        fclose(fp);
        
        if (size > 0)
        {
            return true;
        }
    }
    CCLOG("copy file %s failed.", filename.c_str());
    return false;
}

//文件是否存在
bool AppDelegate::isFileExist(const char* pFileName)
{
    if( !pFileName ) return false;
    //strFilePathName is :/data/data/ + package name
    std::string filePath = FileUtils::getInstance()->getWritablePath() + pFileName;

    FILE *fp = fopen(filePath.c_str(),"r");
    if(fp)
    {
        fclose(fp);
        return true;
    }
    return false;
}

