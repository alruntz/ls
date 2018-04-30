/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 18:22:48 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 16:50:36 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

static void printinfos2(const char *name, STAT *buf, char *final_path, char **to_col, char *mode)
{
	char	buf_link[2048];
	char	*time;

	ft_bzero(buf_link, 2048);
	time = ft_strsub(ctime(&(buf->st_mtime)), 4, 13);
	time[strlen(time) - 1] = '\0';
	strmode(buf->st_mode, mode);
	mode[strlen(mode) - 1] = '\0';
	to_col[0] = strdup(mode);
	to_col[1] = strdup(ft_itoa((int)(buf->st_nlink)));
	to_col[2] = strdup(getpwuid(buf->st_uid)->pw_name);
	to_col[3] = strdup(getgrgid(buf->st_gid)->gr_name);
	to_col[4] = strdup(ft_itoa((int)(buf->st_size)));
	to_col[5] = strdup(time);
	if (readlink(final_path, buf_link, 2048) > 1)
	{
		to_col[6] = malloc(sizeof(char) * ft_strlen(name) +
				readlink(final_path, buf_link, 2048) + 5);
		strcpy(to_col[6], name);
		strcat(to_col[6], " -> ");
		strcat(to_col[6], buf_link);
	}
	else
		to_col[6] = strdup(name);
}

static int printinfos_content(char *path, const char *name, char ***to_col, size_t i)
{
	STAT 	*buf;
	char	*final_path;
	char	*mode;
	int		ret;

	ret = 0;
	mode = malloc(sizeof(char) * 11);
	mode[10] = '\0';
	buf = malloc(sizeof(STAT));
	final_path = strdup(path);
	final_path = ft_strjoin(path, "/");
	final_path = ft_strjoin(final_path, name); 
	if (lstat(final_path, buf) != -1)
	{
		printinfos2(name, buf, final_path, to_col[i], mode);
		ret = buf->st_blocks;
	}
	return (ret);
}

static char ***init_to_col(size_t t)
{
	size_t	i;
	char	***to_col;
	
	i = 0;
	to_col = malloc(sizeof(char **) * t + 1);
	while (i <= t)
	{
		to_col[i] = malloc(sizeof(char *) * 8);
		to_col[i][7] = NULL;
		i++;
	}
	to_col[i - 1] = NULL;
	return (to_col);
}

void		printdir_content2(t_lst_content *tmp, t_content *content, int flags[5], char ***to_col, blkcnt_t st_blocks)
{
	size_t i;

	i = 0;
	while(tmp)
	{
		if (content->path && ((DIRENT *)(tmp->data))->d_name[0])
		{
			if (flags[F_L])
			{
				st_blocks += printinfos_content(content->path, ((DIRENT *)(tmp->data))->d_name, to_col, i);
				i++;
			}
			else
				printf("%s\n", ((DIRENT *)(tmp->data))->d_name);
			tmp = (!flags[F_R]) ? tmp->next : tmp->back;
		}
	}
	if (flags[F_L])
	{
		printf ("total %lld\n", st_blocks);
		print_col(to_col, 0);
	}
}

void		printdir_content(t_content *content, int flags[5])
{
	t_lst_content	*tmp;
	char			***to_col;
	blkcnt_t 		st_blocks;

	st_blocks = 0;
	tmp = NULL;
	to_col = NULL;
	if (!content->contents)
	{
		if (content->path)
		{
			if (flags[F_L])
			{
				to_col = init_to_col(1);
				st_blocks += printinfos_content(".\0", content->path, to_col, 0);
			}
			else
				printf("%s\n", content->path);
		}
	}
	else
	{
		tmp = (!flags[F_R]) ? content->contents->first : content->contents->last;
		to_col = init_to_col(content->contents->size);
	}
	printdir_content2(tmp, content, flags, to_col, st_blocks);
}

void		printdir_content_rcrsv(t_list *list, int flags[5])
{
	t_lst_content	*tmp;
	t_content		*ttmp;

	tmp = NULL;
	if (list->first)
		tmp = list->first;
	while(tmp)
	{
		if (opendir(((t_content *)(tmp->data))->path) && strcmp(((t_content *)(tmp->data))->path, "."))
			printf("%s:\n", ((t_content*)(tmp->data))->path);
		ttmp = (t_content *)(tmp->data);
		printdir_content(ttmp, flags);
		if (tmp->next)
			printf("\n");
		tmp = tmp->next;
	}
}
