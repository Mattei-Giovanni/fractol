/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:02:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/28 17:08:25 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../projects/headers_2/first_layer.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>

# define WIN_WIDTH 900 
# define WIN_HEIGHT 900
# define MAX_ITER 150
# define MLX_ERROR -1

typedef struct s_complex
{
	double	re;
	double	re_sq;
	double	im;
	double	im_sq;
}	t_complex;

typedef struct s_coords
{
	int			px;
	int			py;
	t_complex	z;
	t_complex	c;
	t_complex	julia;
	int			iter;
	int			max_iter;
}	t_coords;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractal;
	int			small_side;
	int			color;
	int			label;
	int			launch;
	double		julia_multiplier;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		move_x;
	double		move_y;
	long double	mouse_x;
	long double	mouse_y;
	long double	zoom;
	long double	new_zoom;
	long double	zoom_factor;
	long double	zoom_incr;
	long double	zoom_decr;
	t_coords	coord;
	t_img		img;
}	t_data;

/*args check*/
int		ft_valid_args(t_data *data, int argc, char **argv);
int		ft_julia_args(t_data *data, int argc, char **argv);
void	ft_error_msg(void);
/*init functions*/
int		ft_init(t_data *data);
int		ft_get_small_side(void);
void	ft_hooks_init(t_data *data);
void	ft_draw_handler(t_data *data);
/*destroy function*/
void	*ft_free_fractol(void **ptr);
int		ft_destroy_fractal(t_data *data);
/*hooks handler functions*/
int		ft_mouse_handler(int keycode, int px, int py, t_data *data);
int		ft_key_handler(int keycode, t_data *data);
void	hook_handler_2(int keycode, t_data *data);
void	ft_reset_fractal(t_data *data);
void	ft_color_change(t_data *data);
/*zoom functions*/
void	ft_zoom_in(t_data *data, int px, int py);
void	ft_zoom_out(t_data *data, int px, int py);
void	instant_zoom(t_data *data);
void	instant_pointed_zoom(t_data *data, int x, int y, int n);
/*draw functions*/
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw(t_data *data);
void	ft_window_label(t_data *data);
void	fractal_change(t_data *data, int n);
/*Mandelbrot functions*/
void	ft_mandelbrot_init(t_data *data);
int		ft_equation(t_data *data);
/*Julia functions*/
void	ft_julia_init(t_data *data);
int		ft_julia(t_data *data);
/*Burning Ship functions*/
void	ft_burning_ship_init(t_data *data);
int		ft_burning_ship(t_data *data);

#endif
