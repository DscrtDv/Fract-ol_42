/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 14:15:35 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 18:56:56 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	nav_keys(t_fractol *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->pos.x -= (data->complex.min_re - data->complex.max_re) * 0.05;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->pos.x += (data->complex.min_re - data->complex.max_re) * 0.05;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->pos.y += (data->complex.min_im - data->complex.max_im) * 0.05;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->pos.y -= (data->complex.min_im - data->complex.max_im) * 0.05;
}

void	loop_hook(void *param)
{
	t_fractol	*data;

	data = param;
	nav_keys(data);
	render(data);
}

void	init_hooks(mlx_key_data_t ks, void *param)
{
	t_fractol	*data;

	data = param;
	if ((ks.key == 'R' || ks.key == 'G' || \
		ks.key == 'B' || ks.key == 'A'))
		increment_rgba(data, ks.key);
	else if (ks.key == 'Z' && ks.action == MLX_PRESS)
		set_up(data, false, NULL);
	else if (ks.key == 'I' && ks.action == MLX_PRESS)
		data->max_it += 10;
	else if ((ks.key == 'O' && data->max_it != 0) && ks.action == MLX_PRESS)
		data->max_it -= 10;
	else if (ks.key == MLX_KEY_ESCAPE && ks.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}
