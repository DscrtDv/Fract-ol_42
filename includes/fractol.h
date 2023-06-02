/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:06:35 by tcensier      #+#    #+#                 */
/*   Updated: 2023/06/02 18:47:14 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_window
{
	int32_t			width;
	int32_t			height;
}				t_window;

typedef struct s_pos
{
	double			x;
	double			y;
}				t_pos;

typedef struct s_rgba
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
}			t_rgba;

typedef struct s_complex
{
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		c_re;
	double		c_im;
}				t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*img;
	char		*name;
	int			max_it;
	t_pos		pos;
	t_window	win;
	t_complex	complex;
	t_rgba		color;
}				t_fractol;

//render
void		render(t_fractol *data);
double		get_coord_x(t_fractol *data, int x);
double		get_coord_y(t_fractol *data, int y);

//fractal
int			mandel_calc(t_fractol *data, double re, double im);
int			julia_calc(t_fractol *data, double re, double im);
int			bs_calc(t_fractol *data, double re, double im);

//init
void		init_fractol(t_fractol *data);
void		set_up(t_fractol *data, bool first_init, char **argv);
void		init_mandelbrot(t_fractol *data, bool first_init);
void		init_julia(t_fractol *data, char **argv, bool first_init);
void		init_bs(t_fractol *data, bool first_init);

//colors
void		set_rgba(t_fractol *data, int r, int g, int b);
uint32_t	set_color(t_fractol *data, int iter);
void		draw_pixel(t_fractol *data, int x, int y, int iter);
void		increment_rgba(t_fractol *data, int key);

//hooks
void		loop_hook(void *param);
void		init_hooks(mlx_key_data_t ks, void *param);

//display
void		center_fractal(t_fractol *data);
void		resize_window(int32_t width, int32_t height, void *param);

//zoom
void		zoom(double y_delta, double x_delta, void *param);

//utils
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		magnitude(double z_re, double z_im);
int			ft_isdigit(char c);
int			ft_isspace(char c);
double		ft_atof(char *str);

//errors
int			check_args(t_fractol *data, int argc, char **argv);
int			error_msg(void);
#endif