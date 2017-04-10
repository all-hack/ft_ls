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

static	int	swap_files(t_context *context, char **strlist, int i)
{
	char	*tmp_str;

	tmp_str = strlist[i - 1];
	strlist[i - 1] = strlist[i];
	strlist[i] = tmp_str;

	return (1);
}

static	int	desc_inner_loop(t_context *context, char **strlist, int i)
{
	t_lstat	rstat;
	t_lstat	astat;
		
	lstat(strlist[i], &rstat);
	lstat(strlist[i - 1], &astat);

	if (rstat.st_mtimespec.tv_sec < astat.st_mtimespec.tv_sec)
		return (swap_files(context, strlist, i));
	else if (rstat.st_mtimespec.tv_sec == astat.st_mtimespec.tv_sec)
	{
		if (rstat.st_mtimespec.tv_nsec < astat.st_mtimespec.tv_nsec)
			return (swap_files(context, strlist, i));
		else if (rstat.st_mtimespec.tv_nsec == astat.st_mtimespec.tv_nsec)
			if (ft_strcmp(strlist[i], strlist[i - 1]) > 0)
				return (swap_files(context, strlist, i));
	}
	return (0);
}

static	int	asc_inner_loop(t_context *context, char **strlist, int i)
{
	t_lstat	rstat;
	t_lstat	astat;

	lstat(strlist[i], &rstat);
	lstat(strlist[i - 1], &astat);

	if (rstat.st_mtimespec.tv_sec > astat.st_mtimespec.tv_sec)
		return (swap_files(context, strlist, i));
	else if (rstat.st_mtimespec.tv_sec == astat.st_mtimespec.tv_sec)
	{
		if (rstat.st_mtimespec.tv_nsec > astat.st_mtimespec.tv_nsec)
			return (swap_files(context, strlist, i));
		else if (rstat.st_mtimespec.tv_nsec == astat.st_mtimespec.tv_nsec)
			if (ft_strcmp(strlist[i], strlist[i - 1]) < 0)
				return (swap_files(context, strlist, i));
	}
	return (0);
}

char		**algo_desctimes_strsort_file(t_context *context, char **strlist)
{
	int		flag;
	size_t	i;
	
	flag = 1;
	if (strlist && context)
	{				
		while (flag > 0)
		{
			i = 1;
			flag = 0;
			while (strlist[i])
			{
				flag += desc_inner_loop(context, strlist, i);
				i++;
			}
		}
	}
	return (strlist);
}

char		**algo_asctime_strsort_file(t_context *context, char **strlist)
{
	int		flag;
	size_t	i;
	
	flag = 1;
	if (strlist && context)
	{				
		while (flag > 0)
		{
			i = 1;
			flag = 0;
			while (strlist[i])
			{
				flag += asc_inner_loop(context, strlist, i);
				i++;
			}
		}
	}
	return (strlist);
}

