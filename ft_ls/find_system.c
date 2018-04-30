/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_system.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 17:43:04 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 17:22:13 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_content	*find_directory(char *path, int flags[5])
{
	DIR				*op_dir;
	DIRENT			*readd;
	t_list			*ret;
	t_content		*cont;
	int				i;
	int				b;
	char			*final_path;
	STAT			*buf;
	t_lst_content	*tmp_content; // OBSOLETE : ASSIGNABLE DIRECTEMENT AVEC LST->FIRST.

	i = 0;
	ret = new_list();
	cont = malloc(sizeof(t_content));
	buf = malloc(sizeof(STAT));
	if (!(op_dir = opendir(path)))
	{
		cont->contents = NULL;
		//CHECK LES CODES DERREURS POUR LES MESSQGES ET SI ON QUITTE
		//	exit(-1);
	}
	else
	{
		while((readd = readdir(op_dir)))
		{
			b = 1;
			if (readd->d_name[0])
			{
				if (readd->d_name[0] == '.' &&  !flags[F_A])
					b = 0;
				if (b)
				{
					tmp_content = push_back(&ret, readd, sizeof(DIRENT));
					if (flags[F_T])
					{
						final_path = strdup(path);
						final_path = ft_strjoin(path, "/");
						final_path = ft_strjoin(final_path, readd->d_name);
						if (stat(final_path, buf) != -1)
						{
							tmp_content->tri = (void *)buf->st_mtime;
							tmp_content->size_tri = sizeof(int);
						}
					}
					else if (!flags[F_R])
					{
						tmp_content->tri = strdup(readd->d_name);
						tmp_content->size_tri = sizeof(char *);
					}
				}
			}
		}
		cont->contents = ret;
	}
	if (cont->contents)
		tri(&(cont->contents), 0);
	cont->path = path;
	return (cont);
}

t_list		*find_directory_rcrsv(t_list **lst, char *path,  int flags[5])
{
	t_lst_content	*content;
	char			*cat_tmp;

	t_content *directory_content = find_directory(path, flags);
	if (!(*lst))
		*lst = new_list();	
	push_back(lst, directory_content, sizeof(t_list));

	if (directory_content->contents)
		content = directory_content->contents->first;
	else
		content = NULL;
	while(content)
	{

		if (((DIRENT *)(content->data))->d_type == 4 &&
				((DIRENT *)(content->data))->d_name[0] != '.')
		{
			cat_tmp = strdup(path);
			cat_tmp = ft_strjoin(cat_tmp, "/");
			cat_tmp = ft_strjoin(cat_tmp, ((DIRENT *)(content->data))->d_name);
			find_directory_rcrsv(lst, cat_tmp, flags);
		}
		content = content->next;
	}
	return (*lst);
}
