#pragma once
#ifndef __CREATE_ANIMATE_H__
#define __CREATE_ANIMATE_H__

#include "cocos2d.h"

USING_NS_CC;

class CreateAnimate
{
public:
    static cocos2d::Animate* create(const std::string filePath, int nameLen, int picNum, const char* picName, float frequency);
};

#endif 
