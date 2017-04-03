/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clip_infa_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:15:59 by obelange          #+#    #+#             */
/*   Updated: 2017/01/21 17:16:00 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	t_clip_build_valid_lflags(t_clip *clip)
{
	if (clip)
	{					
		clip->valid_lflags[0] = "help";
		clip->valid_lflags[1] = NULL;
	}
}

void	t_clip_build_valid_sflags(t_clip *clip)
{
	if (clip)
	{
		clip->valid_sflags = "Rtlra";
	}
}

void	t_clip_build_sflags_apply(t_clip *clip)
{
	if (clip)
	{
		clip->sflags_apply[0] = t_clip_apply_sflags_R;
		clip->sflags_apply[1] = t_clip_apply_sflags_t;
		clip->sflags_apply[2] = t_clip_apply_sflags_l;
		clip->sflags_apply[3] = t_clip_apply_sflags_r;
		clip->sflags_apply[4] = t_clip_apply_sflags_a;
		clip->sflags_apply[5] = NULL;
		clip->sflags = ft_strdup("00000");
	}
}

void	t_clip_build_lflags_apply(t_clip *clip)
{
	if (clip)
	{
		clip->lflags_apply[0] = t_clip_apply_lflags_help;
		clip->lflags_apply[1] = NULL;
		clip->lflags = ft_strdup("0");
	}
}
