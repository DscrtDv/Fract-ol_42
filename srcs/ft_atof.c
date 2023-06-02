/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 16:29:36 by tcensier      #+#    #+#                 */
/*   Updated: 2023/06/02 17:03:51 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	val;
	double	pow;

	i = 0;
	sign = 1;
	val = 0.0;
	pow = 1.0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		val = 10.0 * val + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		val = 10.0 * val + (str[i++] - '0');
		pow *= 10;
	}
	return (sign * val / pow);
}
