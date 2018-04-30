/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_back.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 16:07:40 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 15:37:09 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

t_lst_content   *push_back(t_list **lst, void *data, size_t size_data)
{
	t_lst_content *ret;

	ret = new_lst_content(data, size_data);
	if (!(*lst)->first)
		(*lst)->first = ret;
	else
		(*lst)->last->next = ret;
	ret->back = (*lst)->last;
	(*lst)->last = ret;
	(*lst)->last_id++;
	ret->id = (*lst)->last_id;
	(*lst)->size++;
	return (ret);
}
