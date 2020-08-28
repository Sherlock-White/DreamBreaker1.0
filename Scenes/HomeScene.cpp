/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "Scenes/HomeScene.h"
#include "SimpleAudioEngine.h"
#include "Functions/createAnimate.h"
#include "Constant.h"

USING_NS_CC;

Scene* Home::createScene()
{
    return Home::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HomeScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Home::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    //map
    auto map = TMXTiledMap::create("councelingRoomMap.tmx");
    addChild(map, 0, HOME_MAP);
    //sofa
    auto sofa = Sprite::create("councelingRoom/counselingRoom_sofa.png");
    float sofaX = FRAME_SIZE_X*0.57;
    float sofaY = FRAME_SIZE_Y*0.4;
    sofa->setAnchorPoint(Vec2(0, 0));
    sofa->setPosition(Vec2(sofaX, sofaY));
    addChild(sofa, 1);
    //flower
    auto flower = Sprite::create("councelingRoom/counselingRoom_flower.png");
    float flowerX = FRAME_SIZE_X * 0.9;
    float flowerY = FRAME_SIZE_Y * 0.45;
    flower->setAnchorPoint(Vec2(0, 0));
    flower->setPosition(Vec2(flowerX, flowerY));
    addChild(flower, 1);
    //teaTable
    auto teaTable = Sprite::create("councelingRoom/counselingRoom_teaTable.png");
    float teaTableX = FRAME_SIZE_X * 0.1;
    float teaTableY = FRAME_SIZE_Y * 0.06;
    teaTable->setAnchorPoint(Vec2(0, 0));
    teaTable->setPosition(Vec2(teaTableX, teaTableY));
    addChild(teaTable, 1);
    //teaCup
    auto teaCup = Sprite::create("councelingRoom/counselingRoom_teaCup.png");
    float teaCupX = FRAME_SIZE_X * 0.12;
    float teaCupY = FRAME_SIZE_Y * 0.12;
    teaCup->setAnchorPoint(Vec2(0, 0));
    teaCup->setPosition(Vec2(teaCupX, teaCupY));
    addChild(teaCup, 1);
    //book
    auto book = Sprite::create("councelingRoom/counselingRoom_book.png");
    float bookX = FRAME_SIZE_X * 0.17;
    float bookY = FRAME_SIZE_Y * 0.11;
    book->setAnchorPoint(Vec2(0, 0));
    book->setPosition(Vec2(bookX, bookY));
    addChild(book, 1);
    //doctor
    auto animateStanding = CreateAnimate::create("Doctor/DoctorStanding.plist", 20, 2, "DoctorStanding%04d", 0.5f);
    auto animateMove = CreateAnimate::create("Doctor/DoctorMove.plist", 20, 2, "DoctorMove%04d", 0.5f);
    auto doctor = Sprite::create();
    addChild(doctor,2);
    doctor->setPosition(233, 466);
    doctor->runAction(RepeatForever::create(animateStanding));

    //auto animate = CreateAnimate::create("saberMove.plist", 20, 7, "saberMove%04d", 0.13f);
    //auto sprite = Sprite::create();
    //addChild(sprite);
    //sprite->setScale(3);
    //sprite->setPosition(233, 233);
    //sprite->runAction(RepeatForever::create(animate));
    //auto knightMoveListener = EventListenerKeyboard::create();

    //knightMoveListener->onKeyPressed = [=](EventKeyboard::KeyCode code, Event* e)
    //{
    //    keys[code] = true;
    //};

    //knightMoveListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    //{
    //    keys[keyCode] = false;
    //};
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(knightMoveListener, this);

    return true;
}

void Home::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
