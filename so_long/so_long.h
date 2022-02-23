#ifndef SO_LONG_H
# define SO_LONG_H

# define GAME_NAME	"Matter of Time"
# define KEY_W		13

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibX/mlx.h"

typedef struct game
{
	void	*init;
	void	*win;
}	t_game;

typedef struct player
{
	int	pos_x;
	int	pos_y;
	int	sand;
}	t_sandy;

char	**ft_check_map(char *path);

#endif
