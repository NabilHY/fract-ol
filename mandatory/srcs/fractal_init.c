/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:24:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/24 21:38:39 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 10;
	fractal->zoom = 1.00;
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
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

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if ((keydata.key == MLX_KEY_KP_ADD 
			|| (keydata.key == MLX_KEY_EQUAL && keydata.modifier == MLX_SHIFT)) 
		&& keydata.action == MLX_RELEASE)
		fractal->iterations += 10;
	else if ((keydata.key == MLX_KEY_KP_SUBTRACT
			|| keydata.key == MLX_KEY_MINUS) && keydata.action == MLX_RELEASE)
	{
		if (fractal->iterations >= 20)
			fractal->iterations -= 10;
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_terminate(fractal->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	else
		return ;
	fractal_render(fractal);
}

void	events_init(t_fractal *fractal)
{
	mlx_scroll_hook(fractal->mlx_ptr, &my_scrollhook, (void *)fractal);
	mlx_key_hook(fractal->mlx_ptr, &my_keyhook, (void *)fractal);
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
	if (!fractal->img
		|| (mlx_image_to_window(fractal->mlx_ptr, fractal->img, 0, 0) < 0))
	{
		mlx_terminate(fractal->mlx_ptr);
		ft_putstr_err("MLX Image Failure");
		exit(EXIT_FAILURE);
	}
	events_init(fractal);
	data_init(fractal);
}
