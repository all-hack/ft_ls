/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_t_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:44:53 by obelange          #+#    #+#             */
/*   Updated: 2017/01/20 13:44:54 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_context	*t_context_add_path(t_context *context, char *curr_path)
{
	char	*tmp_path;

	if (curr_path && context)
	{
		if (*curr_path != '/')
		{
			tmp_path = ft_fstrmcat(ft_strdup("/"), curr_path);
			context->path = ft_fstrmcat(context->path, tmp_path);
			ft_strdel(&tmp_path);
		}
		else
			context->path = ft_fstrmcat(context->path, curr_path);
	}
	return (context);
}

t_context	*t_context_minus_path(t_context *context)
{
	char	*rev;

	if (context)
	{
		rev = ft_strrchr(context->path, '/');
		if (rev)
		{
			ft_fstrinsert(&(context->path), "", rev - context->path, ft_strlen(context->path));
		}
	}
	return (context);
}











