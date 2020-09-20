

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
   /* jianpan yidong*/
    //virtual void onKeyPressed(EventKeyboard::KeyCode keycode, Event* event);
    //virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event);
    //
    /*virtual void Move();*/
    CREATE_FUNC(HelloWorld);
    std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
};

#endif // __HELLOWORLD_SCENE_H__
