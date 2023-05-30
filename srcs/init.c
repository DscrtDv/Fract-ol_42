/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 20:31:24 by tim           #+#    #+#                 */
/*   Updated: 2023/05/30 12:32:00 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandelbrot(fractol_t *data)
{
    data->name = "mandelbrot";
	data->max_it = 100;
    data->win.width = 1920;
    data->win.height = 1080;
	data->complex.min_re = -2.0;
	data->complex.max_re = 2.0;
	data->complex.min_im = 1.12;
    data->complex.max_im = -1.12;
    data->pos.x = 0;
	data->pos.y = 0;
	data->complex.re_factor = (data->complex.max_re - data->complex.min_re)/(data->win.width);
	data->complex.im_factor = (data->complex.max_im - data->complex.min_im)/(data->win.height);
    set_rgba(data);
    center_fractal(data);
}

void       init_fractol(fractol_t *data)
{
    data->mlx = mlx_init(data->win.width, data->win.height, data->name, true);
    if (!(data->mlx))
        exit(1);
    data->img = mlx_new_image(data->mlx, data->win.width, data->win.height);
    if (!(data->img))
        exit(1);
}