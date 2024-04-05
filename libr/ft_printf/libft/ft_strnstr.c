/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:45:21 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/13 14:46:05 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && needle[j]
			&& (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	largestring[] = "Foor Bar Baz";
	const char	smallstring[] = "Bar";
	char		*ptr;

	ptr = ft_strnstr(largestring, smallstring, sizeof(largestring));
	printf("%p\n", ft_strnstr(largestring, smallstring, sizeof(largestring)));
	printf("%p\n", strnstr(largestring, smallstring, sizeof(largestring)));
}
*/