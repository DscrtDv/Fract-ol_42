/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 14:03:29 by tim           #+#    #+#                 */
/*   Updated: 2023/06/02 18:56:16 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	is_double(char *s)
{
	while (s && ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s == '\0')
		return (true);
	if (*s == '.')
		s++;
	if (!ft_isdigit(*s))
		return (false);
	while (ft_isdigit(*s))
		s++;
	if (*s != '\0')
		return (false);
	return (true);
}

static int	limit(char *s)
{
	double	res;

	res = ft_atof(s);
	return (res <= 2.0);
}

static int	check_julia(char *p1, char *p2)
{
	if (!is_double(p1) || !is_double(p2))
		return (false);
	if (!limit(p1) || !limit(p2))
		return (false);
	return (true);
}

int	check_args(t_fractol *data, int argc, char **argv)
{
	if (argc < 2)
		return (error_msg());
	if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) == 0 \
		&& argc == 2)
		data->name = "Mandelbrot";
	else if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) == 0 && argc == 4 \
			&& check_julia(argv[2], argv[3]))
		data->name = "Julia";
	else if (ft_strncmp(argv[1], "BurningShip", ft_strlen("BurningShip")) == 0 \
			&& argc == 2)
		data->name = "BurningShip";
	else
		return (error_msg());
	return (true);
}
