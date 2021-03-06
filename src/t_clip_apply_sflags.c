/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clip_apply_sflags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:48:39 by obelange          #+#    #+#             */
/*   Updated: 2017/01/28 19:48:40 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	t_clip_apply_sflags_R(t_clip *clip, t_context *context)
{
	if (context)
	{
		context->bonus_action = ls_recursion;
	}
}

void	t_clip_apply_sflags_l(t_clip *clip, t_context *context)
{
	if (context)
	{
		context->filelist_action = ls_longprint_frame;	
	}
}

void	t_clip_apply_sflags_t(t_clip *clip, t_context *context)
{
	if (context)
	{
		context->filelist_sort = algo_asctime_sort;
		context->filelist_rev_sort = algo_desctime_sort;
		context->arg_timesort = algo_asctime_strsort;
		context->file_timesort = algo_asctime_strsort_file;
	}
}

void	t_clip_apply_sflags_r(t_clip *clip, t_context *context)
{
	if (context)
	{
		if (clip->sflags[1] == '1')
		{
			context->filelist_sort = algo_desctime_sort;
			context->filelist_rev_sort = algo_asctime_sort;
			context->arg_timesort = algo_desctimes_strsort;
			context->file_timesort = algo_desctimes_strsort_file;
		}
		else 
		{
			context->filelist_sort = algo_desclex_sort;
			context->filelist_rev_sort = algo_asclex_sort;
			context->arg_sort = algo_desclex_strsort;
		}
		
	}
}

void	t_clip_apply_sflags_a(t_clip *clip, t_context *context)
{
	if (context)
	{
		context->chr = "";
		context->invalid = ft_strlist_remove(context->invalid, ".");
		context->invalid = ft_strlist_remove(context->invalid, "..");
		// ft_strlist_del(&(context->invalid));
	}
}
