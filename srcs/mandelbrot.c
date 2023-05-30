/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 19:25:33 by tcensier      #+#    #+#                 */
/*   Updated: 2023/05/30 12:36:30 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double  magnitude(double z_re, double z_im)
{
    return ((z_re*z_re + z_im*z_im) > 4);
}

static void    mandel_calc(fractol_t *data, double c_re, double c_im)
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
        x = (x*x) - (y*y) + c_re;
        y = (2 * temp * y) - c_im;
        i++;
    }
    if (i == data->max_it)
        mlx_put_pixel(data->img, data->pos.x, data->pos.y, 0x0000FF);
    else
        mlx_put_pixel(data->img, data->pos.x, data->pos.y, set_color(data, i));
}

void    mandelbrot(void *param)
{
    double          c_im;
    double          c_re;
    fractol_t       *data;

    data = param;
    c_im = 0;
    c_re = 0;
    while (data->pos.x < data->win.width)
    {
        data->pos.y = 0;
        while (data->pos.y < data->win.height)
        {
            c_re = data->complex.min_re + (data->pos.x * data->complex.re_factor);
            c_im = data->complex.max_im - (data->pos.y * data->complex.im_factor);
            mandel_calc(data, c_re, c_im);
            data->pos.y++;
        }
        data->pos.x++;
    }
}

