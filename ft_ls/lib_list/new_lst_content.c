/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_content.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:36:24 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 16:55:15 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

t_lst_content   *new_lst_content(void *data, size_t size_data)
{
	t_lst_content *ret;
	ret = NULL;

	ret = malloc(sizeof(t_lst_content));
	if (data)
	{
		ret->data = ft_memalloc(size_data);
		ret->data = ft_memcpy(ret->data, data, size_data);
	}
	else
		ret->data = NULL;
	ret->tri = NULL;
	ret->size_data = size_data;
	ret->next = NULL;
	ret->back = NULL;
	return (ret);
}
