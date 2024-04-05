/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:07:10 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/20 17:37:34 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
/*int    main()
{
    t_list    *link;
    t_list     *node_1;
    t_list     *node_2;
    t_list     *node_3;
	t_list     *node_4;
    t_list        *last_node;

    node_1 = ft_lstnew("Node 1");
    node_2 = ft_lstnew("Node 2");
    node_3 = ft_lstnew("Node 3");
	node_4 = ft_lstnew("Node 4");
    link = NULL;
    ft_lstadd_front(&link, node_3);
    ft_lstadd_front(&link, node_2);
    ft_lstadd_front(&link, node_1);
	ft_lstadd_back(&link, node_4);
    last_node = ft_lstlast(link);
    printf("%s\n", (char *)last_node->content);
}*/