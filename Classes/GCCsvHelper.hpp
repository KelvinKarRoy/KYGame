//
//  GCCsvHelper.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/4.
//
//

#ifndef GCCsvHelper_hpp
#define GCCsvHelper_hpp

#ifndef __Cell__GCCsvHelper__
#define __Cell__GCCsvHelper__

#include <iostream>
#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class GCCsvHelper
{
public:
    GCCsvHelper();
    ~GCCsvHelper();
    
    bool openAndResolveFile(const char *fileName);
    
    const char *getData(unsigned int rowIndex, unsigned int colIndex);
    
    inline int getColLength() { return m_colLength; }
    inline int getRowLength() {    return data.size(); }
    
private:
    const std::string m_seperator;
    std::vector<std::vector<std::string> > data;
    
    //cols length
    int m_colLength;
    
    void rowSplit(std::vector<std::string> &rows, const std::string &content, const char &rowSeperator);
    void fieldSplit(std::vector<std::string> &fields, std::string line);
    
    //获取带引号的字段
    int getFieldWithQuoted(const std::string &line, std::string& field, int index);
    
    //获取无引号的字段
    int getFieldNoQuoted(const std::string &line, std::string &field, int index);
};

#endif /* defined(__Cell__GCCsvHelper__) */
#endif /* GCCsvHelper_hpp */
