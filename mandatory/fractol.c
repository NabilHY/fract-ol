/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:48:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/24 15:39:05 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parce_name(char **av, t_fractal *fractal)
{
	fractal->name = av[1];
	ft_tolower(av[1]);
}

void	ft_error(void)
{
	ft_putstr_err(ERR_MSG);
	exit(1);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac > 1)
		parce_name(av, &fractal);
	if (((ac == 2) && !ft_strncmp(av[1], "mandelbrot", 10)
			&& ft_strlen(av[1]) == 10)
		|| (((ac == 4) && 
				!ft_strncmp(av[1], "julia", 5))
			&& ft_strlen(av[1]) == 5 
			&& ft_double(av[3]) && ft_double(av[2]))
		|| ((ac == 2) && !ft_strncmp(av[1], "burning_ship", 12)))
	{
		if (!ft_strncmp(av[1], "julia", 5))
		{
			fractal.x_julia = ft_atod(av[2]);
			fractal.y_julia = ft_atod(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
		ft_error();
	return (0);
}
