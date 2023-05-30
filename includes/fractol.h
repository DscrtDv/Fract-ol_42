/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:06:35 by tcensier      #+#    #+#                 */
/*   Updated: 2023/05/30 12:36:10 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h>

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
    double          re_factor;
    double          im_factor;	
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

void        mandelbrot(void *param);

//init
void	    init_fractol(fractol_t *data);
void        init_mandelbrot(fractol_t *data);

//colors
void        set_rgba(fractol_t *data);
uint32_t    set_color(fractol_t *data, int iter);
void        increment_rgba(fractol_t *data, int key);

//key_hooks
void        init_hooks(mlx_key_data_t ks, void *param);
void        reset_color(fractol_t *data);

//display
void        center_fractal(fractol_t *data);
void        resize_window(int32_t width, int32_t height, void *param);

#endif