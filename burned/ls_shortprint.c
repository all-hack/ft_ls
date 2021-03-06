/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fileprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:36:56 by obelange          #+#    #+#             */
/*   Updated: 2017/02/04 08:36:58 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char	*ls_recurse_pathname(char *str)
{
	char	*pathname;

	pathname = NULL;
	if (str)
	{
		if (ft_strcmp(str, ".") == 0)
			pathname = ft_strdup("");
		else if (ft_strncmp(str, "./", 2) == 0)
			pathname = ft_strsub(str, 2, ft_strlen(str) - 2);
		else
			pathname = ft_strdup(str);		
	}
	return (pathname);
}

char	*ls_pathname(char *str)
{
	char	*pathname;

	pathname = NULL;
	if (str)
	{
		if (ft_strcmp(str, ".") == 0)
			pathname = ft_strdup("");
		else if (ft_strncmp(str, "./", 2) == 0)
			pathname = ft_fstrmcat(ft_strsub(str, 2, ft_strlen(str) - 2), "/");
		else
			pathname = ft_fstrmcat(ft_strdup(str), "/");		
	}
	return (pathname);
}

void	ls_shortprint(struct s_env *context, t_file **filelist)
{
	if (context && filelist)
	{
		while (*filelist)
		{	
			ft_putstr((*filelist)->d_name); 	
			ft_putstr("\n");
			filelist++;
		}
	}
}
