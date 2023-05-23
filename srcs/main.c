/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:06:49 by tcensier      #+#    #+#                 */
/*   Updated: 2023/05/23 22:34:35 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
//-------------------------------------------------------------------------

void	init_window(t_fractol *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
}

void	init_mandelbrot(t_fractol *data)
{
	data->x = 0;
	data->y = 0;
	data->max_it = 50;
	data->current_it = 0;
	data->min_re = -2.0;
	data->max_re = 1.0;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re) * (HEIGHT / WIDTH);
	data->re_factor = (data->max_re - data->min_re)/(WIDTH);
	data->im_factor = (data->max_im - data->min_im)/(HEIGHT);
}

//-------------------------------------------------------------------------

int32_t	main(void)
{
	t_fractol	*data;

	data = (t_fractol *)malloc(sizeof(t_fractol));
	if (!data)
		return (EXIT_FAILURE);
	init_window(data);
	init_mandelbrot(data);
	mandelbrot(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
