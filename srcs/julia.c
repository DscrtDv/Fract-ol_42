/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 00:14:57 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 00:33:15 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    init_julia(fractol_t *data, bool first_init)
{
    data->name = "Julia";
	data->max_it = 50;
    if (first_init)
    {
        data->win.width = 1080;
        data->win.height = 700;
    }
	data->complex.min_re = -2.0;
	data->complex.max_re = 2.0;
	data->complex.min_im = 2.0;
    data->complex.max_im = -2.0;
    data->complex.c_re = -0.7;
	data->complex.c_im = 0.27015;
    data->pos.x = 0;
	data->pos.y = 0;
    set_rgba(data);
    center_fractal(data);
}

int    julia_calc(fractol_t *data, double re, double im)
{
    double          x;
    double          y;
    double          temp;
    int             i;

    x = re;
    y = im;
    i = 0;
    while (i < data->max_it && !magnitude(x, y))
    {
        temp = x;
        x = (x*x) - (y*y) + data->complex.c_re;
        y = (2 * temp * y) - data->complex.c_im;
        i++;
    }
    return (i);
}