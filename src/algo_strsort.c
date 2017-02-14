/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 14:36:24 by obelange          #+#    #+#             */
/*   Updated: 2017/01/20 14:36:26 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char		**algo_no_strsort(t_context *context, char **filelist)
{
	return (filelist);
}

// static int	lex_loop(char )

char		**algo_asclex_strsort(t_context *context, char **filelist)
{
	char	*tmp_file;
	int		flag;
	size_t	i;

	flag = 1;
	if (filelist)
	{
		while (flag == 1)
		{
			i = 1;
			flag = 0;
			while (filelist[i])
			{
				if (ft_strcmp(filelist[i], filelist[i - 1]) < 0)
				{
					tmp_file = filelist[i - 1];
					filelist[i - 1] = filelist[i];
					filelist[i] = tmp_file;
					flag = 1;
				}
				i++;
			}
		}
	}
	return (filelist);
}

char		**algo_desclex_strsort(t_context *context, char **filelist)
{
	char	*tmp_file;
	int		flag;
	size_t	i;

	flag = 1;
	if (filelist)
	{
		while (flag == 1)
		{
			i = 1;
			flag = 0;
			while (filelist[i])
			{
				if (ft_strcmp(filelist[i], filelist[i - 1]) > 0)
				{
					tmp_file = filelist[i - 1];
					filelist[i - 1] = filelist[i];
					filelist[i] = tmp_file;
					flag = 1;
				}
				i++;
			}
		}
	}
	return (filelist);
}














