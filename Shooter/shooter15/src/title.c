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

#include "title.h"

static void logic(void);
static void draw(void);
static void drawLogo(void);

static SDL_Texture *sdl2Texture;
static SDL_Texture *shooterTexture;
static int reveal = 0;
static int timeout;

void initTitle(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	
	memset(app.keyboard, 0, sizeof(int) * MAX_KEYBOARD_KEYS);
	
	sdl2Texture = loadTexture("gfx/sdl2.png");
	shooterTexture = loadTexture("gfx/shooter.png");
	
	timeout = FPS * 5;
}

static void logic(void)
{
	doBackground();
	
	doStarfield();
	
	if (reveal < SCREEN_HEIGHT)
	{
		reveal++;
	}
	
	if (--timeout <= 0)
	{
		initHighscores();
	}
	
	if (app.keyboard[SDL_SCANCODE_LCTRL])
	{
		initStage();
	}
}

static void draw(void)
{
	drawBackground();
	
	drawStarfield();
	
	drawLogo();
	
	if (timeout % 40 < 20)
	{
		drawText(SCREEN_WIDTH / 2, 600, 255, 255, 255, TEXT_CENTER, "PRESS FIRE TO PLAY!");
	}
}

static void drawLogo(void)
{
	SDL_Rect r;
	
	r.x = 0;
	r.y = 0;
	
	SDL_QueryTexture(sdl2Texture, NULL, NULL, &r.w, &r.h);
	
	r.h = MIN(reveal, r.h);
	
	blitRect(sdl2Texture, &r, (SCREEN_WIDTH / 2) - (r.w / 2), 100);
	
	SDL_QueryTexture(shooterTexture, NULL, NULL, &r.w, &r.h);
	
	r.h = MIN(reveal, r.h);
	
	blitRect(shooterTexture, &r, (SCREEN_WIDTH / 2) - (r.w / 2), 250);
}
