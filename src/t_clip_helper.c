/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clip_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:31:32 by obelange          #+#    #+#             */
/*   Updated: 2017/03/17 11:31:33 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	t_clip_print(t_clip *clip)
{
	ft_printf("t_clip->ssignal: %s\n", clip->ssignal);
	ft_printf("t_clip->lsignal: %s\n", clip->lsignal);
	ft_printf("t_clip->lflag: %s\n", clip->lflags);
	ft_printf("t_clip->sflag: %s\n", clip->sflags);
	ft_printf("t_clip->valid lflags:\n");
	ft_strlist_print(clip->valid_lflags);
	ft_printf("t_clip->args list:\n");
	ft_strlist_print(clip->args);
}

int		ls_arg_validator(char* str)
{
	if (str)
	{
		return (1);
	}
	return (0);
}

void	ls_cli_error(int x, char *err)
{
	if (x < 1)
	{
		write(2, err, ft_strlen(err));
		exit(1);
	}
}







