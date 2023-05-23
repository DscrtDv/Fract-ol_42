/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 22:30:49 by tim           #+#    #+#                 */
/*   Updated: 2023/05/23 22:42:38 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void    put_pixel(t_fractol *data)
{
    int32_t color = ft_pixel(
        data->current_it % 0xff0000,
        data->current_it % 0x00ff00,
        data->current_it % 0x0000ff,
        data->current_it % 0xFF
    );
    mlx_put_pixel(data->img, data->x, data->y, color);
}

