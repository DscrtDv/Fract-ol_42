/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 20:31:24 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 18:57:19 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_up(t_fractol *data, bool first_init, char **argv)
{
	if (ft_strncmp(data->name, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		init_mandelbrot(data, first_init);
	else if (ft_strncmp(data->name, "Julia", ft_strlen("Julia")) == 0)
		init_julia(data, argv, first_init);
	else
		init_bs(data, first_init);
}

void	init_fractol(t_fractol *data)
{
	data->mlx = mlx_init(data->win.width, data->win.height, data->name, true);
	if (!(data->mlx))
		exit(1);
	data->img = mlx_new_image(data->mlx, data->win.width, data->win.height);
	if (!(data->img))
		exit(1);
	mlx_image_to_window(data->mlx, data->img, data->win.width \
						, data->win.height);
}
