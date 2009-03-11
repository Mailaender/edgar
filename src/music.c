#include "headers.h"

#include "music.h"

extern Game game;

void freeMusic(void);

void loadMusic(char *name)
{
	freeMusic();

	game.music = Mix_LoadMUS(name);

	if (game.music == NULL)
	{
		printf("Could not load music file %s: %s\n", name, Mix_GetError());
	}
}

void freeMusic()
{
	if (game.music != NULL)
	{
		stopMusic();

		Mix_FreeMusic(game.music);

		game.music = NULL;
	}
}

void playMusic()
{
	if (game.music != NULL)
	{
		Mix_VolumeMusic(MIX_MAX_VOLUME);
	
		Mix_PlayMusic(game.music, -1);
	}
}

void stopMusic()
{
	Mix_HaltMusic();
}

int adjustMusicVolume(int val)
{
	int current = Mix_VolumeMusic(-1);

	if ((current == 0 && val < 0) || (current == MIX_MAX_VOLUME && val > 0))
	{
		return current;
	}

	current += val;

	Mix_VolumeMusic(current);

	return current;
}

void setMusicVolume(int val)
{
	Mix_VolumeMusic(val);
}

int getMusicVolume()
{
	return Mix_VolumeMusic(-1);
}
