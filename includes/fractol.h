/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:06:35 by tcensier      #+#    #+#                 */
/*   Updated: 2023/05/23 22:38:08 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
# define WIDTH 600
# define HEIGHT 600

typedef struct      s_fractol
{
    void            *mlx;
    void            *img;
    int             x;
    int             y;
    unsigned int    current_it;
    unsigned int    max_it;
    double          min_re;
    double          max_re;
    double          min_im;
    double          max_im;
    double          re_factor;
    double          im_factor;
}                   t_fractol;

void    mandelbrot(t_fractol *data);
void    put_pixel(t_fractol *data);
#endif