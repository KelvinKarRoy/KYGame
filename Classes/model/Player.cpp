#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}


void Player::expTolevel()
{//经验值转化为等级
    this->setLevel(expTolevel(this->getExp()));
}


int Player::expTolevel(int exp)
{
    //经验值转化为等级
    GCCsvHelper *csv = new GCCsvHelper();
    std::string path= FileUtils::getInstance()->getWritablePath();
    log("%s",path.c_str());
    path+="db/exp.csv";
    csv->openAndResolveFile(path.c_str());
    
    int level;
    for (int i = 0; i < csv->getRowLength(); ++i) {
        if(atoi(csv->getData(i, 1))>exp)
        {
            level = i;
            break;
        }
    }
    delete csv;
    return level;
}


float Player::getExpRate()
{//经验值升级所需比例
    GCCsvHelper *csv = new GCCsvHelper();
    std::string path= FileUtils::getInstance()->getWritablePath();
    log("%s",path.c_str());
    path+="db/exp.csv";
    csv->openAndResolveFile(path.c_str());
    
    
    for (int i = 0; i < csv->getRowLength(); ++i) {
        if(atoi(csv->getData(i, 1)) > this->exp)
        {
            
            double rate = ((double)this->exp - atoi(csv->getData(i-1, 1))) / (atoi(csv->getData(i, 1)) - atoi(csv->getData(i-1, 1)));
            delete csv;
            return rate;
        }
    }
    delete csv;
    return 1.0;
}
