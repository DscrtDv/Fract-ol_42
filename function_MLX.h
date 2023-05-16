/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   function_MLX.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: W2Wizard <main@w2wizard.dev>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/28 02:29:06 by W2Wizard      #+#    #+#                 */
/*   Updated: 2023/05/16 19:38:46 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX42_H
# define MLX42_H
# include <stdint.h>
# include <stdbool.h>
# include "MLX42_Input.h"
# ifdef __cplusplus
extern "C" {
# endif

typedef struct mlx_texture
{
	uint32_t	width;
	uint32_t	height;
	uint8_t		bytes_per_pixel;
	uint8_t*	pixels;
}	mlx_texture_t;

typedef struct xpm
{
	mlx_texture_t	texture;
	int32_t			color_count;
	int32_t			cpp;
	char			mode;
}	xpm_t;

typedef struct mlx_instance
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
	bool	enabled;
}	mlx_instance_t;

typedef struct mlx_key_data
{
	keys_t			key;
	action_t		action;
	int32_t			os_key;
	modifier_key_t	modifier;
}	mlx_key_data_t;

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	int32_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;

typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;

typedef enum mlx_errno
{
	MLX_SUCCESS = 0,	// No Errors
	MLX_INVEXT,			// File has an invalid extension
	MLX_INVFILE,		// File was invalid / does not exist.
	MLX_INVPNG,			// Something is wrong with the given PNG file.
	MLX_INVXPM,			// Something is wrong with the given XPM file.
	MLX_INVPOS,			// The specified X/Y positions are out of bounds.
	MLX_INVDIM,			// The specified W/H dimensions are out of bounds.
	MLX_INVIMG,			// The provided image is invalid, might indicate mismanagement of images.
	MLX_VERTFAIL,		// Failed to compile the vertex shader.
	MLX_FRAGFAIL,		// Failed to compile the fragment shader.
	MLX_SHDRFAIL,		// Failed to compile the shaders.
	MLX_MEMFAIL,		// Dynamic memory allocation has failed.
	MLX_GLADFAIL,		// OpenGL loader has failed.
	MLX_GLFWFAIL,		// GLFW failed to initialize.
	MLX_WINFAIL,		// Failed to create a window.
	MLX_STRTOOBIG,		// The string is too big to be drawn.
	MLX_ERRMAX,			// Error count
}	mlx_errno_t;

extern mlx_errno_t mlx_errno;


typedef enum mlx_settings
{
	MLX_STRETCH_IMAGE = 0,	// Should images resize with the window as it's being resized or not. Default: false
	MLX_FULLSCREEN,			// Should the window be in Fullscreen, note it will fullscreen at the given resolution. Default: false
	MLX_MAXIMIZED,			// Start the window in a maximized state, overwrites the fullscreen state if this is true. Default: false
	MLX_DECORATED,			// Have the window be decorated with a window bar. Default: true
	MLX_HEADLESS,			// Run in headless mode, no window is created. (NOTE: Still requires some form of window manager such as xvfb)
	MLX_SETTINGS_MAX,		// Setting count.
}	mlx_settings_t;


typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);

typedef void (*mlx_mousefunc)(mouse_key_t button, action_t action, modifier_key_t mods, void* param);

typedef void (*mlx_cursorfunc)(double xpos, double ypos, void* param);

typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param);

typedef void (*mlx_resizefunc)(int32_t width, int32_t height, void* param);

typedef void (*mlx_closefunc)(void* param);

typedef void mlx_win_cursor_t;

//= Error Functions =//
const char* mlx_strerror(mlx_errno_t val);

//= Generic Functions =//
mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize);

void mlx_set_setting(mlx_settings_t setting, int32_t value);

void mlx_close_window(mlx_t* mlx);

void mlx_loop(mlx_t* mlx);

void mlx_set_icon(mlx_t* mlx, mlx_texture_t* image);

void mlx_terminate(mlx_t* mlx);

double mlx_get_time(void);

//= Window/Monitor Functions =//
void mlx_focus(mlx_t* mlx);

void mlx_get_monitor_size(int32_t index, int32_t* width, int32_t* height);

void mlx_set_window_pos(mlx_t* mlx, int32_t xpos, int32_t ypos);

void mlx_get_window_pos(mlx_t* mlx, int32_t* xpos, int32_t* ypos);

void mlx_set_window_size(mlx_t* mlx, int32_t new_width, int32_t new_height);

void mlx_set_window_limit(mlx_t* mlx, int32_t min_w, int32_t min_h, int32_t max_w, int32_t max_h);

void mlx_set_window_title(mlx_t* mlx, const char* title);

//= Input Functions =//
bool mlx_is_key_down(mlx_t* mlx, keys_t key);

bool mlx_is_mouse_down(mlx_t* mlx, mouse_key_t key);

void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);

void mlx_set_mouse_pos(mlx_t* mlx, int32_t x, int32_t y);

void mlx_set_cursor_mode(mlx_t* mlx, mouse_mode_t mode);

mlx_win_cursor_t* mlx_create_std_cursor(cursor_t type);

mlx_win_cursor_t* mlx_create_cursor(mlx_texture_t* texture);

void mlx_destroy_cursor(mlx_win_cursor_t* cursor);

void mlx_set_cursor(mlx_t* mlx, mlx_win_cursor_t* cursor);

//= Hooks =//
void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param);

void mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param);

void mlx_cursor_hook(mlx_t* mlx, mlx_cursorfunc func, void* param);

void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);

void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param);

void mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param);

bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);

//= Texture Functions =//
mlx_texture_t* mlx_load_png(const char* path);

xpm_t* mlx_load_xpm42(const char* path);

void mlx_delete_texture(mlx_texture_t* texture);

void mlx_delete_xpm42(xpm_t* xpm);

mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture);

//= Image Functions =//
void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);

mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height);

int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y);

void mlx_delete_image(mlx_t* mlx, mlx_image_t* image);

bool mlx_resize_image(mlx_image_t* img, uint32_t nwidth, uint32_t nheight);

void mlx_set_instance_depth(mlx_instance_t* instance, int32_t zdepth);

//= String Functions =//
mlx_image_t* mlx_put_string(mlx_t* mlx, const char* str, int32_t x, int32_t y);

const mlx_texture_t* mlx_get_font(void);

int32_t mlx_get_texoffset(char c);

# ifdef __cplusplus
}
# endif
#endif