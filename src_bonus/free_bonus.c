/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:01:30 by sarchoi           #+#    #+#             */
/*   Updated: 2022/09/01 17:07:27 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_game_map(void)
{
	t_game	*game;

	game = get_game_struct();
	if (game->map.raw != NULL)
		ft_lstclear(&(game->map.raw), free);
	if (game->map.array != NULL)
		ft_split_free(game->map.array);
	if (game->map.path_north_texture != NULL)
		free(game->map.path_north_texture);
	if (game->map.path_south_texture != NULL)
		free(game->map.path_south_texture);
	if (game->map.path_west_texture != NULL)
		free(game->map.path_west_texture);
	if (game->map.path_east_texture != NULL)
		free(game->map.path_east_texture);
}

static void	free_mlx_image(t_img *img)
{
	t_game	*game;

	game = get_game_struct();
	if (img == NULL || img->img_ptr == NULL)
		return ;
	mlx_destroy_image(game->mlx, img->img_ptr);
	free(img);
}

static void	free_mlx_image_array(t_img **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free_mlx_image(arr[i++]);
	}
	free(arr);
}

static void	free_game_textures(void)
{
	t_game	*game;

	game = get_game_struct();
	free_mlx_image(game->map.textures.north);
	free_mlx_image(game->map.textures.south);
	free_mlx_image(game->map.textures.west);
	free_mlx_image(game->map.textures.east);
	free_mlx_image(game->map.textures.minimap_floor);
	free_mlx_image(game->map.textures.minimap_wall);
	free_mlx_image(game->map.textures.door);
	free_mlx_image(game->map.textures.door_side);
	free_mlx_image_array(game->map.textures.fire);
}

/*
** NOTE: Do not free `game->mlx`
** because mlx library does not provide function to free it.
** And `free()` is not stable.
*/
void	free_game(void)
{
	t_game	*game;

	game = get_game_struct();
	free_game_map();
	free_game_textures();
	free_mlx_image(game->minimap);
	free_mlx_image(game->screen);
	if (game->mlx != NULL && game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
}
