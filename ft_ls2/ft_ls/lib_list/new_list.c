/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_list.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 15:25:22 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 15:21:38 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "list.h"

t_list      *new_list(void)
{
	t_list *ret;

	ret = malloc(sizeof(t_list));
	ret->last = NULL;
	ret->first = NULL;
	ret->last_id = 0;
	ret->size = 0;
	return (ret);
}
