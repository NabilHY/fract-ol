/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:39:14 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 11:06:12 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libr.h"

static void	ft_print_hexa_char(unsigned long int x)
{
	if (x < 10)
		ft_putchar_fd((x + '0'), 1);
	else
		ft_putchar_fd(('a' + (x - 10)), 1);
}

static void	ft_print_hexa(unsigned long int x, int *count)
{
	if (x / 16 == 0)
	{
		ft_print_hexa_char(x);
		*count += 1;
	}
	else
	{
		ft_print_hexa(x / 16, count);
		*count += 1;
		ft_print_hexa_char(x % 16);
	}
}

int	ft_print_pointer(unsigned long int x)
{
	int	count;

	if (!x)
		return (ft_putstr_fd("0x0", 1));
	count = 0;
	count += ft_putstr_fd("0x", 1);
	ft_print_hexa(x, &count);
	return (count);
}
