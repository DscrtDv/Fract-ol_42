/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:06:49 by tcensier      #+#    #+#                 */
/*   Updated: 2023/06/02 14:22:47 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------

static void	hooks(fractol_t *data)
{
	mlx_key_hook(data->mlx, &init_hooks, data);
	mlx_resize_hook(data->mlx, &resize_window, data);
	mlx_loop_hook(data->mlx, &loop_hook, data);
	mlx_scroll_hook(data->mlx, &zoom, data);
}

int32_t	main(int argc, char **argv)
{
	fractol_t		*data;

	data = (fractol_t *)malloc(sizeof(fractol_t));
	if (!data)
		return (EXIT_FAILURE);
	if (!check_args(data, argc, argv))
		return (-1);
	set_up(data, true);
	init_fractol(data);
	hooks(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	
	return (EXIT_SUCCESS);
}