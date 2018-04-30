/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_back.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 16:07:40 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 18:15:19 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

t_lst_content   *push_back(t_list **lst, void *data, size_t size_data)
{
	t_lst_content *ret;

	if (!(ret = new_content(data, size_data)))
		return (NULL);
	(*lst)->last->next = ret;
	(*lst)->last = ret;
	(*lst)->size++;
	return (ret);
}
