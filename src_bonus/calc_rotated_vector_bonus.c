/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotated_vector_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:58:02 by cpak              #+#    #+#             */
/*   Updated: 2022/09/01 17:07:27 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vector	calc_rotated_vector(t_vector v, int d)
{
	t_vector	result;

	result.x = v.x * cos(d * M_PI / 180) - v.y * sin(d * M_PI / 180);
	result.y = v.x * sin(d * M_PI / 180) + v.y * cos(d * M_PI / 180);
	return (result);
}
