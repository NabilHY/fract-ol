/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:49:43 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/18 12:46:52 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*int	main(void)
{
	t_list	*first_ptr;
	char str[] = "String livesin first node";
	first_ptr = ft_lstnew((void *)str);
	printf("%s\n", first_ptr->content);
	return(0);
}*/