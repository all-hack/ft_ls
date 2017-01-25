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


static int	t_clip_check_lflags(t_clip *clip, char *argv, int *argc)
{
	int i;

	if (argv && clip)
	{
		i = -1;
		while (clip->valid_lflags[++i])
		{
			if (ft_strcmp(argv, clip->valid_lflags[i]) == 0)
			{
				
			}
		}
	}

}




void	t_clip_parse_argv(t_clip *clip, int argc, char **argv)
{
	if (argv && clip)
	{

		while (*argv++)
		{
			if (ft_strncmp(*argv, "--", 2) == 0)
				printf("long option\n");
			else if (ft_strncmp(*argv, "-", 1) == 0)
				printf("short option\n");
			else
				printf("arguments\n");
		}


	}
	
}













