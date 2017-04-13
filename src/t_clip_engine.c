/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clip_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:42:57 by obelange          #+#    #+#             */
/*   Updated: 2017/01/21 18:42:59 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	t_clip_parse_argv(t_clip *clip, char **argv)
{
	if (argv && clip)
	{
		while (*++argv)
		{
			if (ft_strncmp(*argv, "--", 2) == 0)				
				t_clip_add_lflags(clip, *argv + 2);
			else if (ft_strncmp(*argv, "-", 1) == 0)
				t_clip_add_sflags(clip, *argv + 1);
			else
			{
				if (clip->arg_validator(*argv) == 1)				
					clip->args = ft_strlist_add(clip->args, *argv);
				else
					clip->error(0, "\x1b[31mthis is not a valid argument, \
please refer to --help for usage\x1b[37m\n");
			}
		}
	}
}

void	t_clip_application(t_clip *clip, t_context *context)
{
	int	i;

	i = -1;
	t_clip_apply_default(clip, context);	
	while (clip->lflags[++i])
		if (clip->lflags[i] == '1')
			clip->lflags_apply[i](clip, context);
	i = -1;
	while (clip->sflags[++i])
		if (clip->sflags[i] == '1')
			clip->sflags_apply[i](clip, context);
	
}

void	t_clip_apply_default(t_clip *clip, t_context *context)
{
	if (context)
	{
		t_context_init(context, -1, NULL);
		t_clip_nope(context);
		context->filelist_action = ls_shortprint;
		context->filelist_sort = algo_asclex_sort;
		context->arg_sort = algo_asclex_strsort;
		context->arg_timesort = algo_no_strsort;
		context->file_timesort = algo_no_strsort;
		context->filelist_rev_sort = algo_desclex_sort;
		context->bonus_action = ls_do_nothing;
	}
}

void	t_clip_engine(t_clip *clip, t_context *context, char **argv)
{
	t_clip_parse_argv(clip, argv);
	t_clip_application(clip, context);
}
