/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap_lst_content.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:24:20 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 16:03:38 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

void        swap_lst_content(t_lst_content **c1, t_lst_content **c2)
{
	t_lst_content tmp;
	tmp = **c1;
	(*c1)->data = (*c2)->data;
	(*c1)->tri = (*c2)->tri;
	(*c1)->size_tri = (*c2)->size_tri;
	(*c2)->data = tmp.data;
	(*c2)->tri = tmp.tri;
	(*c2)->size_tri = tmp.size_tri;
}
