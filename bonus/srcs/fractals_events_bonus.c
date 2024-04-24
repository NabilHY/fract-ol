/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_events_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:43:40 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/24 13:26:09 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	apply_zoom(t_fractal *fractal, double zoom)
{
	double		x_plane;
	double		y_plane;

	x_plane = scaling_value(fractal->cursor_x, fractal->x_min, 
			fractal->x_max, WIDTH);
	y_plane = scaling_value(fractal->cursor_y, fractal->y_min, 
			fractal->y_max, HEIGHT);
	fractal->x_min = x_plane + ((fractal->x_min - x_plane) * zoom);
	fractal->x_max = x_plane + ((fractal->x_max - x_plane) * zoom);
	fractal->y_min = y_plane + ((fractal->y_min - y_plane) * zoom);
	fractal->y_max = y_plane + ((fractal->y_max - y_plane) * zoom);
}

void	cursor_coor(double xpos, double ypos, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	fractal->cursor_x = xpos;
	fractal->cursor_y = ypos;
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	double		zoom;

	(void)xdelta;
	fractal = (t_fractal *)param;
	zoom = 0.0;
	if (ydelta > 0)
	{
		fractal->zoom *= 1.05;
		zoom = 1.05;
	}
	else if (ydelta < 0)
	{
		fractal->zoom *= 0.95;
		zoom = 0.95;
	}
	else
		return ;
	apply_zoom(fractal, zoom);
	fractal_render(fractal);
}

void	keyhook_handler(mlx_key_data_t keydata, t_fractal *fractal)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		fractal->y_shift -= (0.5 * fractal->zoom);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		fractal->y_shift += (0.5 * fractal->zoom);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		fractal->x_shift -= (0.5 * fractal->zoom);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		fractal->x_shift += (0.5 * fractal->zoom);
	else if ((keydata.key == MLX_KEY_KP_ADD
			|| (keydata.key == MLX_KEY_EQUAL && keydata.modifier == MLX_SHIFT))
		&& keydata.action == MLX_RELEASE)
		fractal->iterations += 5;
	else if ((keydata.key == MLX_KEY_KP_SUBTRACT
			|| keydata.key == MLX_KEY_MINUS) && keydata.action == MLX_RELEASE)
	{
		if (fractal->iterations >= 20)
			fractal->iterations -= 5;
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_terminate(fractal->mlx_ptr);
		exit(0);
	}
	else
		return ;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	keyhook_handler(keydata, fractal);
	fractal_render(fractal);
}
