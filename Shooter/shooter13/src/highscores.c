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

#include "highscores.h"

static void logic(void);
static void draw(void);
static int highscoreComparator(const void *a, const void *b);
static void drawHighscores(void);

void initHighscoreTable(void)
{
	int i;
	
	memset(&highscores, 0, sizeof(Highscores));
	
	for (i = 0 ; i < NUM_HIGHSCORES ; i++)
	{
		highscores.highscore[i].score = NUM_HIGHSCORES - i;
	}
}

void initHighscores(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	
	memset(app.keyboard, 0, sizeof(int) * MAX_KEYBOARD_KEYS);
}

static void logic(void)
{
	doBackground();
	
	doStarfield();
	
	if (app.keyboard[SDL_SCANCODE_LCTRL])
	{
		initStage();
	}
}

static void draw(void)
{
	drawBackground();
	
	drawStarfield();
	
	drawHighscores();
}

static void drawHighscores(void)
{
	int i, y;
	
	y = 150;
	
	drawText(425, 70, 255, 255, 255, "HIGHSCORES");
	
	for (i = 0 ; i < NUM_HIGHSCORES ; i++)
	{
		if (highscores.highscore[i].recent)
		{
			drawText(425, y, 255, 255, 0, "#%d ............. %03d", (i + 1), highscores.highscore[i].score);
		}
		else
		{
			drawText(425, y, 255, 255, 255, "#%d ............. %03d", (i + 1), highscores.highscore[i].score);
		}
		
		y += 50;
	}
	
	drawText(425, 600, 255, 255, 255, "PRESS FIRE TO PLAY!");
}

void addHighscore(int score)
{
	Highscore newHighscores[NUM_HIGHSCORES + 1];
	int i;
	
	for (i = 0 ; i < NUM_HIGHSCORES ; i++)
	{
		newHighscores[i] = highscores.highscore[i];
		newHighscores[i].recent = 0;
	}
	
	newHighscores[NUM_HIGHSCORES].score = score;
	newHighscores[NUM_HIGHSCORES].recent = 1;
	
	qsort(newHighscores, NUM_HIGHSCORES + 1, sizeof(Highscore), highscoreComparator);
	
	for (i = 0 ; i < NUM_HIGHSCORES ; i++)
	{
		highscores.highscore[i] = newHighscores[i];
	}
}

static int highscoreComparator(const void *a, const void *b)
{
	Highscore *h1 = ((Highscore*)a);
	Highscore *h2 = ((Highscore*)b);

	return h2->score - h1->score;
}
