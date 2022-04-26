/*
Copyright (C) 2015-2018 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define STRNCPY(dest, src, n) strncpy(dest, src, n); dest[n - 1] = '\0'

#define SCREEN_WIDTH             1280
#define SCREEN_HEIGHT            720

#define MAX_SCORE_NAME_LENGTH    16
#define MAX_NAME_LENGTH          32
#define MAX_LINE_LENGTH          1024

#define FPS                      60

#define PLAYER_SPEED             4
#define PLAYER_BULLET_SPEED      20
#define ALIEN_BULLET_SPEED       8

#define MAX_KEYBOARD_KEYS        350

#define SIDE_PLAYER              0
#define SIDE_ALIEN               1

#define MAX_STARS                500

#define MAX_SND_CHANNELS         8

#define NUM_HIGHSCORES           8

#define GLYPH_HEIGHT             28
#define GLYPH_WIDTH              18

enum
{
	CH_ANY = -1,
	CH_PLAYER,
	CH_ALIEN_FIRE,
	CH_POINTS
};

enum
{
	SND_PLAYER_FIRE,
	SND_ALIEN_FIRE,
	SND_PLAYER_DIE,
	SND_ALIEN_DIE,
	SND_POINTS,
	SND_MAX
};

enum
{
	TEXT_LEFT,
	TEXT_CENTER,
	TEXT_RIGHT
};
