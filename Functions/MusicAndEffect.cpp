#include "Functions/MusicAndEffect.h"
using namespace CocosDenshion;

//if you want to play music or effect, then use the function playMusic() or playEffect(), and each of the parameter's meanings are like these:
//--- chonst char* music is the path of the music
//there are five commands,
//--- COMMAND_ON_OFF, means "turn off"
//--- COMMAND_OFF_ON, means "turn on"
//--- COMMAND_STILL, means "keep still"
//these three command above will only be used in the functions playMusic() or playEffect()
//--- COMMAND_VOLUME_INCREASE£¬means "increase the volume"
//--- COMMAND_VOLUME_DECREASE, means "decrease the volume"
//these two commands above will only be used in the functions MusicVolumeChange() or EffectVolumeChange()

bool MusicAndEffect::_effectCondition = true;
bool MusicAndEffect::_musicCondition = true;
float MusicAndEffect::_effectVolume = 0.5;
float MusicAndEffect::_musicVolume = 0.5;

void MusicAndEffect::playMusic(const char* music, bool loop, int command) {
    //command is to change the condition of music
    if (command == COMMAND_ON_OFF) {
        _musicCondition = false;
    }
    else if(command == COMMAND_OFF_ON) {
        _musicCondition = true;
    }

    //play the music or not
    if (_musicCondition == true) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(music, loop);
        SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(_musicVolume);
    }
    else {
        SimpleAudioEngine::getInstance()->stopBackgroundMusic(music);
    }
}

void MusicAndEffect::playEffect(const char* effect, int command) {
    if (_effectCondition == true) {
        SimpleAudioEngine::getInstance()->playEffect(effect);
        SimpleAudioEngine::getInstance()->setEffectsVolume(_effectVolume);
    }
    //command is to change the condition of music
    if (command == COMMAND_ON_OFF) {
        _effectCondition = false;
    }
    else if (command == COMMAND_OFF_ON) {
        _effectCondition = true;
    }
}

void MusicAndEffect::MusicVolumeChange(int command) 
    float OrigionVolumnMusic = _musicVolume;
    float volumeMusic;
    //change the volume
    if (command == COMMAND_VOLUME_INCREASE) {
        volumeMusic = OrigionVolumnMusic + 0.1;
    }
    else {
        volumeMusic = OrigionVolumnMusic - 0.1;
    }

    //to keep the range of volume in 0-1
    if (volumeMusic > 1) {
        volumeMusic = 1;
    }
    else if (volumeMusic < 0) {
        volumeMusic = 0;
    }

    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volumeMusic);
    _musicVolume = volumeMusic;
}
void MusicAndEffect::EffectVolumeChange(int command) {
    float OrigionVolumnEffect = _effectVolume;
    float volumeEffect;
    //change the volume
    if (command == COMMAND_VOLUME_INCREASE) {
        volumeEffect = OrigionVolumnEffect + 0.1;
    }
    else {
        volumeEffect = OrigionVolumnEffect - 0.1;
    }

    //to keep the range of volume in 0-1
    if (volumeEffect > 1) {
        volumeEffect = 1;
    }
    else if (volumeEffect < 0) {
        volumeEffect = 0;
    }

    SimpleAudioEngine::getInstance()->setEffectsVolume(volumeEffect);
    _effectVolume = volumeEffect;
}