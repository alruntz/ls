/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tri.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:24:50 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 16:59:59 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "list.h"

void        tri(t_list **lst, int invers)
{
	t_lst_content *lst_content;
	t_lst_content *tmp_lst_content;
	int b;

	b = 1;
	lst_content = (*lst)->first;
	while (b)
	{
		b = 0;
		while (lst_content)
		{
			tmp_lst_content = (*lst)->first;
			while (tmp_lst_content)
			{
				if (tmp_lst_content->size_tri == sizeof(int))
				{
					if (!invers && (int)lst_content->tri < (int)tmp_lst_content->tri)
					{
						swap_lst_content(&lst_content, &tmp_lst_content);
						b = 1;
					}
					else if (invers && (int)lst_content->tri > (int)tmp_lst_content->tri)
					{
						swap_lst_content(&lst_content, &tmp_lst_content);
						b = 1;
					}
				}
				else if (tmp_lst_content->size_tri == sizeof(char *))
				{
					if (!invers && ft_strcmp((char *)lst_content->tri, (char *)tmp_lst_content->tri) < 0)
					{
						swap_lst_content(&lst_content, &tmp_lst_content);
						b = 1;
					}
					else if (invers && ft_strcmp((char *)lst_content->tri, (char *)tmp_lst_content->tri) > 0)
					{
						swap_lst_content(&lst_content, &tmp_lst_content);
						b = 1;
					}
				}
				tmp_lst_content = tmp_lst_content->next;
			}
			lst_content = lst_content->next;
		}
	}
}
