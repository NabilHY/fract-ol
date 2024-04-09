/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:48:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/09 02:55:04 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "fractol.h"
#include <stdio.h>

typedef struct s_complex
{
	//		x -- real
	double real;
	//		y -- imaginary
	double i;
} t_complex;

int	main(void)
{
	t_complex	z;
	//	point
	t_complex	c;
	double		tmp_real;
	int			i;
	
	z.real = 0;
	z.i = 0;

	c.real = 5;
	c.i = 2;
	
	while (i < 42)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		printf("%f %f\n", z.real, z.i);
		i++;
	}
}
