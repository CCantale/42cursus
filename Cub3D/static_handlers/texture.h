#ifndef TEXTURE_H
# define TEXTURE_H

#define tex_GET_NORTH	0
#define tex_GET_SOUTH	1
#define tex_GET_WEST	2
#define tex_GET_EAST	3
#define tex_GET_FLOOR	4
#define tex_UPDATE	5
#define tex_ERROR	6

int	new_textures(char **new_set);
void	*get_north_texture(void);
void	*get_south_texture(void);
void	*get_west_texture(void);
void	*get_east_texture(void);
void	*get_floor_texture(void);

#endif
