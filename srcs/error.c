/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 14:29:36 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 14:45:56 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


static void ft_putstr_fd(char *s)
{
    write(1, s, ft_strlen(s));
}

int    error_msg(void)
{
    ft_putstr_fd(" ___________________________________________________________\n");
    ft_putstr_fd("|[!] An error occured while passing the arguments:          |\n");
    ft_putstr_fd("|[?] To generate the Mandelbrot set: ./fractol Mandelbrot   |\n");
    ft_putstr_fd("|[?] To generate the Julia set: ./fractol Julia xx.xx xx.xx |\n");
    ft_putstr_fd("|   [-] xx.xx as floating numbers, between(2 | -2)          |\n");
    ft_putstr_fd("|[?] To generate the BurningShip set: ./fractol BurningShip |\n");
    ft_putstr_fd("|___________________________________________________________|\n");
    return (false);
}