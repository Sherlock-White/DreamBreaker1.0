#include "createAnimate.h"

USING_NS_CC;

//if you want to create an animate,you should write like this:
//auto animate = CreateAnimate::create("saberMove.plist", 20, 7, "saberMove%04d", 0.13f);
//sprite->runAction(RepeatForever::create(animate));
//---------------------------------------------------------------------------------------
//nameLen--the length of the picture name, such as the length of "saberMove0000" is 13
//filePath--plist file's name,including its path, such as "Hero/saberMove.plist" 
//picNum--the number of the picture in this plist file
//picName--be used in the function sprintf(),and you should write as "saberMove%04d"
//frequency--the frequency of the animation,you should write as 1.0f
Animate* CreateAnimate::create(const std::string filePath,int nameLen,int picNum,const char* picName, float frequency) {
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile(filePath);
    Vector<SpriteFrame*>vec;
    char* name = new char[nameLen];
    memset(name, 0, nameLen);
    for (int i = 0; i < picNum; i++) {
        sprintf(name, picName, i);
        vec.pushBack(cache->getSpriteFrameByName(name));
    } 
    delete[]name;//delete
    Animation* animation = Animation::createWithSpriteFrames(vec, frequency);
    Animate* animate = Animate::create(animation);
    return animate;
}
