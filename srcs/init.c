/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 20:31:24 by tim           #+#    #+#                 */
/*   Updated: 2023/06/01 17:30:26 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void       init_fractol(fractol_t *data)
{
    data->mlx = mlx_init(data->win.width, data->win.height, data->name, true);
    if (!(data->mlx))
        exit(1);
    data->img = mlx_new_image(data->mlx, data->win.width, data->win.height);
    if (!(data->img))
        exit(1);
    mlx_image_to_window(data->mlx, data->img, data->win.width, data->win.height);
}