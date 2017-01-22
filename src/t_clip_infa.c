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

void	ft_strlistdel(char	***strlist)
{
	size_t	i;

	if (strlist)
	{
		if (*strlist)
		{
			i = 0;
			while ((*strlist)[i])
				ft_strdel(&((*strlist)[i]));
			free(*strlist);
			*strlist = NULL;  
		}
	}
}



t_clip	*t_clip_build(void (*error)(int, char*))
{
	t_clip	*clip;

	if ((clip = (t_clip*)malloc(sizeof(t_clip))) == 0)
		error(0, "failed to mallocate for t_clip\n");

	clip->ssignal = NULL;
	clip->lsignal = NULL;
	clip->sflags = NULL;
	clip->valid_sflags = NULL;
	clip->lflags = NULL;
	clip->valid_lflags[0] = NULL;
	clip->args = NULL;
	clip->valid_args[0] = NULL;
	clip->sflags_exe = NULL;
	clip->lflags_exe = NULL;
	clip->sflags_apply[0] = NULL;
	clip->lflags_apply[0] = NULL;
	clip->error = error;
	
	return (clip);
}


t_clip	*t_clip_init()
{
	
}


void	t_clip_destroy(t_clip **clip)
{
	if (clip)
	{
		if (*clip)
		{
			ft_strdel(&(*clip)->sflags);
			ft_strlistdel(&(*clip)->lflags);
			ft_strlistdel(&(*clip)->args);
			free(*clip);
			*clip = NULL;
		}
	}
}














