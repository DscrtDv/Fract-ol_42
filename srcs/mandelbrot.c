/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 19:25:33 by tcensier      #+#    #+#                 */
/*   Updated: 2023/05/24 00:25:45 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double  magnitude(double z_re, double z_im)
{
    return (z_re*z_re + z_im*z_im);
}

static void    mandel_calc(t_fractol *data, double c_re, double c_im)
{
    double          z_re;
    double          z_im;
    unsigned int    it;
    
    z_re = c_re;
    z_im = c_im;
    while (data->current_it < data->max_it)
    {
        if (magnitude(z_re, z_im) > 4)
            mlx_put_pixel(data->img, data->x, data->y, 0xffffff);
        z_im = 2 * z_re * z_im + c_im;
        z_re = (z_re * z_re) - (z_im * z_im) + c_re;
        data->current_it++;
    }
        
    data->current_it = 0;
}

void    mandelbrot(t_fractol *data)
{
    double          c_im;
    double          c_re;
    int             temp;

    c_im = 0;
    c_re = 0;
    temp = data->y;
    while (data->x < WIDTH)
    {
        c_re = data->min_re + data->x * data->re_factor;
        data->y = temp;
        while (data->y < HEIGHT)
        {
            c_im = data->max_im - data->y * data->im_factor;
            mandel_calc(data, c_re, c_im);
            data->y++;
        }
        data->x++;
    }
}

