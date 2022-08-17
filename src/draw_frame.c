/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpak <cpak@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:34:02 by cpak              #+#    #+#             */
/*   Updated: 2022/08/17 14:57:49 by cpak             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_frame()
{
	t_game	*game;

	game = get_game_struct();
	mlx_clear_window(game->mlx, game->win);
	erase_minimap_dirline();
	erase_minimap_fov();
	erase_minimap_ray();
	erase_minimap_player();
}

void draw_minimap(void)
{
	draw_minimap_wall();
	draw_minimap_ray();
	draw_minimap_dirline();
	draw_minimap_fov();
	draw_minimap_player();
}

int	draw_frame(void)
{
	clear_frame();
	set_player();
	draw_wall();
	draw_minimap();
	return (0);
}
