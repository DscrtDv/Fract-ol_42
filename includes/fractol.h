/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:06:35 by tcensier      #+#    #+#                 */
/*   Updated: 2023/06/01 17:46:26 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
# include <stddef.h>

typedef struct      s_window
{
    int32_t         width;
    int32_t         height;
}    				window_t;

typedef struct		s_pos
{
	int			x;
	int			y;
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

//frac
void        render(fractol_t *data);
int         mandel_calc(fractol_t *data, double re, double im);

//init
void	    init_fractol(fractol_t *data);
void        init_mandelbrot(fractol_t *data);

//colors
void        set_rgba(fractol_t *data);
uint32_t    set_color(fractol_t *data, int iter);
void	    draw_pixel(fractol_t *data, int x, int y, int iter);
void        increment_rgba(fractol_t *data, int key);

//hooks
void        loop_hook(void *param);
void        init_hooks(mlx_key_data_t ks, void *param);
void        reset_color(fractol_t *data);

//display
void        center_fractal(fractol_t *data);
void        resize_window(int32_t width, int32_t height, void *param);

//utils
size_t      ft_strlen(const char *str);
int         ft_strncmp(const char *s1, const char *s2, size_t n);

#endif