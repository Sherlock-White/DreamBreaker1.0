#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Constant.h"

class MusicAndEffect {
private:
	//bool _doContinueGame;
	CC_SYNTHESIZE(bool, _effectCondition, EffectCondition);
	CC_SYNTHESIZE(bool, _musicCondition, MusicCondition);
	CC_SYNTHESIZE(float, _effectVolume, EffectVolume);
	CC_SYNTHESIZE(float, _musicVolume, MusicVolume);
public:
	MusicAndEffect(bool effectCondition,bool musicCondition,float effectVolume, float musicVolume);
	void playMusic(const char* music, bool loop, int command);
	void playEffect(const char* effect, int command);
	void MusicVolumeChange(int command);
	void EffectVolumeChange(int command);
};

#endif // __SOUND_H__

//#define __SOUND_H__