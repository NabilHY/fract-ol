/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:41:49 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/16 09:25:57 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current_node = *lst;
	while (current_node)
	{
		next_node = current_node->next;
		ft_lstdelone(current_node, del);
		current_node = next_node;
	}
	*lst = NULL;
}

/*void	free_content(void *content)
{
	free(content);
	printf("Node deleted\n");
}

int	main(void)
{
	t_list	*link;
	t_list	*node_1;
	t_list	*node_2;
	t_list	*node_3;
	t_list	*node_4;

	node_1 = ft_lstnew("Node 1");
	node_2 = ft_lstnew("Node 2");
	node_3 = ft_lstnew("Node 3");
	node_4 = ft_lstnew("Node 4");
	link = NULL;
	ft_lstadd_front(&link, node_3);
	ft_lstadd_front(&link, node_2);
	ft_lstadd_front(&link, node_1);
	ft_lstadd_back(&link, node_4);
	while (link->next)
	{
		printf("%s\n", (char *)link->content);
		link = link->next;
	}
	ft_lstclear(&link, free_content);
}

*/