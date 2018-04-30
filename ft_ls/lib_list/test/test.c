/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 15:56:50 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 18:28:49 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

int	main(void)
{
	t_list *list;
	t_lst_content *content;
	list  = new_list("test1", sizeof(char *));
	push_back(&list,"test2", sizeof(char *));
	push_back(&list, "test3", sizeof(char *));
	push_front(&list, "test4", sizeof(char *));
	push_front(&list, "test5", sizeof(char *));
	content = list->first;
	while (content)
	{
		printf("%s", content->data);
		content = content->next;
	}

}
