//
//  Promptable.cpp
//  KYGame
//
//  Created by Kelvin on 16/3/16.
//
//

#include "Promptable.hpp"
#include "../scene/DialogLayer.h"

void Promptable::promptDialogBox(std::string str)
{
    childLayer = DialogLayer::create();
    ((DialogLayer*)childLayer)->setText(str);//弹出对话框
    this->addChild((DialogLayer*)childLayer);
    utility::setEnable(false, this);
}
