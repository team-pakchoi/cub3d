/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpak <cpak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:33:12 by sarchoi           #+#    #+#             */
/*   Updated: 2022/09/01 19:13:08 by cpak             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(void)
{
	t_game	*game;

	game = get_game_struct();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	init_images();
	mlx_hook(game->win, KEY_PRESS, 0L, key_down, NULL);
	mlx_hook(game->win, KEY_RELEASE, 0L, key_up, NULL);
	mlx_hook(game->win, CLOSE_BUTTON, 0, exit_with_close_button, NULL);
	mlx_loop_hook(game->mlx, draw_frame, NULL);
}

static void	run_game(char *filepath)
{
	t_game	*game;

	game = get_game_struct();
	init_map(filepath);
	init_player();
	init_mlx();
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./cub3d <map_file_name>\n", 2);
		return (1);
	}
	printf("<Info> map file name: %s\n", argv[1]);
	run_game(argv[1]);
	free_game();
	return (0);
}
