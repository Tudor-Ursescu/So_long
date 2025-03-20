/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:40:53 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 18:57:42 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_on_button(t_game *game)
{
	game_over(game);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		game_over(game);
	if (keycode == W_KEY || keycode == UP_KEY)
	{
		game->player_direction = 2;
		move_player(game, 0, -1);
	}
	if (keycode == S_KEY || keycode == DOWN_KEY)
	{
		game->player_direction = 3;
		move_player(game, 0, 1);
	}
	if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		game->player_direction = 1;
		move_player(game, -1, 0);
	}
	if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		game->player_direction = 0;
		move_player(game, 1, 0);
	}
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0L, close_on_button, game);
}
