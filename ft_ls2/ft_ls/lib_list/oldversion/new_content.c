/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_content.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 15:33:12 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 18:12:18 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

t_lst_content *new_content(void *data, size_t size_data)
{
	t_lst_content *ret;
	
	if (!(ret = (t_lst_content *)malloc(sizeof(t_lst_content))))
		return (NULL);
	ret->next = NULL;
	if (!data)
		ret->data = NULL;
	else
	{
		if (!(ret->data = ft_memalloc(size_data)))
			return (NULL);
		ret->data = memcpy(ret->data, data, size_data);
	}
	return (ret);
}
