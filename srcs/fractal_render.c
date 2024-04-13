/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:10:52 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/13 22:14:29 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handle_mandelbort_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	
	i = 0;
	c.x = (scaling_value(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->x_shift;
	c.y = (scaling_value(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->y_shift;
	while (i < fractal->iterations)
	{
		z = sum_complex(sqrt_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scaling_value(i, BLACK, WHITE, 0, fractal->iterations);
			mlx_put_pixel(fractal->img, x,y ,color);
			return ;
		}
		mlx_put_pixel(fractal->img, x,y, BLUE);
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
			handle_mandelbort_pixel(x, y, fractal);
		}
	}
	mlx_image_to_window(fractal->mlx_ptr, fractal->img, 0, 0);
}