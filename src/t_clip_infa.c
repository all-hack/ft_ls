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


void	ft_ls_cli_error(int x, char *err)
{
	if (x < 1)
	{
		write(2, err, ft_strlen(err));
		exit(1);
	}
}




t_clip	*t_clip_build(void (*error)(int, char*))
{
	t_clip	*clip;

	clip = NULL;
	if ((clip = (t_clip*)malloc(sizeof(t_clip))) == 0)
		error(0, "Error: failed to mallocate for t_clip\n");

	clip->ssignal = NULL;
	clip->lsignal = NULL;

	clip->sflags = NULL;
	clip->valid_sflags = NULL;

	clip->lflags = NULL;
	clip->args = NULL;

	clip->sflags_exe = NULL;
	clip->lflags_exe = NULL;
	clip->error = error;
	
	return (clip);
}


void	t_clip_init(t_clip	*clip)
{
	if (clip)
	{
		t_clip_build_valid_lflags(clip);
		t_clip_build_valid_args(clip);		
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
			ft_strlist_del(&(*clip)->lflags);
			ft_strlist_del(&(*clip)->args);
			free(*clip);
			*clip = NULL;
		}
	}
}














