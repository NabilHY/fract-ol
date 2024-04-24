/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:18:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/23 17:01:43 by nhayoun          ###   ########.fr       */
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

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
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

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}
