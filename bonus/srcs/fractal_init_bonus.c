/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:24:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/24 17:33:54 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 10;
	fractal->zoom = 1.00;
	fractal->cursor_x = 0;
	fractal->cursor_y = 0;
	fractal->x_min = -2;
	fractal->x_max = +2;
	fractal->y_min = -2;
	fractal->y_max = +2;
	fractal->x_shift = 0;
	fractal->y_shift = 0;
}

void	events_init(t_fractal *fractal)
{
	mlx_scroll_hook(fractal->mlx_ptr, &scrollhook, (void *)fractal);
	mlx_key_hook(fractal->mlx_ptr, &keyhook, (void *)fractal);
	mlx_cursor_hook(fractal->mlx_ptr, &cursor_coor, (void *)fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init(WIDTH, HEIGHT, fractal->name, 0);
	if (!fractal->mlx_ptr)
	{
		ft_putstr_err("MLX Window Failure");
		exit(EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img || (mlx_image_to_window(fractal->mlx_ptr , fractal->img, 0, 0) < 0))
	{
		mlx_terminate(fractal->mlx_ptr);
		ft_putstr_err("MLX Image Failure");
		exit(EXIT_FAILURE);
	}
	events_init(fractal);
	data_init(fractal);
}
