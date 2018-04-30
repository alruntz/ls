/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   to_array.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:25:26 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 15:39:19 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

void        **to_array(t_list *lst)
{
	void **ret;
	t_lst_content *lst_content;
	size_t i;

	ret = malloc(lst->size * lst->first->size_data + 1);
	i = 0;
	lst_content = lst->first;
	while(lst_content)
	{
		ret[i] = lst_content->data;//memcpy(ret[i], lst_content->data, lst_content->size_data);
		i++;
		lst_content = lst_content->next;
	}
	ret[i] = NULL;
	return (ret);
}
