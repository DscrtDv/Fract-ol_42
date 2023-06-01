/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 21:21:12 by tim           #+#    #+#                 */
/*   Updated: 2023/06/01 17:37:32 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* Start colour settings for fractals */
void	set_rgba(fractol_t *data)
{
	data->color.r = 2;
	data->color.g = 1;
	data->color.b = 6;
	data->color.a = 255;
}

/* RGB values are based on how many iterations it take for a
coordinate to escape a circle of radius 2 */
uint32_t	set_color(fractol_t *data, int iter)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = data->color.r * iter;
	g = data->color.g * iter;
	b = data->color.b * iter;
	return (r << 24 | g << 16 | b << 8 | data->color.a);
}

void	draw_pixel(fractol_t *data, int x, int y, int iter)
{
	if (iter == data->max_it)
		mlx_put_pixel(data->img, x, y, 0x000000FF);
	else
		mlx_put_pixel(data->img, x, y, set_color(data, iter));
}

static void check_color(uint8_t *color)
{
    if (*color == 255)
        *color -= 2;
    else
        *color += 2;
}

void        increment_rgba(fractol_t *data, int key)
{
    if (key == 'R')
        check_color(&data->color.r);
    else if (key == 'G')
        check_color(&data->color.g);
    else if (key == 'B')
        check_color(&data->color.b);
    else if (key == 'A' && data->color.a != 0)
        data->color.a -= 2;
}

void        reset_color(fractol_t *data)
{
    set_rgba(data);
}