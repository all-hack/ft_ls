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

t_context	*t_context_init(char *path, int index, char *chr, char **invalid)
{
	t_context	*context;

	context = NULL;
	if (path)
	{
		context = (t_context*)malloc(sizeof(t_context));
		context->path = ft_strdup(path);		
		if (index == -1)
			context->index = 1;
		else
			context->index = index;

		if (chr)
			context->chr = chr;
		else
			context->chr = "abcdefghijklmnopqrstuwxyz0123456789";

		context->invalid = invalid;
	}

	return (context);
}

void	t_context_free(t_context **context)
{
	if (context)
	{
		if (*context)
		{
			if ((*context)->path)
				free((*context)->path);
			free(*context);
			context = NULL;
		}
	}
}