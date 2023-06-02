/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:06:49 by tcensier      #+#    #+#                 */
/*   Updated: 2023/06/02 18:57:30 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	hooks(t_fractol *data)
{
	mlx_key_hook(data->mlx, &init_hooks, data);
	mlx_resize_hook(data->mlx, &resize_window, data);
	mlx_loop_hook(data->mlx, &loop_hook, data);
	mlx_scroll_hook(data->mlx, &zoom, data);
}

//----------------------------------------------------------------//

int32_t	main(int argc, char **argv)
{
	t_fractol		*data;

	data = (t_fractol *)malloc(sizeof(t_fractol));
	if (!data)
		return (EXIT_FAILURE);
	if (!check_args(data, argc, argv))
		return (EXIT_FAILURE);
	set_up(data, true, argv);
	init_fractol(data);
	hooks(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	return (EXIT_SUCCESS);
}
