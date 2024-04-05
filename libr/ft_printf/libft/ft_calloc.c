/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:30:37 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/18 11:01:34 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count && size && count > (4294967295 / size))
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, count * size);
	return (mem);
}
/*.
int	main(void)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_calloc(5, sizeof(int));
	while (i < 5)
		printf("%d\n", str[i++]);
	return (0);
}
*/