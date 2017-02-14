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

t_file		**algo_no_sort(t_context *context, t_file **filelist)
{
	return (filelist);
}

// static int	lex_loop(t_file )

t_file		**algo_asclex_sort(t_context *context, t_file **filelist)
{
	t_file	*tmp_file;
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
				if (ft_strcmp(filelist[i]->d_name, filelist[i - 1]->d_name) < 0)
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

t_file		**algo_desclex_sort(t_context *context, t_file **filelist)
{
	t_file	*tmp_file;
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
				if (ft_strcmp(filelist[i]->d_name, filelist[i - 1]->d_name) > 0)
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














