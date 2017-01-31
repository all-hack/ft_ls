/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clip_parse_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:49:58 by obelange          #+#    #+#             */
/*   Updated: 2017/01/28 15:50:17 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		t_clip_check_lflags(t_clip *clip, char *argv)
{
	size_t i;

	if (argv && clip)
	{
		i = 0;
		while (clip->valid_lflags[++i])
			if (ft_strcmp(argv, clip->valid_lflags[i]) == 0)
				return (1);
	}
	return (0);	
}

int		t_clip_add_lflags(t_clip *clip, char *argv)
{
	int i;

	if (argv && clip)
	{
		i = -1;
		while (clip->valid_lflags[++i])
			if (ft_strcmp(argv, clip->valid_lflags[i]) == 0)
			{
				clip->lflags[i] = '1';
				return (1);
			}
	}
	return (0);
}

int		t_clip_check_sflags(t_clip *clip, char *argv)
{
	int 	j;
	size_t	index;

	if (argv && clip)
	{
		j = -1;
		while (argv[++j])
		{
			if (ft_strchri(clip->valid_sflags, argv[j], &index))
			{
				return (1);
			}
		}
	}
	return (0);
}

int		t_clip_add_sflags(t_clip *clip, char *argv)
{
	int 	j;
	size_t	index;

	if (argv && clip)
	{
		j = -1;
		while (argv[++j])
		{
			if (ft_strchri(clip->valid_sflags, argv[j], &index))
			{
				clip->sflags[index] = '1';
				return (1);
			}
		}
	}
	return (0);
}

