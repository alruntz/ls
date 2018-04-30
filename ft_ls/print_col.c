/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_col.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 18:02:00 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 16:54:37 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

char *strat(char *str, size_t n)
{
	char	*ret;
	size_t	i;

	if (!(ret = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = 0;
	while(i < n && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	str[i] = '\0';	
	return (ret);
}

static int determine_space(char ***str, int i, int j)
{
	size_t	max_len;
	size_t	tmp_len;
	int		tmp_i;


	max_len = 0;
	tmp_i = i;
	i =  0;
	while(str[i] && str[i][j])
	{
		tmp_len = ft_strlen(str[i][j]);
		if (tmp_len > max_len)
			max_len = tmp_len;
		i++;
	}
	return(max_len - ft_strlen(str[tmp_i][j]));
}

void	print_col(char ***str, int margin)
{
	int i;
	int j;
	int l;
	int spaces;

	j = -1;
	i = -1;
	spaces = 0;
	while (str[++i])
	{
		j = -1;
		while(str[i][++j])
		{
			l = -1;
			if (j == 0)
			{
				spaces = determine_space(str, i, j);
				while(++l < spaces)
					ft_putchar(' ');
			}
			l = -1;
			spaces = 0;
			if (str[i][j + 1])
				spaces = determine_space(str, i, j  + 1);
			printf("%s", str[i][j]);
			if (str[i][j + 2])
			{
				if (j == 0 || j == 2 || j == 3)
					margin = 1;
				else
					margin = 0;
				while (++l < margin + spaces)
					printf(" ");
			}
			if (str[i][j + 1])
				printf(" ");
		}
		printf("\n");
	}
}


/*int main()
{
	int i = -1;
	int j = -1;
	char ***test;
	test = malloc(sizeof(char **) * 4);
	while (++i < 2)
	{
		j = -1;
		test[i] = malloc(sizeof(char *) * 4);
		while (++j < 4)
			test[i][j] = malloc(sizeof(char) * 10);
	}
	test[0][0] = "helloezk\0";
	test[0][1] = "world\0";
	test[0][2] = "jedsl";
	test[0][3] = 0;
	test[1][0] = "hello\0";
	test[1][1] = "wor\0";
	test[1][2] = "smmqlqqsqsqsq";
	test[1][3]  = 0;
	test[2][0] = "hello\0";
	test[2][1] = "wor983291ssssssqqsqsqs\0";
	test[2][2] =  "ez";
	test[2][3] = 0;
	test[3] = 0;

	print_col(test, 2);
}*/
