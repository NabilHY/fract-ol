/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:48:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/11 20:01:32 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h" 

int	main(int ac, char **av)
{
	t_fractal fractal;
	if (((ac == 2) && (!ft_strncmp(av[1], "mandelbort", 10)))
		|| ((ac == 4) && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		//fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Wrong Input!, Choose mandelbort or julia with it's read and imag. number \n", 0);
		exit(0);
	}
	return (0);
}
