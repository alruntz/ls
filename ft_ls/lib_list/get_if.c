/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_if.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:26:24 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 15:35:56 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

t_list      *get_if(t_list *lst, int (f)(void *), int val)
{
	t_list *ret;
	t_lst_content *content;

	content = lst->first;
	ret = new_list();
	while(content)
	{
		if (f(content->data) == val)
			push_back(&ret, content->data, content->size_data);
		content = content->next;
	}
	return (ret);
}
