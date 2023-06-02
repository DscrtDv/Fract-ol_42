/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:06:35 by tcensier      #+#    #+#                 */
/*   Updated: 2023/06/02 14:45:26 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*
    -Arg
    -Arg check
    -mem leak check
    -clean-up
*/


typedef struct      s_window
{
    int32_t         width;
    int32_t         height;
}    				window_t;

typedef struct		s_pos
{
	double			x;
	double			y;
}					pos_t;

typedef struct      s_rgba
{
    uint8_t      r;
    uint8_t      g;
    uint8_t      b;
    uint8_t      a;
}                   rgba_t;

typedef struct		s_complex
{
    double          min_re;
    double          max_re;
    double          min_im;
    double          max_im;
    double          c_re;
    double          c_im;
}					complex_t;

typedef struct      s_fractol
{
    void            *mlx;
    void            *img;
	char			*name;
    int             max_it;
	pos_t			pos;
	window_t		win;
	complex_t		complex;
	rgba_t			color;
}                   fractol_t;

//render
void        render(fractol_t *data);
double      get_coord_x(fractol_t *data, int x);
double      get_coord_y(fractol_t *data, int y);

//fractal
int         mandel_calc(fractol_t *data, double re, double im);
int         julia_calc(fractol_t *data, double re, double im);
int         bs_calc(fractol_t *data, double re, double im);

//init
void	    init_fractol(fractol_t *data);
void        set_up(fractol_t *data, bool first_init);
void        init_mandelbrot(fractol_t *data, bool first_init);
void        init_julia(fractol_t *data, bool first_init);
void	    init_bs(fractol_t *data, bool first_init);

//colors
void        set_rgba(fractol_t *data, int r, int g, int b);
uint32_t    set_color(fractol_t *data, int iter);
void	    draw_pixel(fractol_t *data, int x, int y, int iter);
void        increment_rgba(fractol_t *data, int key);

//hooks
void        loop_hook(void *param);
void        init_hooks(mlx_key_data_t ks, void *param);

//display
void        center_fractal(fractol_t *data);
void        resize_window(int32_t width, int32_t height, void *param);

//zoom
void        zoom(double y_delta, double x_delta, void *param);

//utils
size_t      ft_strlen(const char *str);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
double      magnitude(double z_re, double z_im);

//errors
int         check_args(fractol_t *data, int argc, char **argv);
int         error_msg(void);
#endif