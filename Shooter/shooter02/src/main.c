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

#include "main.h"

int main(int argc, char *argv[])
{
	memset(&app, 0, sizeof(App));
	memset(&player, 0, sizeof(Entity));
	
	initSDL();
	
	player.x = 100;
	player.y = 100;
	player.texture = loadTexture("gfx/player.png");
	
	atexit(cleanup);
	
	while (1)
	{
		prepareScene();
		
		doInput();
		
		blit(player.texture, player.x, player.y);
		
		presentScene();
		
		SDL_Delay(16);
	}

	return 0;
}
