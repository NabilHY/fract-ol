/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:21:29 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/16 09:42:29 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	void	*new_content;
	t_list	*current_node;

	current_node = lst;
	if (!current_node)
		return (NULL);
	head = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (current_node)
	{
		new_content = f(current_node->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		current_node = current_node->next;
	}
	return (head);
}
/*void	*increment_by_one(void *number)
{
	int	*x;

	x = (int *)number;
	*x += 1;
	return ((void *)x);
}

void	delete_item(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *link;
	t_list *node_1;
	t_list *node_2;
	t_list *node_3;
	t_list *node_4;
	t_list *upd_list;

	int arr[] = {1, 2, 3, 4};
	node_1 = ft_lstnew(&arr[0]);
	node_2 = ft_lstnew(&arr[1]);
	node_3 = ft_lstnew(&arr[2]);
	node_4 = ft_lstnew(&arr[3]);
	link = NULL;
	ft_lstadd_front(&link, node_3);
	ft_lstadd_front(&link, node_2);
	ft_lstadd_front(&link, node_1);
	ft_lstadd_back(&link, node_4);
	while (link) {
		printf("%d\n", *((int *)link->content));
		link = link->next;
	}

	// Reset 'link' back to the head of the original list
	link = node_1;

	upd_list = ft_lstmap(link, increment_by_one, delete_item);
	printf("New Linked List\n");
	while (upd_list) {
		printf("%d\n", *((int *)upd_list->content));
		upd_list = upd_list->next;
	}
	return (0);
}*/