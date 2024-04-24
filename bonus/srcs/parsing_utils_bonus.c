/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:58:45 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/23 17:08:17 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	modify_params(int *i, char *str, int *sign)
{
	while (str[*i] <= 32)
		*i += 1;
	if (str[*i] == '-')
	{
		*sign *= -1;
		*i += 1;
	}
	else if (str[*i] == '+')
		*i += 1;
}

double	ft_atod(char *str)
{
	int		i;
	double	pow;
	int		sign;
	int		integral;
	double	fraction;

	i = 0;
	fraction = 0;
	pow = 1;
	sign = 1;
	integral = 0;
	modify_params(&i, str, &sign);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		integral = (integral * 10) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		pow /= 10;
		fraction = fraction + (str[i++] - '0') * (pow);
	}
	return (sign * (fraction + integral));
}
