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
		ls_cli_error(0, "Error: failed to mallocate for t_context\n");
	context->access_path = NULL;
	context->index = -1;
	context->chr = NULL;
	context->invalid = NULL;
	context->presentation_path = NULL;
	context->filename = NULL;
	context->pre_seed = NULL;
	return (context);
}

void	t_context_print(t_context *context)
{
	int i;

	i = 0;
	ft_printf("\n");
	ft_printf("context->access_path: %s\n", context->access_path);
	ft_printf("context->presentation_path: %s\n", context->presentation_path);
	ft_printf("context->filename: %s\n", context->filename);
	ft_printf("context->index: %d\n", context->index);
	ft_printf("context->chr: %s\n", context->chr);
	if (context->invalid)
		while (context->invalid[i])
		{
			ft_printf("context->invalid[%d]: %s\n", i, context->invalid[i]);
			i++;
		}
}

t_context	*t_context_init(t_context *context, int index, char *chr)
{
	if (context)
	{
		if (index == -1)
			context->index = 1;
		else
			context->index = index;

		if (chr)
			context->chr = chr;
		else
			context->chr = ".";
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
			ft_strdel(&(*context)->access_path);
			ft_strlist_del(&(*context)->invalid);
			free(*context);
			context = NULL;
		}
	}
}
