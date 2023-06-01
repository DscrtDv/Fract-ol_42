/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 15:34:47 by tim           #+#    #+#                 */
/*   Updated: 2023/06/01 17:59:39 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// void        center_fractal(fractol_t *data)
// {
//     double  range_x;
//     double  range_y;

//     if (data->win.width > data->win.height)
//     {
//         range_y = data->complex.min_im - data->complex.max_im;
//         range_x = (range_y / data->win.height) * data->win.width;
//         data->complex.max_re = range_x/2;
//         data->complex.min_re = -(range_x/2);
//         data->complex.min_im = range_y/2;
//         data->complex.max_im = -(range_y/2);
//     }
//     else if (data->win.width < data->win.height)
//     {
//         range_x = data->complex.max_re - data->complex.min_re;
//         range_y = (range_x / data->win.width) * data->win.height;
//         data->complex.max_re = range_x/2;
//         data->complex.min_re = -(range_x/2);
//         data->complex.min_im = range_y/2;
//         data->complex.max_im = -(range_y/2);
//     }
//     printf("max_x: %f |min_x: %f |max_y: %f |min_y: %f\n", data->complex.max_re, data->complex.min_re, data->complex.max_im, data->complex.min_im);
// }

void	center_fractal(fractol_t *data)
{
	double	range_y;
	double	range_x;

	if (data->win.width > data->win.height)
	{
		range_y = data->complex.min_im - data->complex.max_im;
		range_x = (range_y / data->win.height) * data->win.width;
		data->complex.min_re = -(range_x / 2);
		data->complex.max_re = range_x / 2;
		data->complex.min_im = range_y / 2;
		data->complex.max_im = -(range_y / 2);
	}
	else if (data->win.width < data->win.height)
	{
		range_x = data->complex.max_re - data->complex.min_re;
		range_y = (range_x / data->win.width) * data->win.height;
		data->complex.min_im = range_y / 2;
		data->complex.max_im = -(range_y / 2);
		data->complex.min_re = -(range_x / 2);
		data->complex.max_re = range_x / 2;
	}
}

void    resize_window(int32_t width, int32_t height, void *param)
{
    fractol_t   *data;

    data = param;
    if (width != data->win.width || height != data->win.height)
    {
        data->win.width = width;
        data->win.height = height;
        mlx_resize_image(data->img, data->win.width, data->win.height);
        center_fractal(data);
    }
}