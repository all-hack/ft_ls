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
		if (*curr_path != '/' && context->access_path[ft_strlen(context->access_path) - 1] != '/')
		{
			tmp_path = ft_fstrmcat(ft_strdup("/"), curr_path);
			context->access_path = ft_fstrmcat(context->access_path, tmp_path);
			ft_strdel(&tmp_path);
		}
		else
			context->access_path = ft_fstrmcat(context->access_path, curr_path);
	}
	return (context);
}

t_context	*t_context_minus_path(t_context *context)
{
	char	*rev;

	if (context && context->access_path)
	{
		rev = ft_strrchr(context->access_path, '/');
		if (rev)
		{
			if (context->access_path[0] == '/')
				ft_fstrinsert(&(context->access_path), "", rev - context->access_path + 1, ft_strlen(context->access_path));
			else
				ft_fstrinsert(&(context->access_path), "", rev - context->access_path, ft_strlen(context->access_path));
		}
	}
	return (context);
}
