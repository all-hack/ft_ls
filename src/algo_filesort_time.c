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



t_lstat		file_stat(t_context *context, t_file *file)
{
	t_lstat	rstat;
	char	*pathname;

	if (file && context)
	{
		pathname = ft_fstrmcat(ft_strjoin(context->path, "/"), file->d_name);		
		stat(pathname, &rstat);		
	}

	return (rstat);
}


t_file		**algo_asctime_sort(t_context *context, t_file **filelist)
{
	t_file	*tmp_file;
	int		flag;
	size_t	i;
	t_lstat	rstat;
	t_lstat	astat;

	flag = 1;
	if (filelist && context)
	{
		while (flag == 1)
		{
			i = 1;
			flag = 0;
			while (filelist[i])
			{
				rstat = file_stat(context, filelist[i]);
				astat = file_stat(context, filelist[i - 1]);
				if (rstat.st_mtimespec.tv_nsec < astat.st_mtimespec.tv_nsec)
				{
					tmp_file = filelist[i - 1];
					filelist[i - 1] = filelist[i];
					filelist[i] = tmp_file;
					flag = 1;
				}
				else if (rstat.st_mtimespec.tv_nsec == astat.st_mtimespec.tv_nsec)
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

t_file		**algo_desctime_sort(t_context *context, t_file **filelist)
{
	t_file	*tmp_file;
	int		flag;
	size_t	i;
	t_lstat	rstat;
	t_lstat	astat;

	flag = 1;
	if (filelist && context)
	{
		while (flag == 1)
		{
			i = 1;
			flag = 0;
			while (filelist[i])
			{
				rstat = file_stat(context, filelist[i]);
				astat = file_stat(context, filelist[i - 1]);
				if (rstat.st_mtimespec.tv_nsec > astat.st_mtimespec.tv_nsec)
				{
					tmp_file = filelist[i - 1];
					filelist[i - 1] = filelist[i];
					filelist[i] = tmp_file;
					flag = 1;
				}
				else if (rstat.st_mtimespec.tv_nsec == astat.st_mtimespec.tv_nsec)
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











