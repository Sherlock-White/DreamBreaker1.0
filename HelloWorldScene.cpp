#include "HelloWorldScene.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{

    if ( !Scene::init() )
    {
        return false;
    }
    auto map = TMXTiledMap::create("homeMap.tmx");
    addChild(map, 0);

    auto visibleSize = Director::getInstance()->getVisibleSize();  //get the size of screen
    Vec2 origin = Director::getInstance()->getVisibleOrigin();//get origin information? get the zuobiao of this black blank!

    auto hero = Sprite::create("Doctor.png");
    hero->setPosition(Vec2(visibleSize.width/2+origin.x, visibleSize.height / 2+origin.y ));
    this->addChild(hero, 0);

    //监听器
    auto MoveListener = EventListenerKeyboard::create();

    MoveListener->onKeyPressed = [=](EventKeyboard::KeyCode code, Event* e)
    {
        keys[code] = true;
    };

    MoveListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        keys[keyCode] = false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(MoveListener, this);
    hero->runAction(MoveBy::create(1, Point(0, 100)));
   /* Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(MoveListener, hero);*/
    {
        if (keys[EventKeyboard::KeyCode::KEY_W])
        {
            hero->runAction(MoveBy::create(1, Point(0,100)));
        }
        if (keys[EventKeyboard::KeyCode::KEY_A])
        {
            hero->runAction(MoveBy::create(1, Point(-100, 0)));

        }
        if (keys[EventKeyboard::KeyCode::KEY_S])
        {
            hero->runAction(MoveBy::create(1, Point(0, -100)));

        }
        if (keys[EventKeyboard::KeyCode::KEY_D])
        {
            hero->runAction(MoveBy::create(1, Point(100, 0)));

        }
    };
    return true;
}





//void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keycode, Event* event)
//{
//    if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
//        CCLOG("按下了：上方向键");
//    }
//    else if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
//        CCLOG("按下了：左方向键");
//    }
//    else if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
//        CCLOG("按下了：右方向键");
//    }
//    else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
//        CCLOG("按下了：下方向键");
//    }
//
//}

