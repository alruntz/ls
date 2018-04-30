/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   to_list.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:25:47 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 15:26:09 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "list.h"

t_list      *to_list(void **arr, size_t size_data)
{
	t_list *ret;
	int i;

	ret = new_list();
	i = -1;
	while(arr[++i])
		push_back(&ret, arr[i], size_data);
	return (ret);
}
