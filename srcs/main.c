/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:49:57 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/28 17:06:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	instant_pointed_zoom(t_data *data, int x, int y, int n)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if (n == 1)
			ft_zoom_in(data, x, y);
		else
			ft_zoom_out(data, x, y);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		free(data);
	else if (ft_valid_args(data, argc, argv) == 0)
		ft_error_msg();
	else
	{
		data->fractal = ft_valid_args(data, argc, argv);
		ft_init(data);
		ft_draw_handler(data);
		ft_hooks_init(data);
	}
	return (0);
}
