/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:10:52 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/15 19:28:21 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	cmplx_initial_points(t_complex *c, t_complex *z, t_fractal *fractal, int x, int y)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->x = (scaling_value(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->x_shift;
		z->y = (scaling_value(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->y_shift;
		c->x = fractal->x_julia;
		c->y = fractal->y_julia;
	}
	else
	{
		z->x = 0;
		z->y = 0;
		c->x = (scaling_value(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->x_shift;
		c->y = (scaling_value(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->y_shift;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	cmplx_initial_points(&c, &z, fractal, x, y);
	while (i < fractal->iterations)
	{
		z = sum_complex(sqrt_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scaling_value(i, BLUE, GREEN, BLACK, fractal->iterations);
			mlx_put_pixel(fractal->img, x,y ,color);
			return ;
		}
		mlx_put_pixel(fractal->img, x,y, RED);
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