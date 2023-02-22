#include "texture.h"

void	*texture_handler(char **new_set, int option);
/* end of declarations */

void	*get_north_texture(void)
{
	return (texture_handler(NULL, tex_GET_NORTH));
}

void	*get_south_texture(void)
{
	return (texture_handler(NULL, tex_GET_SOUTH));
}

void	*get_west_texture(void)
{
	return (texture_handler(NULL, tex_GET_WEST));
}

void	*get_east_texture(void)
{
	return (texture_handler(NULL, tex_GET_EAST));
}

void	*get_floor_texture(void)
{
	return (texture_handler(NULL, tex_GET_FLOOR));
}
