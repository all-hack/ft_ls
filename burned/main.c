/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 21:03:38 by obelange          #+#    #+#             */
/*   Updated: 2017/01/19 21:03:40 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	cleanup(t_context *context, char **dirList, t_clip *clip)
{
	t_context_destroy(&context);
	ft_strlist_del(&dirList);
	t_clip_destroy(&clip);
}

void	god_damn_it(t_context *context, char **dirList, int i)
{
	char	*path;
	t_context_add_path(context, dirList[i]);
	path = ls_pathname(context->path);
	ft_printf("%s:\n", path);
	ls_engine(context);
	t_context_minus_path(context);
	ft_strdel(&path);
}

int	main(int argc, char **argv)
{
	t_clip		*clip;
	t_context	*c;
	char		**dirList;
	int			i;

	c = t_context_build();
	t_clip_init((clip = t_clip_build(ls_cli_error)));
	t_clip_engine(clip, c, argv);
	dirList = algo_asclex_strsort(c, ls_get_directories(c, &clip->args));
	clip->args = algo_asclex_strsort(c, clip->args);
	i = -1;
	if (clip->args)
		while ((clip->args)[++i])
			ls_args_handleFile(c, (clip->args)[i]);
	i = -1;
	if (dirList)
		while (dirList[++i])
		{
			if (i > 0)
				ft_printf("\n");
			god_damn_it(c, dirList, i);
		}
	if (!(clip->args || dirList))
		ls_engine(c);
	cleanup(c, dirList, clip);
	return (0);
}
