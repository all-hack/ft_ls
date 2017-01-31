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




void	t_context_print(t_context *context)
{
	int i;

	i = 0;
	printf("\n");
	printf("context->path: %s\n", context->path);
	printf("context->index: %d\n", context->index);
	printf("context->chr: %s\n", context->chr);
	
	if (context->invalid)
		while (context->invalid[i])
		printf("context->invalid[%d]: %s\n", i, context->invalid[i++]);
}




void	t_clip_print(t_clip *clip)
{

	printf("t_clip->ssignal: %s\n", clip->ssignal);
	printf("t_clip->lsignal: %s\n", clip->lsignal);
	printf("t_clip->lflag: %s\n", clip->lflags);
	printf("t_clip->sflag: %s\n", clip->sflags);
	
	printf("t_clip->valid lflags:\n");
	ft_strlist_print(clip->valid_lflags);
	
	printf("t_clip->args list:\n");
	ft_strlist_print(clip->args);

}


int	main(void)
{

	t_clip	*clip;
	char	*strlist[5];
	t_context	*context;

	strlist[0] = "--help";
	strlist[1] = "--help";
	strlist[2] = "-gsdfg";
	strlist[3] = "dafaf";
	strlist[4] = NULL;

	context = t_context_build();
	t_clip_init((clip = t_clip_build(ft_ls_cli_error)));


	t_clip_engine(clip, context, strlist);


	t_clip_print(clip);
	t_context_print(context);

	

	// context = t_context_init("0", -1, NULL, str);


	
	// char		*str[3];
	// int			k;
	// t_file		**filelist;

	// str[0] = ".";
	// str[1] = "..";
	// str[2] = NULL;

	
	// t_context_print(context);
	// context = t_context_add_path(context, "abc");
	// t_context_print(context);
	// t_context_minus_path(context);
	// t_context_print(context);

	// filelist = filelist_init(context, "0/txt.txt");
	// printf("\n");

	// filelist_print(filelist);
	

	t_context_destroy(&context);
	

	t_clip_destroy(&clip);

	return (0);
}




