#include "map_handler.h"

static char	**map_handler(char **new_map, int option)
{
	static char	**map;

	if (option == m_UPDATE_MAP)
	{
		map = mapcpy(map, new_map); //da fare
	}
	else if (option == m_GET_MAP)
	{
		return (map);
	}
	return (NULL);
}

void	update_map(char **new_map)
{
	map_handler(new_map, m_UPDATE_MAP);
}

char	**get_map(void)
{
	map_handler(NULL, m_GET_MAP);
}

void	edit_map(int x, int y, char edit)
{
	if (edit == '0' || edit == '1')
		get_map()[y][x] = edit;
}
	
