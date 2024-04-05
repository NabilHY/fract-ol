/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:50:57 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/12 12:19:08 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int    main()
{
    t_list    *link;
    t_list     *node_1;
    t_list     *node_2;
    t_list     *node_3;
    t_list        *last_node;

    node_1 = ft_lstnew("Node 1");
    node_2 = ft_lstnew("Node 2");
    node_3 = ft_lstnew("Node 3");
    link = NULL;
    ft_lstadd_front(&link, node_3);
    ft_lstadd_front(&link, node_2);
    ft_lstadd_front(&link, node_1);
    last_node = ft_lstlast(link);
    printf("%s\n", (char *)last_node->content);
}*/
