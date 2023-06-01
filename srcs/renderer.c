/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/01 16:19:04 by tim           #+#    #+#                 */
/*   Updated: 2023/06/01 18:07:12 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double  get_coord_x(fractol_t *data, int x)
{
    double  interval;
    double  coord;

    interval =  (data->complex.max_re - data->complex.min_re) / data->win.width;
    coord = data->complex.min_re + interval * (double)x;
    return (coord);
}

double get_coord_y(fractol_t *data, int y)
{
    double  interval;
    double  coord;

    interval =  (data->complex.min_im - data->complex.max_im) / data->win.height;
    coord = data->complex.min_im - interval * (double)y;
    return (coord);
}

static int equation_selector(fractol_t *data, double re, double im)
{
    int     iter;

    iter = 0;
    if (ft_strncmp(data->name, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
        iter = mandel_calc(data, re, im);
    return (iter);
}

void    render(fractol_t *data)
{
    double          im;
    double          re;
    int             x;
    int             y;
    int             iter;

    y = 0;    
    while (y < data->win.height)
    {
        x = 0;
        im = get_coord_y(data, y);
        while (x < data->win.width)
        {
            re = get_coord_x(data, x);
            iter = equation_selector(data, re, im);
            draw_pixel(data, x, y, iter);
            x++;
        }
        y++;
    }
}
