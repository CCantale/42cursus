#include "background.h"

static int backgroundX;
static Star stars[MAX_STARS];
static SDL_Texture *background;

void initBackground(void)
{
	background = loadTexture("gfx/background.png");
	
	backgroundX = 0;
}

void initStarfield(void)
{
	int i;
	
	for (i = 0 ; i < MAX_STARS ; i++)
	{
		stars[i].x = rand() % SCREEN_WIDTH;
		stars[i].y = rand() % SCREEN_HEIGHT;
		stars[i].speed = 1 + rand() % 8;
	}
}

void doBackground(void)
{
	if (--backgroundX < -SCREEN_WIDTH)
	{
		backgroundX = 0;
	}
}
	
void doStarfield(void)
{
	int i;
	
	for (i = 0 ; i < MAX_STARS ; i++)
	{
		stars[i].x -= stars[i].speed;
		
		if (stars[i].x < 0)
		{
			stars[i].x = SCREEN_WIDTH + stars[i].x;
		}
	}
}

void drawStarfield(void)
{
	int i, c;
	
	for (i = 0 ; i < MAX_STARS ; i++)
	{
		c = 32 * stars[i].speed;
		
		SDL_SetRenderDrawColor(app.renderer, c, c, c, 255);
		
		SDL_RenderDrawLine(app.renderer, stars[i].x, stars[i].y, stars[i].x + 3, stars[i].y);
	}
}

void drawBackground(void)
{
	SDL_Rect dest;
	int x;
	
	for (x = backgroundX ; x < SCREEN_WIDTH ; x += SCREEN_WIDTH)
	{
		dest.x = x;
		dest.y = 0;
		dest.w = SCREEN_WIDTH;
		dest.h = SCREEN_HEIGHT;
		
		SDL_RenderCopy(app.renderer, background, NULL, &dest);
	}
}
