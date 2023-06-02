/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 14:29:36 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 18:57:06 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_putstr_fd(char *s)
{
	write(1, s, ft_strlen(s));
}

//norm nightmare hah lmao shoot me
int	error_msg(void)
{
	ft_putstr_fd(" ___________________________\
	________________________________\n");
	ft_putstr_fd("|[!] An error occured while \
	passing the arguments:          |\n");
	ft_putstr_fd("|[?] To generate the Mandelb\
	rot set: ./fractol Mandelbrot   |\n");
	ft_putstr_fd("|[?] To generate the Julia s\
	et: ./fractol Julia xx.xx xx.xx |\n");
	ft_putstr_fd("|   [-] xx.xx as floating nu\
	mbers, between(2 | -2)          |\n");
	ft_putstr_fd("|[?] To generate the Burning\
	Ship set: ./fractol BurningShip |\n");
	ft_putstr_fd("|___________________________\
	________________________________|\n");
	return (false);
}
