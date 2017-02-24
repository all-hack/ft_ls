/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:21:21 by obelange          #+#    #+#             */
/*   Updated: 2017/01/20 15:21:23 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		file_validate(t_context *context, t_file *file)
{
	char	*tmp_dirent;
	size_t	i;

	if (context && file)
	{
		i = 0;
		tmp_dirent = ft_strsub(file->d_name, 0, context->index);
		// ft_printf("tmp_dirent: %s\n", tmp_dirent);
		if (!(ft_strsearch_ov(tmp_dirent, context->chr)))
		{
			ft_strdel(&tmp_dirent);
			return (0);
		}
		if (context->invalid)
			while (context->invalid[i])
			{
				if (ft_strcmp(context->invalid[i], file->d_name) == 0)
				{
					ft_strdel(&tmp_dirent);
					return (0);
				}
				i++;
			}
		ft_strdel(&tmp_dirent);
		return (1);
	}
	return (0);
}

























