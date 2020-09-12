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
#include "Functions/MusicAndEffect.h"
#include "Constant.h"

USING_NS_CC;

Scene* Home::createScene()
{
    auto scene = Scene::create();
    auto layer = Home::create();
    scene->addChild(layer, 0);
    return scene;
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
    if ( !Layer::init() )
    {
        return false;
    }
    //////////////////////////home map inicialize/////////////////////////
    _tileMap = TMXTiledMap::create("councelingRoomMap.tmx");
    addChild(_tileMap, 0, HOME_MAP);

    TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
    //ValueMap spawnPoint = group->getObject("doctor");
    //float x = spawnPoint["x"].asFloat();
    //float y = spawnPoint["y"].asFloat();


    auto sofa = Sprite::create("councelingRoom/counselingRoom_sofa.png");
    auto flower = Sprite::create("councelingRoom/counselingRoom_flower.png");
    auto teaTable = Sprite::create("councelingRoom/counselingRoom_teaTable.png");
    auto teaCup = Sprite::create("councelingRoom/counselingRoom_teaCup.png");
    auto book = Sprite::create("councelingRoom/counselingRoom_book.png");
    initSprites(sofa, flower, teaTable, teaCup, book);

    //////////////////////////////////////hero inicialize//////////////////////////////////////////
    auto animateStanding = CreateAnimate::create("Doctor/DoctorStanding.plist", 20, 2, "DoctorStanding%04d", 0.5f);
    auto animateMove = CreateAnimate::create("Doctor/DoctorMove.plist", 20, 2, "DoctorMove%04d", 0.5f);

    _player = Sprite::create("Doctor/doctor.png");
    addChild(_player,2);
    _player->setPosition(233, 466);
    _player->runAction(RepeatForever::create(animateStanding));

    return true;
}

void Home::initSprites(cocos2d::Sprite* obj1, cocos2d::Sprite* obj2, cocos2d::Sprite* obj3, cocos2d::Sprite* obj4, cocos2d::Sprite* obj5) {
    //sofa
    float sofaX = FRAME_SIZE_X * 0.57;
    float sofaY = FRAME_SIZE_Y * 0.4;
    obj1->setAnchorPoint(Vec2(0, 0));
    obj1->setPosition(Vec2(sofaX, sofaY));
    addChild(obj1, 1);
    //flower
    float flowerX = FRAME_SIZE_X * 0.9;
    float flowerY = FRAME_SIZE_Y * 0.45;
    obj2->setAnchorPoint(Vec2(0, 0));
    obj2->setPosition(Vec2(flowerX, flowerY));
    addChild(obj2, 1);
    //teaTable
    float teaTableX = FRAME_SIZE_X * 0.1;
    float teaTableY = FRAME_SIZE_Y * 0.06;
    obj3->setAnchorPoint(Vec2(0, 0));
    obj3->setPosition(Vec2(teaTableX, teaTableY));
    addChild(obj3, 1);
    //teaCup
    float teaCupX = FRAME_SIZE_X * 0.12;
    float teaCupY = FRAME_SIZE_Y * 0.12;
    obj4->setAnchorPoint(Vec2(0, 0));
    obj4->setPosition(Vec2(teaCupX, teaCupY));
    addChild(obj4, 1);
    //book
    float bookX = FRAME_SIZE_X * 0.17;
    float bookY = FRAME_SIZE_Y * 0.11;
    obj5->setAnchorPoint(Vec2(0, 0));
    obj5->setPosition(Vec2(bookX, bookY));
    addChild(obj5, 1);
}

void Home::onEnter() {
    Layer::onEnter();
    //Listener
    auto doctorMoveListener = EventListenerKeyboard::create();
    doctorMoveListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
        //keys[keyCode] = true;
    };
    doctorMoveListener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event* event) {
        //keys[keyCode] = false;
    };
    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(doctorMoveListener, this);
    
    //Music
    MusicAndEffect::playMusic("music/main theme.mp3", true, COMMAND_OFF_ON);
}

void Home::onEnterTransitionDidFinish() {
    Layer::onEnterTransitionDidFinish();
}

void Home::onExit() {
    Layer::onExit();
}

void Home::onExitTransitionDidStart() {
    Layer::onExitTransitionDidStart();
}

void Home::cleanup() {
    Layer::cleanup();
}

void Home::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
