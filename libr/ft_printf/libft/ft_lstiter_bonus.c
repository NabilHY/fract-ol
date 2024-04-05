/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:18:03 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/16 09:26:12 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void	increment_by_one(void *number)
{
	int	*x;

	x = (int *)number;
	*x += 1;
}
int	main(void)
{
	t_list *link;
	t_list *node_1;
	t_list *node_2;
	t_list *node_3;
	t_list *node_4;

	int	arr[] = {1, 2, 3, 4};
	node_1 = ft_lstnew(&arr[0]);
    node_2 = ft_lstnew(&arr[1]);
    node_3 = ft_lstnew(&arr[2]);
    node_4 = ft_lstnew(&arr[3]);
	link = NULL;
	ft_lstadd_front(&link, node_3);
	ft_lstadd_front(&link, node_2);
	ft_lstadd_front(&link, node_1);
	ft_lstadd_back(&link, node_4);
	ft_lstiter(link, increment_by_one);
	while (link)
	{
   		printf("%d\n", *((int *)link->content));
    	link = link->next;
	}
}*/