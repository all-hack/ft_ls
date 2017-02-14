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


// dev_t		st_dev;		/* device inode resides on */
// ino_t		st_ino;		/* inode's number */
// mode_t		st_mode;	/* inode protection mode */
// nlink_t		st_nlink;	/* number of hard links to the file */
// uid_t		st_uid;		/* user-id of owner */
// gid_t		st_gid;		/* group-id of owner */
// struct timespec st_atimespec;	/* time of last access */
// struct timespec st_mtimespec;	/* time of last data modification */
// struct timespec st_ctimespec;	/* time of last file status change */
// off_t		st_size;	/* file size, in bytes */
// quad_t		st_blocks;	/* blocks allocated for file */
// u_long		st_blksize;	/* optimal file sys I/O ops blocksize */
// u_long		st_flags;	/* user defined flags for file */
// u_long		st_gen;		/* file generation number */


void	stat_print(t_lstat rstat)
{
	printf("%-13s %d\n", "st_dev:", rstat.st_dev);
	printf("%-13s %lld\n", "st_ino:", rstat.st_ino);
	printf("%-13s %d\n", "st_mode:", rstat.st_mode);
	printf("%-13s %d\n", "st_nlink:", rstat.st_nlink);
	printf("%-13s %u\n", "st_uid:", rstat.st_uid);
	printf("%-13s %u\n", "st_gid:", rstat.st_gid);
	printf("%-13s %lld\n", "st_atimespec:", rstat.st_atimespec);
	printf("%-13s %lld\n", "st_mtimespec:", rstat.st_mtimespec);
	printf("%-13s %lld\n", "st_ctimespec:", rstat.st_ctimespec);
	printf("%-13s %lld\n", "st_size:", rstat.st_size);
	printf("%-13s %lld\n", "st_blocks:", rstat.st_blocks);
	printf("%-13s %d\n", "st_blksize:", rstat.st_blksize);
	printf("%-13s %u\n", "st_gen:", rstat.st_gen);
}

// S_IRWXU
// read, write, execute/search by owner
// S_IRUSR
// read permission, owner
// S_IWUSR
// write permission, owner
// S_IXUSR
// execute/search permission, owner

// S_IRWXG
// read, write, execute/search by group
// S_IRGRP
// read permission, group
// S_IWGRP
// write permission, group
// S_IXGRP
// execute/search permission, group

// S_IRWXO
// read, write, execute/search by others
// S_IROTH
// read permission, others
// S_IWOTH
// write permission, others
// S_IXOTH
// execute/search permission, others

char	*ls_longprint_permbits(t_lstat rstat, int shift)
{
	char *perm;

	perm = ft_strdup("---");
	if (rstat.st_mode & (S_IRUSR >> shift * 3))
		perm[0] = 'r';
	if (rstat.st_mode & (S_IWUSR >> shift * 3))
		perm[1] = 'w';
	if (rstat.st_mode & (S_IXUSR >> shift * 3))
		perm[2] = 'x';
	return (perm);
}





char	*ls_longprint_permissions(t_lstat rstat)
{
	char *perm;
	int i;

	perm = ft_strdup("-");
	if (S_ISBLK(rstat.st_mode))
		perm[0] = 'b';
	else if (S_ISCHR(rstat.st_mode))
		perm[0] = 'c';
	else if (S_ISDIR(rstat.st_mode))
		perm[0] = 'd';
	else if (S_ISFIFO(rstat.st_mode))
		perm[0] = 'p';
	else if (S_ISREG(rstat.st_mode))
		;
	else if (S_ISLNK(rstat.st_mode))
		perm[0] = 'l';
	else if (S_ISSOCK(rstat.st_mode))
		perm[0] = 's';
	i = -1;
	while (++i < 3)
		perm = ft_fstrmcatf(perm, ls_longprint_permbits(rstat, i));
	return (perm);
}


char	*ls_longprint_timestring(t_lstat rstat)
{
	char	*btime;	
	char	*time;

	btime = ctime(&rstat.st_mtimespec);	
	if (ft_strcmp(btime + 20, "2017"))
		time = ft_strsub(btime, 4, 12);
	else
	{
		time = ft_strsub(btime, 4, 7);
		time = ft_fstrmcatf(time, ft_strsub(btime, 19, 5));
	}
	return (time);
}

char	**ls_longprint_update_column(char **strlist, char *str, int *field, int i)
{
	int l;
	l = ft_strlen(str);
	strlist = ft_strlist_add(strlist, str);
	if (i != -88 && i != -1 && i != -2)
		ft_strdel(&str);
	if (i == -1 || i == -2)
		i = i * -1;
	if (i > -1)
	{
		if (l > field[i])
			field[i] = l;
	}
	return (strlist);
}

char	*ls_longprint_pathname(t_lstat rstat, char *path, char *filetype)
{
	char	*pathname;

	pathname = NULL;
	if (filetype && path)
	{
		if (filetype[0] == 'l')
		{
			pathname = ft_strnew(rstat.st_size);
			readlink(path, pathname, rstat.st_size);
			pathname = ft_fstrmcatf(ft_strmcat(path, " -> "), pathname);
		}
		else
		{
			pathname = ft_strdup(path);
		}
	}
	return (pathname);
}

void	ls_longprint_totalblock(struct s_env *context, t_file **filelist)
{
	t_lstat	rstat;	
	char	*pathname;
	size_t	total;

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
	printf("total %lu\n", total / 512);
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
	print = ls_longprint_update_column(print, ls_longprint_pathname(rstat, pathname, print[0]), field, -99);
	
	ls_longprint_engine(context, ++filelist, field);	
	printf("%10s %*s %*s  %*s  %*s %s %s\n", print[0], field[0],
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

		// printf("%10s %2d %s %s %2d %s %s\n", print[0], rstat.st_nlink, print[1], print[2], rstat.st_size, print[3], print[4]);
		// ft_strlist_del(&print);
		// ft_strdel(&pathname);
		// printf("field: %p\n", field);
		// printf("*field: %p\n", *field);
		len = filelist_len(filelist);

		if (len > 1)
			ls_longprint_totalblock(context, filelist);
		
		ls_longprint_engine(context, filelist, field);
		
		// printf("field 0: %d\n", field[0]);
		// printf("field 1: %d\n", field[1]);
		// printf("field 2: %d\n", field[2]);
		// printf("field 3: %d\n", field[3]);

		// printf("field 0: %d\n", *field[0]);
		// printf("field 1: %d\n", *field[1]);
		// printf("field 2: %d\n", *field[2]);
		// printf("field 3: %d\n", *field[3]);

		// printf("field 0: %d\n", (*field)[0]);
		// printf("field 1: %d\n", (*field)[1]);
		// printf("field 2: %d\n", (*field)[2]);
		// printf("field 3: %d\n", (*field)[3]);

	}
}








