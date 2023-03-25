/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:38:38 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:31:45 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = 0;
	while (lst != 0)
	{
		if (lst->content != 0)
		{
			tmp = ft_lstnew(f(lst->content));
			ft_lstadd_back(&new, tmp);
		}
		else
			ft_lstclear(&new, del);
		lst = lst->next;
	}
	return (new);
}
