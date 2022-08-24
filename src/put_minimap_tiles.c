/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap_tiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:53:00 by sarchoi           #+#    #+#             */
/*   Updated: 2022/08/22 02:53:29 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_minimap_tiles(void)
{
	t_game *game;
	t_map * map;
	t_point i;
	t_point tile_start;
	t_point tile_end;

	game = get_game_struct();
	map = &(game->map);
	i.y = 0;
	while (i.y < (int) map->height)
	{
		i.x = 0;
		while (i.x < (int) map->width)
		{
			tile_start.x = i.x * MINIMAP_TILE_SIZE;
			tile_start.y = i.y * MINIMAP_TILE_SIZE;
			tile_end.x = tile_start.x + MINIMAP_TILE_SIZE;
			tile_end.y = tile_start.y + MINIMAP_TILE_SIZE;
			if (map->array[i.y][i.x] == '1')
			{
				put_image_rect(map->textures.minimap_floor, tile_start, tile_end, MINIMAP_WALL_COLOR);
			}
			i.x++;
		}
		i.y++;
	}
}