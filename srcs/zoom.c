/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/01 19:15:24 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 18:55:20 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	zoom_x(t_fractol *data, double re, int x, bool out)
{
	double	range;
	double	new_range;
	double	offset;
	double	prop;

	range = data->complex.max_re - data->complex.min_re;
	offset = range * 0.2;
	if (out)
		new_range = range + offset;
	else
		new_range = range - offset;
	prop = (double)x / data->win.width;
	data->complex.min_re = re - prop * new_range;
	data->complex.max_re = data->complex.min_re + new_range;
}

static void	zoom_y(t_fractol *data, double im, int y, bool out)
{
	double	range;
	double	new_range;
	double	offset;
	double	prop;

	range = data->complex.min_im - data->complex.max_im;
	offset = range * 0.2;
	if (out)
		new_range = range + offset;
	else
	{
		new_range = range - offset;
	}
	prop = (double)y / data->win.height;
	data->complex.min_im = im + prop * new_range;
	data->complex.max_im = data->complex.min_im - new_range;
}

void	zoom(double y_delta, double x_delta, void *param)
{
	t_fractol	*data;
	int32_t		x;
	int32_t		y;
	double		x_coord;
	double		y_coord;

	data = param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	(void)y_delta;
	x_coord = get_coord_x(data, x);
	y_coord = get_coord_y(data, y);
	if (x_delta > 0)
	{
		zoom_x(data, x_coord, x, false);
		zoom_y(data, y_coord, y, false);
	}
	else
	{
		zoom_x(data, x_coord, x, true);
		zoom_y(data, y_coord, y, true);
	}
}
