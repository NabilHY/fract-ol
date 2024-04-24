/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:18:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/24 21:08:51 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/* Function to calculate the scaling 
value based on the input and output ranges*/
double	scaling_value(double ival, double omin,
						double omax, double imax)
{
	return ((omax - omin) * (ival - 0) / (imax - 0) + omin);
}

/* Function to sum two complex numbers/points*/
/* Parameters:*/
/*   z1: first complex number/point*/
/*   z2: second complex number/point*/
/* Returns:*/
/*   The sum of the two complex numbers/points*/
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.imag = z1.imag + z2.imag;
	return (res);
}

/* Function to calculate the square root of a complex number*/
/* Parameters:*/
/* z: complex number*/
/* Returns:*/
/* The square root of the complex number*/
t_complex	sqrt_complex(t_complex z)
{
	t_complex	res;

	res.real = (z.real * z.real) - (z.imag * z.imag);
	res.imag = 2 * z.real * z.imag;
	return (res);
}
