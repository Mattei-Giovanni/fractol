/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:57:44 by gmattei           #+#    #+#             */
/*   Updated: 2023/07/06 16:57:45 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	ft_julia_init(t_data *data)
{
	data->coord.iter = 0;
	data->coord.z.re = data->x_min + (data->coord.px + data->move_x)
		* (data->x_max - data->x_min) / data->small_side;
	data->coord.z.im = data->y_max - (data->coord.py + data->move_y)
		* (data->y_max - data->y_min) / data->small_side;
	data->coord.z.re_sq = data->coord.z.re * data->coord.z.re;
	data->coord.z.im_sq = data->coord.z.im * data->coord.z.im;
}

int	ft_julia(t_data *data)
{
	data->coord.px = 0;
	while (data->coord.px < data->small_side)
	{
		data->coord.py = 0;
		while (data->coord.py < data->small_side)
		{
			ft_julia_init(data);
			while (data->coord.z.re_sq + data->coord.z.im_sq < 4
				&& data->coord.iter < data->coord.max_iter)
			{
				data->coord.z.im = 2 * data->coord.z.re
					* data->coord.z.im + data->coord.julia.im;
				data->coord.z.re = data->coord.z.re_sq
					- data->coord.z.im_sq + data->coord.julia.re;
				data->coord.z.re_sq = data->coord.z.re * data->coord.z.re;
				data->coord.z.im_sq = data->coord.z.im * data->coord.z.im;
				data->coord.iter++;
			}
			ft_mlx_pixel_put(data, data->coord.px, data->coord.py,
				data->coord.iter + data->color * data->coord.iter);
			data->coord.py++;
		}
		data->coord.px++;
	}
	return (0);
}
