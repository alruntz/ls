/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_list.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 15:25:22 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 15:47:39 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "list.h"

t_list	*new_list(void *data, size_t size_data)
{
	t_list *ret;
	
	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(ret->first = new_content(data, size_data)))
		return (NULL);
	ret->last = ret->first;
	ret->size = 1;
	return (ret);
}
