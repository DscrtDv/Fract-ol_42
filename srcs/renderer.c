/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/01 16:19:04 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 18:54:37 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	get_coord_x(t_fractol *data, int x)
{
	double	interval;
	double	coord;

	interval = (data->complex.max_re - data->complex.min_re) / data->win.width;
	coord = data->complex.min_re + interval * (double)x;
	return (coord);
}

double	get_coord_y(t_fractol *data, int y)
{
	double	interval;
	double	coord;

	interval = (data->complex.min_im - data->complex.max_im) / data->win.height;
	coord = data->complex.min_im - interval * (double)y;
	return (coord);
}

static int	equation_selector(t_fractol *data, double re, double im)
{
	int	iter;

	iter = 0;
	if (ft_strncmp(data->name, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		iter = mandel_calc(data, re, im);
	else if (ft_strncmp(data->name, "Julia", ft_strlen("Julia")) == 0)
		iter = julia_calc(data, re, im);
	else
		iter = bs_calc(data, re, im);
	return (iter);
}

void	render(t_fractol *data)
{
	double	im;
	double	re;
	int		x;
	int		y;
	int		iter;

	y = 0;
	while (y < data->win.height)
	{
		x = 0;
		im = get_coord_y(data, y);
		im += data->pos.y;
		while (x < data->win.width)
		{
			re = get_coord_x(data, x);
			re += data->pos.x;
			iter = equation_selector(data, re, im);
			draw_pixel(data, x, y, iter);
			x++;
		}
		y++;
	}
}
