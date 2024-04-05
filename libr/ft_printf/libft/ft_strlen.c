/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:32:27 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/13 14:46:47 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int	main(void)
{
	char str[] = "1337 School";
	char str1[1];
	printf("custom=>%zu  Lib's=>%zu\n", ft_strlen(str1), strlen(str));
	return (0);
}*/