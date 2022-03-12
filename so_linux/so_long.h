#ifndef SO_LONG_H
# define SO_LONG_H

# define GAME_NAME	"Matter of Time"
# define KEY_W		119
# define KEY_ESC	65307

# include <fcntl.h>
# include "libft/libft.h"
# include "minilinuX/mlx.h"
# include "minilinuX/mlx_int.h"

typedef struct game
{
	void	*init;
	void	*win;
	char	**map;
	int		map_x;
	int		map_y;
	int		start;
	int		changes;
	void	*player;
	void	*out_block;
	void	*s_block;
	void	*t_block;
	void	*o_door;
	void	*turner;
	void	*background;
}	t_game;

typedef struct player
{
	int	pos_x;
	int	pos_y;
	int	sand;
}	t_sandy;

char	**ft_check_map(t_game *game, char *path);
void	quit(t_game *game);
void	*error_msg(char *msg);
int		error_int(char *msg);
int		update(t_game *game);
int	get_xml(t_game *game);

#endif
