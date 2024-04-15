/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:48:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/14 22:51:48 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h" 

int	main(int ac, char **av)
{
	t_fractal fractal;

	if (((ac == 2) && !ft_strncmp(av[1], "mandelbort", 10))
		|| ((ac == 4) && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			fractal.x_julia = ft_atod(av[1]);
			fractal.y_julia = ft_atod(av[2]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		ft_putstr("Wrong Input!, Choose mandelbort or julia with it's real and imag. values \n");
		exit(0);
	}
	return (0);
}
