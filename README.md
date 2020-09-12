# DreamBreaker1.0-
a project for learning

【About the MusicAndEffect's part】
the volume control and the "on and off" control have been totally realised.(except the buttons' setting)
if you want to play music or effect, then use the function playMusic() or playEffect(),and each of the parameter's meanings are like these:
---chonst char* music is the path of the music
there are five commands,
---COMMAND_ON_OFF,means "turn off"
---COMMAND_OFF_ON,means "turn on"
---COMMAND_STILL,means "keep still"
these three command above will only be used in the functions playMusic() or playEffect()
---COMMAND_VOLUME_INCREASE，means "increase the volume" 
---COMMAND_VOLUME_DECREASE ,means "decrease the volume"
these two commands above will only be used in the functions MusicVolumeChange() or EffectVolumeChange() 
