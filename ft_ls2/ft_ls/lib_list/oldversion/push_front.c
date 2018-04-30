/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_front.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 17:42:04 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 18:15:44 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

t_lst_content	*push_front(t_list **lst, void *data, size_t size_data)
{
	t_lst_content *ret;

	if (!(ret = new_content(data, size_data)))
			return (NULL);
	ret->next = (*lst)->first;
	(*lst)->first = ret;
	(*lst)->size++;
	return (ret);
}
