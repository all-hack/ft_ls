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

char	*ls_longprint_pathname(t_lstat rstat, char *path, char *filename, char *filetype)
{
	char	*pathname;

	pathname = NULL;
	if (filetype && path)
	{
		// if (path[0] == '.')
		// 	filename = ft_strdup(filename);
		// else
		// 	filename = ft_strdup(path);

		if (filetype[0] == 'l')
		{
			pathname = ft_strnew(rstat.st_size);
			readlink(path, pathname, rstat.st_size);
			pathname = ft_fstrmcatf(ft_strmcat(filename, " -> "), pathname);
		}
		else
			return (ft_strdup(filename));
	}
	return (pathname);
}
