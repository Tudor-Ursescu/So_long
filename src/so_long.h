/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:06:43 by tursescu          #+#    #+#             */
/*   Updated: 2024/09/06 11:26:04 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../dirs/libft/libft.h"
# include "../dirs/mlx/mlx.h"
# define TILE_SIZE 120
# define TEXTURE_WALL "./textures/wall.xpm"
# define TEXTURE_P_RIGHT "./textures/char_right.xpm"
# define TEXTURE_COLL "./textures/collectible1.xpm"
# define TEXTURE_GROUND "./textures/ground.xpm"
# define TEXTURE_CL_DOOR "./textures/closed_door.xpm"
# define TEXTURE_OP_DOOR "./textures/opened_door.xpm"
# define TEXTURE_P_UP "./textures/char_up.xpm"
# define TEXTURE_P_DOWN "./textures/char_down.xpm"
# define TEXTURE_P_LEFT "./textures/char_left.xpm"
# define TEXTURE_EN_1 "./textures/enemy1.xpm"
# define TEXTURE_EN_2 "./textures/enemy2.xpm"
# define TEXTURE_COLL_2 "./textures/collectible2.xpm"

# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define RED "\033[31m"
# define ORANGE "\033[38;5;214m"
# define WHITE "\033[37m"
# define RESET "\033[0m"
# define PINK "\033[38;5;206m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define LIGHT_GREEN "\033[38;5;120m"
# define MEDIUM_GREEN "\033[38;5;34m"
# define DARK_GREEN "\033[38;5;22m"

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img[12];
	t_map	*map;
	int		p_count;
	int		e_count;
	int		c_count;
	int		player_x;
	int		player_y;
	int		collected;
	int		player_direction;
	int		enemy_frame;
	int		steps;
}			t_game;
//Initialisation
void	window_init(t_game *game);
void	texture_init(t_game *game, void *mlx);
void	render_textures(char target, t_game *game, int x, int y);
void	render_map(t_game *game);
void	render_steps(t_game *game);
void	init_values(t_game *game);
void	render_player(t_game *game, int x, int y);
void	render_enemy(t_game *game, int x, int y);
void	render_collectible(t_game *game, int x, int y);
void	render_exit(t_game *game, int x, int y);
//Interactions functions
void	setup_hooks(t_game *game);
int		close_on_button(t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	game_over(t_game *game);
void	you_won(void);
void	you_died(void);
void	not_yet(void);
void	update_p_pos(t_game *game, t_map *old_pos, int new_x, int new_y);
void	player_events(t_game *game, char target_tile);
t_map	*get_target_pos(t_map *map, int target_y);
//Free and error handle
void	free_list(t_map *head);
int		propper_exit(t_game *game, char *str);
void	input_exit(t_game *game, char *str);
// Utils
void	find_player_pos(t_game *game);
void	flood_fill(t_map *head, size_t x, size_t y);
void	get_map_dimensions(t_map *head, size_t *width, size_t *height);
t_map	*create_node(char *line);
void	append_node(t_map **head, t_map *new_node);
void	set_char_at(t_map *head, size_t row, size_t col, char new_char);
char	get_char_at(t_map *head, size_t row, size_t col);
// Map Checks
int		is_rectangular(t_game *game);
int		closed_walls(t_game *game);
int		is_wall_line(const char *line, size_t width);
int		check_elements(t_game *game);
int		only_valid_elements(t_game *game);
int		check_unreachable(t_map *head);
int		path_is_valid(t_game *game);
void	good_input(t_game *game);

#endif