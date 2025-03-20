/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:15:35 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 18:57:10 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_player(t_game *game, int x, int y)
{
	if (game->player_direction == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img[0],
			x, y);
	else if (game->player_direction == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img[6],
			x, y);
	else if (game->player_direction == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->img[7],
			x, y);
	else if (game->player_direction == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->img[8],
			x, y);
}

void	render_enemy(t_game *game, int x, int y)
{
	if (game->enemy_frame % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img[9],
			x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img[10],
			x, y);
}

void	render_collectible(t_game *game, int x, int y)
{
	if (game->enemy_frame % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img[1],
			x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img[11],
			x, y);
}

void	render_exit(t_game *game, int x, int y)
{
	if (game->collected == game->c_count)
		mlx_put_image_to_window(game->mlx, game->win, game->img[2],
			x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img[5],
			x, y);
}
