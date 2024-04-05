/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:21:03 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 11:06:00 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libr.h"

static void	ft_print_hexa_char(unsigned int x, char cas)
{
	if (x < 10)
		ft_putchar_fd((x + '0'), 1);
	else
		ft_putchar_fd((cas + (x - 10)), 1);
}

static void	ft_print_hexa(unsigned int x, int *count, char cas)
{
	if (x / 16 != 0)
		ft_print_hexa(x / 16, count, cas);
	*count += 1;
	ft_print_hexa_char(x % 16, cas);
}

int	ft_print_hex(unsigned int x, char cas)
{
	int	count;

	count = 0;
	ft_print_hexa(x, &count, cas);
	return (count);
}
