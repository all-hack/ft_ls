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
		if (!(ft_strsearch_ov(tmp_dirent, context->chr)))
			return (0);
		if (context->invalid)
			while (context->invalid[i])
			{
				if (ft_strcmp(context->invalid[i], file->d_name) == 0)
					return (0);
				i++;
			}
		return (1);
	}
	return (0);
}


























