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
    inline int getRowLength() { return data.size(); }
    
private:
    const std::string m_seperator;
    std::vector<std::vector<std::string> > data;
    
    //cols length
    int m_colLength;
    
    
    
};

#endif /* defined(__Cell__GCCsvHelper__) */
#endif /* GCCsvHelper_hpp */
