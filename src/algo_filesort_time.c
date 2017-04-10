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

static	void	swap_files(t_context *context, t_file **filelist, int i, int *flag)
{
	t_file	*tmp_file;

	tmp_file = filelist[i - 1];
	filelist[i - 1] = filelist[i];
	filelist[i] = tmp_file;
	*flag = 1;
}


static	void	desc_inner_loop(t_context *context, t_file **filelist, int i, int *flag)
{
	t_lstat	rstat;
	t_lstat	astat;
	
	rstat = file_stat(context, filelist[i]);
	astat = file_stat(context, filelist[i - 1]);
	if (rstat.st_mtimespec.tv_sec < astat.st_mtimespec.tv_sec)
		swap_files(context, filelist, i, flag);
	else if (rstat.st_mtimespec.tv_sec == astat.st_mtimespec.tv_sec)
	{
		if (rstat.st_mtimespec.tv_nsec < astat.st_mtimespec.tv_nsec)
			swap_files(context, filelist, i, flag);
		else if (rstat.st_mtimespec.tv_nsec == astat.st_mtimespec.tv_nsec)
			if (ft_strcmp(filelist[i]->d_name, filelist[i - 1]->d_name) > 0)
				swap_files(context, filelist, i, flag);
	}
}

static	void	asc_inner_loop(t_context *context, t_file **filelist, int i, int *flag)
{
	t_lstat	rstat;
	t_lstat	astat;
	
	rstat = file_stat(context, filelist[i]);
	astat = file_stat(context, filelist[i - 1]);
	if (rstat.st_mtimespec.tv_sec > astat.st_mtimespec.tv_sec)
		swap_files(context, filelist, i, flag);
	else if (rstat.st_mtimespec.tv_sec == astat.st_mtimespec.tv_sec)
	{
		if (rstat.st_mtimespec.tv_nsec > astat.st_mtimespec.tv_nsec)
			swap_files(context, filelist, i, flag);
		else if (rstat.st_mtimespec.tv_nsec == astat.st_mtimespec.tv_nsec)
			if (ft_strcmp(filelist[i]->d_name, filelist[i - 1]->d_name) < 0)
				swap_files(context, filelist, i, flag);
	}
}

t_file		**algo_desctime_sort(t_context *context, t_file **filelist)
{
	int		flag;
	size_t	i;
	

	flag = 1;
	if (filelist && context)
	{
		while (flag == 1)
		{
			i = 1;
			flag = 0;
			while (filelist[i])
			{
				desc_inner_loop(context, filelist, i, &flag);
				i++;
			}
		}
	}
	return (filelist);
}

t_file		**algo_asctime_sort(t_context *context, t_file **filelist)
{
	int		flag;
	size_t	i;
	

	flag = 1;
	if (filelist && context)
	{
		while (flag == 1)
		{
			i = 1;
			flag = 0;
			while (filelist[i])
			{
				asc_inner_loop(context, filelist, i, &flag);
				i++;
			}
		}
	}
	return (filelist);
}

