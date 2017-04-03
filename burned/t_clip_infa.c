/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_infa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:52:06 by obelange          #+#    #+#             */
/*   Updated: 2017/01/21 14:52:07 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

t_clip	*t_clip_build(void (*error)(int, char*))
{
	t_clip	*clip;

	clip = NULL;
	if ((clip = (t_clip*)malloc(sizeof(t_clip))) == 0)
		error(0, "Error: failed to mallocate for t_clip\n");
	clip->ssignal = NULL;
	clip->lsignal = NULL;
	clip->sflags = NULL;
	clip->lflags = NULL;
	clip->args = NULL;
	clip->error = error;
	return (clip);
}

void	t_clip_init(t_clip	*clip)
{
	if (clip)
	{
		t_clip_build_valid_lflags(clip);
		t_clip_build_valid_sflags(clip);
		clip->ssignal = "-";
		clip->lsignal = "--";
		t_clip_build_sflags_apply(clip);
		t_clip_build_lflags_apply(clip);		
	}
}

void	t_clip_destroy(t_clip **clip)
{
	if (clip)
	{
		if (*clip)
		{
			ft_strdel(&(*clip)->sflags);
			ft_strdel(&(*clip)->lflags);
			ft_strlist_del(&(*clip)->args);
			free(*clip);
			*clip = NULL;
		}
	}
}
