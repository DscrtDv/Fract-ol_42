/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 19:25:33 by tcensier      #+#    #+#                 */
/*   Updated: 2023/06/01 18:22:15 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandelbrot(fractol_t *data)
{
    data->name = "Mandelbrot";
	data->max_it = 40;
    data->win.width = 1080;
    data->win.height = 700;
	data->complex.min_re = -2.0;
	data->complex.max_re = 0.47;
	data->complex.min_im = 1.12;
    data->complex.max_im = -1.12;
    data->pos.x = 0;
	data->pos.y = 0;
    set_rgba(data);
    center_fractal(data);
}

static double  magnitude(double z_re, double z_im)
{
    return ((z_re*z_re + z_im*z_im) > 4);
}

int    mandel_calc(fractol_t *data, double re, double im)
{
    double          x;
    double          y;
    double          temp;
    int             i;

    x = 0;
    y = 0;
    i = 0;
    while (i < data->max_it && !magnitude(x, y))
    {
        temp = x;
        x = (x*x) - (y*y) + re;
        y = (2 * temp * y) - im;
        i++;
    }
    return (i);
}

