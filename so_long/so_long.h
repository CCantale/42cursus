/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:45:10 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/16 11:00:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GAME_NAME	"so_long"
# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT		2
# define KEY_ESC	53

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibX/mlx.h"

typedef struct game
{
	void	*init;
	void	*win;
	char	**map;
	int		map_x;
	int		map_y;
	int		start;
	void	*player;
	int		player_x;
	int		player_y;
	int		steps;
	int		animation;
	int		time;
	void	*flip[6];
	void	*out_block;
	void	*s_block;
	void	*t_block;
	void	*o_door;
	void	*turner;
	void	*enemy;
	void	*black;
	void	*background;
}	t_game;

char	**ft_check_map(t_game *game, char *path);
int		check_name(char *path, char *ending);
int		check_letters(char *str);
int		quit(t_game *game);
void	*error_msg(char *msg);
int		error_int(char *msg);
int		update(t_game *game);
int		get_xml(t_game *game);
void	put_whatever(t_game *game, int i, int j);
void	move(t_game *game, int key);
int		check_for_coll(char **map, int map_y);
char	**split_nl(const char *s);
void	play_animation(t_game *game);
void	step(t_game *game);

#endif
