//
//  GCCsvHelper.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/4.
//
//

#include "GCCsvHelper.hpp"

GCCsvHelper::GCCsvHelper()
:m_seperator(",")
,m_colLength(0)
{
    
}

GCCsvHelper::~GCCsvHelper()
{
    
}

#pragma region reselove the content begin...

bool GCCsvHelper::openAndResolveFile(const char *fileName)
{
    std::string pathKey = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);
    unsigned char* pBuffer = NULL;
    ssize_t bufferSize = 0;
    log("%s",pathKey.c_str());
    pBuffer = CCFileUtils::sharedFileUtils()->getFileData(pathKey.c_str(), "r", &bufferSize);
    
    std::string tmpStr = (char*)pBuffer;
    std::string fileContent = tmpStr.substr(0, bufferSize);
    
    char temp[10000];
    strcpy(temp, fileContent.c_str());
    
    char* line;
    
    //std::vector<std::string> line;
    line = strtok(temp, "\r");
    
    while(line!=NULL) {
        std::vector<std::string> vline;
        m_colLength = 0;
        int j=0;
        for(int i=0;i<strlen(line);++i)
        {
            if(line[i]==';')
            {
                vline.push_back(std::string(line,j,i-j));
                j=i+1;
                m_colLength++;
            }
            if(i==strlen(line)-1)
            {
                vline.push_back(std::string(line,j,i-j+1));
                m_colLength++;
            }
            
        }
        data.push_back(vline);
        line = strtok(NULL,"\r");
    }
    
    return true;
}



#pragma region end.

///////search data
const char *GCCsvHelper::getData(unsigned int rowIndex, unsigned int colIndex)
{
    if (rowIndex >= getRowLength() || colIndex >= getColLength()) {
        return "";
    }
    
    if (colIndex >= data[rowIndex].size()) {
        return "";
    }
    
    return data[rowIndex][colIndex].c_str();
}