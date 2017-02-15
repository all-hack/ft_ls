/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clip_apply_lflags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:48:50 by obelange          #+#    #+#             */
/*   Updated: 2017/01/28 19:48:51 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	t_clip_apply_lflags_help(t_clip *clip, t_context *context)
{
	printf("\x1b[33mft_ls is a program that displays the contents of directorie\
s.\n\x1b[32mUsage: ./ft_ls -[Rtlra] --[help] ARG\n");
	t_context_destroy(&context);
	t_clip_destroy(&clip);
	exit (1);
}



