/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:01:02 by sarchoi           #+#    #+#             */
/*   Updated: 2022/08/29 23:13:30 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_image_pixel(t_img *image, int x, int y)
{
	int				bytes;
	int				offset;
	unsigned int	index;

	bytes = image->bits_per_pixel / CHAR_BIT;
	offset = (image->size_line - image->width * bytes) / bytes;
	index = (image->width + offset) * y + x;
	return (image->addr[index]);
}
