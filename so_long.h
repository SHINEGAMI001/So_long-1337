/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:08:49 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/26 01:45:13 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "Utils/libft/libft.h"
# include "Utils/printf/ft_printf.h"

# define BUFFER_SIZE 100000
# define FALSE 1
# define TRUE 0

# define WALL_PATH "Textures/tree_demonic5.png"
# define FLOOR_PATH "Textures/demonic_red9.png"
# define C_PATH "Textures/head.png"
# define PLAYER_PATH "Textures/lemure.png"
# define OP_PLAYER_PATH "Textures/blood_saint.png"
# define EXIT_PATH "Textures/runed_door.png"
# define BROKEN_EXIT_PATH "Textures/broken_door.png"

# define FILETYPE_ERROR "error\nWrong Mapfile !!\n"
# define MAP_ERROR "error\nNO MAP !!\n"
# define INVALID_MAP "error\nInvalid Map !!\n"
# define WALL_ERROR "error\nMap must be surrounded by walls !!\n"
# define COMPONENETS_ERROR "error\nMissing or Invalid components !!\n"
# define PATH_ERROR "error\nNo valid path !!\n"

# define GAME_ESC_MSG "\n Maybe next time :(\n"
# define GAME_WON_MSG "\n(((: U WON :)))\n"
# define DOOR_OPENED_MSG "\n!! Go to the door NOW !!\n\n"

typedef struct s_textures
{
	mlx_texture_t	*m_wall;
	mlx_texture_t	*m_floor;
	mlx_texture_t	*m_food;
	mlx_texture_t	*m_playr;
	mlx_texture_t	*m_exit;
	mlx_texture_t	*m_exit2;

}t_textures;

typedef struct s_images
{
	mlx_image_t	*m_wall;
	mlx_image_t	*m_floor;
	mlx_image_t	*m_food;
	mlx_image_t	*m_player;
	mlx_image_t	*m_exit;
	mlx_image_t	*m_exit2;
	mlx_image_t	*str_image;

}t_images;

typedef struct s_game
{
	struct s_textures	*textures;
	struct s_images		*images;
	mlx_t				*mlx;
	char				**map;
	char				**tmp_map;
	int					m_width;
	int					m_height;
	int					count_move;
	int					count_food;
	int					total_food;

}t_game;

char	**read_map(char *map);
void	free_map(char **map);

int		check_file_type(char *mapfile);
int		check_game(char **map);
int		check_all_components(char **map);
int		check_min_components(char **map);
int		check_path(t_game *game, char *mapfile);

int		map_is_rectangular(char **map);
int		map_is_walled(char **map);

int		total_collectibales(char **map);
void	count_comps(char **map, int *c, int *e, int *p);
void	get_map_size(t_game *game, char **map);
int		*get_position(t_game *game);

void	flood_map(t_game *game, int y, int x);
int		check_fmap(char **fmap);

int		load_game(t_game *game);
void	put_floor(t_game *game, t_images *image);
void	put_map(t_game *game, t_images *image);

void	load_image(t_game *game, t_textures *textures);
void	load_texture(t_game *game);

void	my_key_hook(mlx_key_data_t keydata, void *param);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);

void	take_food(t_game *game);
void	delete_food(t_game *game);

#endif