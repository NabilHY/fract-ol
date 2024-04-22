/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:10:52 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/21 21:38:55 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"
#include <math.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	cmplx_initial_points(t_complex *c, t_complex *z, 
				t_fractal *fractal, t_coor *coor)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->x = (scaling_value(coor->x, fractal->x_min, 
					fractal->x_max, WIDTH)) + fractal->x_shift;
		z->y = (scaling_value(coor->y, fractal->y_min, 
					fractal->y_max, HEIGHT)) + fractal->y_shift;
		c->x = fractal->x_julia;
		c->y = fractal->y_julia;
	}
	else
	{
		z->x = 0;
		z->y = 0;
		c->x = (scaling_value(coor->x, fractal->x_min, 
					fractal->x_max, WIDTH)) + fractal->x_shift;
		c->y = (scaling_value(coor->y, fractal->y_min, 
					fractal->y_max, HEIGHT)) + fractal->y_shift;
	}
}

void	handle_pixel(t_coor *coor, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	cmplx_initial_points(&c, &z, fractal, coor);
	while (i < fractal->iterations)
	{
		if (!ft_strncmp(fractal->name, "burning_ship", 12))
		{
			z = (t_complex){fabs(z.x), fabs(z.y)};
			z = sum_complex(sqrt_complex(z), c);
		}
		else
			z = sum_complex(sqrt_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = i * get_rgba(255, 240, 0, 255);
			mlx_put_pixel(fractal->img, coor->x, coor->y, color);
			return ;
		}
		mlx_put_pixel(fractal->img, coor->x, coor->y, get_rgba(0, 0, 0, 255));
		i++;
	}
}

void	fractal_render(t_fractal *fractal)
{
	t_coor	coor;

	coor.y = -1;
	while (++coor.y < HEIGHT)
	{
		coor.x = -1;
		while (++coor.x < WIDTH)
		{
			handle_pixel(&coor, fractal);
		}
	}
	mlx_image_to_window(fractal->mlx_ptr, fractal->img, 0, 0);
}