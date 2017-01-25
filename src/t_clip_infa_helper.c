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
		if (*(clip->valid_lflags))
		{
			clip->valid_lflags[0] = "help";
			clip->valid_lflags[1] = NULL;
		}
	}
	
}

void	t_clip_build_valid_args(t_clip *clip)
{
	if (clip)
	{
		if (*(clip->valid_args))
		{
			clip->valid_args[0] = "abcdefghijklmnopqrstuwxyz0123456789";
			clip->valid_args[1] = NULL;
		}
	}
}

void	t_clip_build_sflags_apply(t_clip *clip)
{
	if (clip)
	{
		if (*(clip->sflags_apply))
		{
			clip->sflags_apply[0] = NULL;
			clip->sflags_exe = "";
		}
	}
}

void	t_clip_build_lflags_apply(t_clip *clip)
{

	if (clip)
	{
		if (*(clip->lflags_apply))
		{
			clip->lflags_apply[0] = NULL;
			clip->lflags_exe = "";
		}
	}
}

