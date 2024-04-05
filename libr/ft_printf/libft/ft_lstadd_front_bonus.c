/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:43:03 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/15 11:27:54 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int	main(void)
{
	t_list 	*link;
	t_list	*new_node;

	new_node = ft_lstnew("Node 1");
	ft_lstadd_front(&link, new_node);
	ft_putstr_fd((char *)link->content, 1);
	return(0);
}*/