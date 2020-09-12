#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Constant.h"

class MusicAndEffect {
private:
	static bool _effectCondition;
	static bool _musicCondition;
	static float _effectVolume;
	static float _musicVolume;
public:
	static void playMusic(const char* music, bool loop, int command);
	static void playEffect(const char* effect, int command);
	static void MusicVolumeChange(int command);
	static void EffectVolumeChange(int command);
};

#endif // __SOUND_H__

//#define __SOUND_H__