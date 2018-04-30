/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 19:05:16 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 16:52:03 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include  "ft_ls.h"

#include <stdio.h>

char	g_flags[8] = {"RLralt1\0"};
int     g_flags_active[7] = {0, 0, 0, 0, 0, 0, 0};

static		t_list *to_path(char **v)
{
	t_list			*ret;
	t_lst_content	*content;
	int				i;

	i = -1;
	ret = new_list();
	while (v[++i])
	{
		content = push_back(&ret, v[i], ft_strlen(v[i]) + 1);
		content->tri = v[i];
		content->size_tri = sizeof(char *);
	}
	return (ret);
}

static void	init_launcher2(char **v, int *i, int error)
{
	int j;
	int k;

	while(v[*i] && v[*i][0] == '-')
	{
		j = -1;
		while(v[*i][++j])
		{
			k = -1;
			if (v[*i][j] == '-')
				j++;
			while(g_flags[++k])
				if (v[*i][j] == g_flags[k])
				{
					g_flags_active[k] = 1;
					error = 0;
					break;
				}
			if (error)
				exit(EXIT_FAILURE); // FLAG INCONNU
			error = 1;
		}
		(*i)++;
	}
}

t_launcher	*init_launcher(char **v)
{
	t_launcher	*ret;
	int			error;
	int			i;

	i = 0;
	error = 1;
	if (!(ret = malloc(sizeof(t_launcher))))
		return (NULL);
	v++;
	init_launcher2(v, &i, error);
	ret->paths = (v[i]) ? to_path(v + i) : NULL;
	return (ret);
}

void		check_options(char *path)
{
	t_list		*list;
	t_content	*content;

	list = NULL;
	content = NULL;
	if (g_flags_active[F_MAJ_R])
	{
		list = find_directory_rcrsv(&list, path, g_flags_active);
		printdir_content_rcrsv(list, g_flags_active);
	}
	else
	{
		content = find_directory(path, g_flags_active);
		if (g_flags_active[F_T])
			tri(&(content->contents), 1);
		else if (opendir(path))
			tri(&(content->contents), 0);
		printdir_content(content, g_flags_active);
	}
}

int			main(int c, char **v)
{
	t_lst_content	*tmp_paths;
	t_launcher		*launcher;
	
	(void)c;
	launcher = init_launcher(v);
	if (!launcher->paths)
		check_options(".\0");
	else
	{
		tmp_paths = launcher->paths->first;
		tri(&launcher->paths, 0);
		while (tmp_paths)
		{
			if (launcher->paths->size > 1 && opendir(tmp_paths->data))
				printf("\n%s:\n", (char *)(tmp_paths->data));
			check_options((char *)(tmp_paths->data));
			tmp_paths = tmp_paths->next;
		}
	}
	return (0);
}

