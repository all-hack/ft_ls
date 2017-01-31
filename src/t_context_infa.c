/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infa_t_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:12:47 by obelange          #+#    #+#             */
/*   Updated: 2017/01/19 20:12:48 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_context	*t_context_build()
{
	t_context	*context;

	context = NULL;
	if ((context = (t_context*)malloc(sizeof(t_context))) == 0)
		ft_ls_cli_error(0, "Error: failed to mallocate for t_context\n");
	context->path = NULL;
	context->index = -1;
	context->chr = NULL;
	context->invalid = NULL;
	return (context);
}



t_context	*t_context_init(t_context *context, char *path, int index, char *chr)
{
	if (path && context)
	{
		context->path = ft_strdup(path);		
		if (index == -1)
			context->index = 1;
		else
			context->index = index;

		if (chr)
			context->chr = chr;
		else
			context->chr = "abcdefghijklmnopqrstuwxyz0123456789";		
		return (context);
	}
	t_context_destroy(&context);
	return (NULL);
}

void	t_context_destroy(t_context **context)
{
	if (context)
	{
		if (*context)
		{
			ft_strdel(&(*context)->path);
			// ft_strdel(&(*context)->chr);
			ft_strlist_del(&(*context)->invalid);
			free(*context);
			context = NULL;
		}
	}
}