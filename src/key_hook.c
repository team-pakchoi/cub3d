/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:16:16 by cpak              #+#    #+#             */
/*   Updated: 2022/08/27 03:40:16 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_down(int keycode)
{
	t_game	*game;

	game = get_game_struct();
	if (keycode == KEY_W)
		game->player.key.move[0] = 1;
	if (keycode == KEY_S)
		game->player.key.move[1] = 1;
	if (keycode == KEY_A)
		game->player.key.move[2] = 1;
	if (keycode == KEY_D)
		game->player.key.move[3] = 1;
	if (keycode == KEY_ARROW_LEFT)
		game->player.key.rotate = -PLAYER_ROTATE_SPEED;
	if (keycode == KEY_ARROW_RIGHT)
		game->player.key.rotate = PLAYER_ROTATE_SPEED;
	return (0);
}

int	key_up(int keycode)
{
	t_game	*game;

	set_player();
	game = get_game_struct();
	if (keycode == KEY_W)
		game->player.key.move[0] = 0;
	if (keycode == KEY_S)
		game->player.key.move[1] = 0;
	if (keycode == KEY_A)
		game->player.key.move[2] = 0;
	if (keycode == KEY_D)
		game->player.key.move[3] = 0;
	if (keycode == KEY_ARROW_LEFT)
		game->player.key.rotate = 0;
	if (keycode == KEY_ARROW_RIGHT)
		game->player.key.rotate = 0;
	if (keycode == KEY_ESC)
		exit_with_close_button();
	return (0);
}
