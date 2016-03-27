//
//  LoadInfoable.hpp
//  KYGame
//
//  Created by Kelvin on 16/3/27.
//
//  需要加载玩家信息的页面

#ifndef LoadInfoable_hpp
#define LoadInfoable_hpp

class LoadInfoable
{
public:
    virtual void onUpdateInfo() = 0;//http请求成功后更新
    
    LoadInfoable() {};
    virtual ~LoadInfoable() {};
};


#endif /* LoadInfoable_hpp */
