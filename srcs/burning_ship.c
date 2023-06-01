/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burning_ship.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 01:11:08 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 01:18:16 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_bs(fractol_t *data, bool first_init)
{
    data->name = "Burning Ship";
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
tim@POTSKED:~/Documents/Codam/projects/Fract-ol_42$ 
    center_fractal(data);
}

int    bs_calc(fractol_t *data, double re, double im)
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
        x = (x*x) - (y*y) + re;
        y = fabs(2 * temp * y) - im;
        i++;
    }
    return (i);
}

