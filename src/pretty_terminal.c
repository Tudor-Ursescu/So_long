/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:40:49 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 18:57:23 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_over(t_game *game)
{
	ft_printf("%s╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗\n", RED);
	ft_printf("%s║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝\n", YELLOW);
	ft_printf("%s╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═%s", BLUE, RESET);
	ft_printf("%s\n", RESET);
	propper_exit(game, "");
}

void	you_won(void)
{
	ft_printf("%s╦  ╦╔═╗╦ ╦  ╦ ╦╔═╗╦╗ ╦\n", BLUE);
	ft_printf("%s╚╗╔╝║ ║║ ║  ║║║║ ║║╚╗║\n", PINK);
	ft_printf("%s ╚╝ ╚═╝╚═╝  ╚╩╝╚═╝╩ ╚╝%s", WHITE, RESET);
	ft_printf("%s\n", RESET);
}

void	you_died(void)
{
	ft_printf("%s╦  ╦╔═╗╦ ╦  ╔═╗ ╦╔═╗╔═╗\n", RED);
	ft_printf("%s╚╗╔╝║ ║║ ║  ║ ╚╗║║╣ ║ ╚╗\n", ORANGE);
	ft_printf("%s ╚╝ ╚═╝╚═╝  ╚══╝╩╚═╝╚══╝%s", WHITE, RESET);
	ft_printf("%s\n", RESET);
}

void	not_yet(void)
{
	ft_printf("%s╦╗ ╦╔═╗╦═╗╔═╗\n", LIGHT_GREEN);
	ft_printf("%s║╚╗║║ ║╠═╝║╣\n", MEDIUM_GREEN);
	ft_printf("%s╩ ╚╝╚═╝╩  ╚═╝%s", DARK_GREEN, RESET);
	ft_printf("%s\n", RESET);
}

void	render_steps(t_game *game)
{
	char	*step_str;

	step_str = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 10, 50, 0xFF000F, "Steps taken: ");
	mlx_string_put(game->mlx, game->win, 100, 50, 0xFF00, step_str);
	free(step_str);
}
