/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   remove.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:23:38 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 15:42:18 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "list.h"

void        lst_remove(t_list *list, t_lst_content *lst_content)
{
    lst_content->back->next = lst_content->next;
    list->size--;
    free(lst_content);
}
