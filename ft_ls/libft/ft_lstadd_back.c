/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_front.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 14:29:59 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 14:51:03 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstadd_back(t_list **last_elem, void *content, size_t content_size)
{
	t_list *new;

	if ((new = ft_lstnew(content, content_size)) == NULL)
		return (NULL);
	(*last_elem)->next = new;
	new->next = NULL;
	return (new);
}
