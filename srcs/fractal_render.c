/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:10:52 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/13 16:48:16 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	c.x = scaling_value(x, -2, +2, 0, WIDTH);
	c.y = scaling_value(y, -2, +2, 0, HEIGHT);
	while (i < fractal->iterations)
	{
		z = sum_complex(sqrt_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scaling_value(i, WHITE, BLACK, 0, fractal->iterations);
			mlx_put_pixel(fractal->img, x,y ,color);
			return ;
		}
		mlx_put_pixel(fractal->img, x,y ,BLACK);
		i++;
	}
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_image_to_window(fractal->mlx_ptr, fractal->img, 0, 0);
}