/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:24:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/15 19:56:26 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>


void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 10;
	fractal->zoom = 1.00;
}

void	my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_fractal	*fractal;
	(void)xdelta;

	fractal = (t_fractal *)param;
	if (ydelta > 0)
		fractal->zoom *= 1.05;
	else if (ydelta < 0)
		fractal->zoom *= 0.95;
	fractal_render(fractal);
}

void	my_cursorhook(double xpos, double ypos, void *param)
{
	t_fractal *fractal;
	int	julia;

	fractal = (t_fractal *)param;
	julia = ft_strncmp(fractal->name, "julia", 5);
	if (((int)xpos % 10 == 0 || (int)ypos % 10 == 0) && !julia)
	{
		fractal->x_julia = (scaling_value(xpos, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->x_shift;
		fractal->y_julia = (scaling_value(ypos, -2, +2, 0, HEIGHT) * fractal->zoom) + fractal->y_shift;
		fractal_render(fractal);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->y_shift += (0.5 * fractal->zoom);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->y_shift -= (0.5 * fractal->zoom);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->x_shift -= (0.5 * fractal->zoom);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->x_shift += (0.5 * fractal->zoom);
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		fractal->iterations += 10;
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
	{
		if (fractal->iterations >= 20)
			fractal->iterations -= 10;
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(fractal->mlx_ptr);
		exit(0);
	}
	fractal_render(fractal);
}

void	events_init(t_fractal *fractal)
{
	mlx_scroll_hook(fractal->mlx_ptr, &my_scrollhook, (void *)fractal);
	mlx_key_hook(fractal->mlx_ptr, &my_keyhook, (void *)fractal);
	mlx_cursor_hook(fractal->mlx_ptr, &my_cursorhook, (void *)fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init(WIDTH, HEIGHT,  fractal->name, 0);
	//if (!fractal->mlx_ptr)
	//	ft_error();
	fractal->img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	//	ft_error();
	}
	events_init(fractal);
	data_init(fractal);
}