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
		if (clip->sflags[1] == '1')
			context->filelist_sort = algo_asctime_sort;
		else
			context->filelist_sort = algo_desclex_sort;
	}
}

void	t_clip_apply_sflags_t(t_clip *clip, t_context *context)
{
	if (context)
	{
		context->filelist_sort = algo_desctime_sort;
	}
}

void	t_clip_apply_sflags_r(t_clip *clip, t_context *context)
{
	if (context)
	{
		if (clip->sflags[2] == '1')
		{
			if (clip->sflags[1] == '1')
				context->filelist_sort = algo_desctime_sort;
			else
				context->filelist_sort = algo_asclex_sort;	
		}
		else 
		{
			if (clip->sflags[1] == '1')
				context->filelist_sort = algo_asctime_sort;
			else
				context->filelist_sort = algo_desclex_sort;
		}
		
	}
}

void	t_clip_apply_sflags_a(t_clip *clip, t_context *context)
{
	if (context)
	{
		context->chr = "\
qwertyuiopasdfghjklzxcvbnm0123456789/.QWERTYUIOPASDFGHJKLZXCVBNM";
	}
}


