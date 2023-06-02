/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 21:21:12 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 14:21:28 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_rgba(fractol_t *data, int r, int g, int b)
{
	data->color.r = r;
	data->color.g = g;
	data->color.b = b;
	data->color.a = 255;
}

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

void        increment_rgba(fractol_t *data, int key)
{
    if (key == 'R')
        data->color.r += 2;
    else if (key == 'G')
        data->color.g += 2;
    else if (key == 'B')
        data->color.b += 2;
    else if (key == 'A' && data->color.a != 0)
		data->color.a -= 2;
}