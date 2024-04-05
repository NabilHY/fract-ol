/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:38:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 11:06:09 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libr.h"

int	ft_print_signed(int n)
{
	int	count;

	count = 0;
	ft_putnbr_fd(n, 1, &count);
	return (count);
}

static void	put_unsigned_nbr(unsigned int n, int fd, int *count)
{
	if (n < 10)
		*count += ft_putchar_fd((n + '0'), fd);
	else
	{
		put_unsigned_nbr((n / 10), fd, count);
		*count += ft_putchar_fd(((n % 10) + '0'), fd);
	}
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	put_unsigned_nbr(n, 1, &count);
	return (count);
}
