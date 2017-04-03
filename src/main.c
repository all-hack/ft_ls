/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:03:52 by obelange          #+#    #+#             */
/*   Updated: 2017/03/17 11:03:54 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"



int main(int argc, char **argv)
{
	t_clip		*clip;
	t_context	*context;



	context = t_context_build();
	t_clip_init((clip = t_clip_build(ls_cli_error)));
	t_clip_engine(clip, context, argv);


	

	if (clip->args)
		handle_arguments(clip, context);
	else
	{
		context->access_path = ft_strdup(".");
		context->presentation_path = ft_strdup(".");
		ls_engine(context);
	}






	// ft_printf("\n");
	// ft_printf("clip: \n");
	// t_clip_print(clip);
	// ft_printf("\ncontext:");
	// t_context_print(c);

	// ft_printf("\n");

}



















