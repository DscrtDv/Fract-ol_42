/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 14:03:29 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 14:42:00 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int    check_args(fractol_t *data, int argc, char **argv)
{
    if (argc < 2)
        return (error_msg());
    if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) == 0 && argc == 2)
        data->name = "Mandelbrot";
    else if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) == 0)
        data->name = "Julia";
    else if (ft_strncmp(argv[1], "BurningShip", ft_strlen("BurningShip")) == 0 && argc == 2)
        data->name = "BurningShip";
    else
        return (error_msg());
    return (true);
}