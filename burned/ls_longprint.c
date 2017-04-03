/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_longprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 09:04:53 by obelange          #+#    #+#             */
/*   Updated: 2017/02/02 09:04:56 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	stat_print(t_lstat rstat)
{
	ft_printf("%-13s %d\n", "st_dev:", rstat.st_dev);
	ft_printf("%-13s %lld\n", "st_ino:", rstat.st_ino);
	ft_printf("%-13s %d\n", "st_mode:", rstat.st_mode);
	ft_printf("%-13s %d\n", "st_nlink:", rstat.st_nlink);
	ft_printf("%-13s %u\n", "st_uid:", rstat.st_uid);
	ft_printf("%-13s %u\n", "st_gid:", rstat.st_gid);
	ft_printf("%-13s %lld\n", "st_atimespec:", rstat.st_atimespec);
	ft_printf("%-13s %lld\n", "st_mtimespec:", rstat.st_mtimespec);
	ft_printf("%-13s %lld\n", "st_ctimespec:", rstat.st_ctimespec);
	ft_printf("%-13s %lld\n", "st_size:", rstat.st_size);
	ft_printf("%-13s %lld\n", "st_blocks:", rstat.st_blocks);
	ft_printf("%-13s %d\n", "st_blksize:", rstat.st_blksize);
	ft_printf("%-13s %u\n", "st_gen:", rstat.st_gen);
}

char	*ls_longprint_timestring(t_lstat rstat)
{
	char	*btime;	
	char	*time;

	btime = ctime((const time_t *)&rstat.st_mtimespec);	
	if (ft_strcmp(btime + 20, "2017"))
		time = ft_strsub(btime, 4, 12);
	else
	{
		time = ft_strsub(btime, 4, 7);
		time = ft_fstrmcatf(time, ft_strsub(btime, 19, 5));
	}
	return (time);
}

void	ls_longprint_totalblock(struct s_env *context, t_file **filelist)
{
	t_lstat	rstat;	
	char	*pathname;
	size_t	total;
	int		diff;

	if (!(*filelist))
		return ;
	total = 0;
	while (*filelist)
	{
		pathname = ft_fstrmcat(ls_pathname(context->path), (*filelist)->d_name);
		lstat(pathname, &rstat);
		total += rstat.st_size;
		ft_strdel(&pathname);		
		filelist++;
	}
	diff = total % 512;
	if (diff >= 256)
		total = (total / 512) + 1;
	else
		total = (total / 512);
	ft_printf("total %lu\n", total);
}

void	ls_longprint_engine(struct s_env *context, t_file **filelist, int *field)
{
	t_lstat	rstat;	
	char	*pathname;
	char	**print;

	if (!(*filelist))
		return ;
	pathname = ft_fstrmcat(ls_pathname(context->path), (*filelist)->d_name);
	lstat(pathname, &rstat);
	print = NULL;
	print = ls_longprint_update_column(print, ls_longprint_permissions(rstat), field, -99);
	print = ls_longprint_update_column(print, ft_itoa(rstat.st_nlink), field, 0);
	print = ls_longprint_update_column(print, getpwuid(rstat.st_uid)->pw_name, field, -1);
	print = ls_longprint_update_column(print, getgrgid(rstat.st_gid)->gr_name, field, -2);
	print = ls_longprint_update_column(print, ft_itoa(rstat.st_size), field, 3);
	print = ls_longprint_update_column(print, ls_longprint_timestring(rstat), field, -99);
	print = ls_longprint_update_column(print, ls_longprint_pathname(rstat, pathname, (*filelist)->d_name, print[0]), field, -99);
	ls_longprint_engine(context, ++filelist, field);	
	ft_printf("%10s %*s %*s  %*s  %*s %s %s\n", print[0], field[0],
		print[1], field[1], print[2], field[2],
		print[3], field[3], print[4], print[5], print[6]);	
	ft_strlist_del(&print);
	ft_strdel(&pathname);

}

void	ls_longprint_frame(struct s_env *context, t_file **filelist)
{
	t_lstat	rstat;
	int		field[4];
	int		i;
	int		len;	
	
	if (filelist && context)
	{
		i = 0;
		while (i < 4)
			field[i++] = 2;
		len = filelist_len(filelist);
		if (len > 1)
			ls_longprint_totalblock(context, filelist);
		filelist = context->filelist_rev_sort(context, filelist);
		ls_longprint_engine(context, filelist, field);
		filelist = context->filelist_sort(context, filelist);
	}
}
