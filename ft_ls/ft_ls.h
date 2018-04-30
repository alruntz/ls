/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 19:05:11 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 16:57:10 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include "lib_list/list.h"

# define F_MAJ_R 0
# define F_MAJ_L 1
# define F_A 3
# define F_L 4
# define F_R 2
# define F_T 5
# define F_NULL 6

typedef struct dirent DIRENT;
typedef struct stat STAT;
typedef struct group GROUP;
typedef struct passwd PASSWD;

typedef struct	s_content
{
	char		*path;
	t_list		*contents;
}		t_content;

typedef struct	s_launcher
{
	t_list	*paths;
}		t_launcher;

t_content	*find_directory(char *path, int flags[5]);
t_list		*find_directory_rcrsv(t_list **lst, char *path, int flags[5]);
void		printdir_content(t_content *content, int flags[5]);
void		printdir_content_rcrsv(t_list *list, int flags[5]);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnew(size_t size);
size_t		ft_strlen(const char *str);
void		*ft_memalloc(size_t size);
void		print_col(char ***str, int margin);
char 		*ft_itoa(int nb);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			ft_strlen2d(char **str);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
	
#endif
