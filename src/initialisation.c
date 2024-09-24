/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:11:23 by tursescu          #+#    #+#             */
/*   Updated: 2024/09/06 09:04:30 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int		x;
	int		y;
	int		window_x;
	int		window_y;
	t_map	*temp;

	temp = game->map;
	y = 0;
	while (temp != NULL)
	{
		x = 0;
		while (temp->line[x] != '\0')
		{
			window_x = x * TILE_SIZE;
			window_y = y * TILE_SIZE;
			render_textures(temp->line[x], game, window_x, window_y);
			x++;
		}
		y++;
		temp = temp->next;
	}
}

void	render_textures(char target, t_game *game, int x, int y)
{
	if (target == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img[4],
			x, y);
	else if (target == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img[3],
			x, y);
	else if (target == 'P')
		render_player(game, x, y);
	else if (target == 'Z')
		render_enemy(game, x, y);
	else if (target == 'C')
		render_collectible(game, x, y);
	else if (target == 'E')
		render_exit(game, x, y);
}

void	texture_init(t_game *game, void *mlx)
{
	int	i;
	int	width;
	int	height;

	game->img[0] = mlx_xpm_file_to_image(mlx, TEXTURE_P_RIGHT, &width, &height);
	game->img[1] = mlx_xpm_file_to_image(mlx, TEXTURE_COLL, &width, &height);
	game->img[2] = mlx_xpm_file_to_image(mlx, TEXTURE_OP_DOOR, &width, &height);
	game->img[3] = mlx_xpm_file_to_image(mlx, TEXTURE_GROUND, &width, &height);
	game->img[4] = mlx_xpm_file_to_image(mlx, TEXTURE_WALL, &width, &height);
	game->img[5] = mlx_xpm_file_to_image(mlx, TEXTURE_CL_DOOR, &width, &height);
	game->img[6] = mlx_xpm_file_to_image(mlx, TEXTURE_P_LEFT, &width, &height);
	game->img[7] = mlx_xpm_file_to_image(mlx, TEXTURE_P_UP, &width, &height);
	game->img[8] = mlx_xpm_file_to_image(mlx, TEXTURE_P_DOWN, &width, &height);
	game->img[9] = mlx_xpm_file_to_image(mlx, TEXTURE_EN_1, &width, &height);
	game->img[10] = mlx_xpm_file_to_image(mlx, TEXTURE_EN_2, &width, &height);
	game->img[11] = mlx_xpm_file_to_image(mlx, TEXTURE_COLL_2, &width, &height);
	i = 0;
	while (i < 12)
	{
		if (!game->img[i])
			propper_exit(game, "Error Initialising Texture");
		i++;
	}
}

void	window_init(t_game *game)
{
	size_t	window_wid;
	size_t	window_hei;
	size_t	map_width;
	size_t	map_height;

	get_map_dimensions(game->map, &map_width, &map_height);
	window_wid = TILE_SIZE * map_width;
	window_hei = TILE_SIZE * map_height;
	game->mlx = mlx_init();
	if (!game->mlx)
		propper_exit(game, "Error initializing MLX");
	game->win = mlx_new_window(game->mlx, window_wid, window_hei, "so_long");
	if (!game->win)
		propper_exit(game, "Error initializing WIN");
	texture_init(game, game->mlx);
	render_map(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
}

void	init_values(t_game *game)
{
	game->collected = 0;
	game->player_direction = 0;
	game->enemy_frame = 0;
	game->steps = 0;
}
