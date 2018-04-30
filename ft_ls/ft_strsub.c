/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:57 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/03 14:20:38 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	n;

	n = start;
	i = 0;
	if (!(ret = ft_strnew(sizeof(char) * len)))
		return (NULL);
	if (s)
	{
		while (i < len)
		{
			ret[i] = s[n];
			i++;
			n++;
		}
	}
	return (ret);
}
