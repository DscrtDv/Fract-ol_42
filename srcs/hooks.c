/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 14:15:35 by tim           #+#    #+#                 */
/*   Updated: 2023/06/01 17:10:07 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
void    loop_hook(void *param)
{
    fractol_t   *data;

    data = param;
    render(data);
}
void    init_hooks(mlx_key_data_t ks, void *param)
{
    fractol_t *data;
    data = param;
    if ((ks.key == 'R' || ks.key == 'G' ||\
        ks.key == 'B' || ks.key == 'A') &&\
        ks.action == MLX_PRESS)
        increment_rgba(data, ks.key);
    else if (ks.key == 'Z' && ks.action == MLX_PRESS)
        reset_color(data);
}