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
	ft_printf("\n");
	ft_printf("context->path: %s\n", context->path);
	ft_printf("context->index: %d\n", context->index);
	ft_printf("context->chr: %s\n", context->chr);
	
	if (context->invalid)
		while (context->invalid[i])
		ft_printf("context->invalid[%d]: %s\n", i, context->invalid[i++]);
}




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


// int ls_file_get(t_context *context, char *filename, DIR **der)
// {
// 	t_lstat	rstat;

// 	if (context && filename)
// 	{
// 		lstat(context->path, &rstat);
// 		stat_print(stat);
// 		return (1);
// 	}
// 	return (0);
// }


void	ls_args_handleFile(t_context *context, char *filename)
{
	t_file	**filelist;
	t_file	**file;
	DIR 	*der;
	char	*str;
	int		i;
	size_t	j;
	char	*add;

	filelist = NULL;
	file = NULL;
	// ft_printf("hdfoiahfoh\n");
	if (context && filename)
	{		
		// t_context_add_path(context, filename);
		// ft_printf("context->path: %s\n", context->path);

		if ((add = ft_strrchr(filename, '/')) != NULL)
		{
			// ft_printf("context: %s\n", context->path);
			// ft_printf("add: %p\n", add);
			// ft_printf("add: %d\n", add);
			// ft_printf("add: %s\n", add);
			// ft_printf("diff: %d\n", add - filename);
			context->path = ft_fstrmcatf(ls_pathname(context->path), ft_strsub(filename, 0, add - filename));			
		}
		// ft_printf("a context: %s\n", context->path);
		// ft_printf("add: %s\n", add);
		// ft_printf("diff: %d\n", add - filename);

		// if (ft_strchri(filename, '/', &j) == 1)
		// 	ft_strmcatf(context->path, )

		if ((filelist = filelist_init(context, context->path, &der)) == NULL)
			ft_printf("%s: is not an existing file.\n", filename);
		// t_context_add_path(context, filename);
		// ft_printf("jhh\n");
		i = -1;
		// filelist_print(filelist);
		if (filelist)
			while (filelist[++i])
			{
				// ft_printf("%s == %s\n", (*filelist)->d_name, filename);
				if (add)
				{
					if (ft_strcmp((filelist[i])->d_name, add + 1) == 0)
					{
						file = filelist_addfile(file, filelist[i], 0);
						break;
					}
				}
				else
					if (ft_strcmp((filelist[i])->d_name, filename) == 0)
					{
						file = filelist_addfile(file, filelist[i], 0);
						break;
					}
			}
		// ft_printf("foidfhoah\n");
		// filelist_print(file);

		if (file)
		{
			context->filelist_action(context, file);
			ft_printf("\n");
		}
		else
			ft_printf("%s: is not an existing file.\n", filename);

		
		
		// free(file);
		// free(filelist);
		filelist_destroy(&file);
		filelist_destroy(&filelist);
		if (der)
			closedir(der);
		// t_context_minus_path(context);
		// ft_printf("end\n");
	}
}




int	main(int argc, char **argv)
{
	t_clip		*clip;
	t_context	*context;
	char		**dirList;
	int			i;

	// ft_printf("0 main\n");
	context = t_context_build();
	// ft_printf("1 main\n");
	t_clip_init((clip = t_clip_build(ls_cli_error)));
	// ft_printf("2 main\n");
	t_clip_engine(clip, context, argv);
	// ft_printf("3 main\n");

	// ft_strlist_print(clip->args);


	// ls_engine(context);
	// ft_printf("get\n\n\n");
	dirList = NULL;
	dirList = algo_asclex_strsort(context, ls_get_directories(context, &clip->args));
	// ft_printf("4 main\n");
	
	clip->args = algo_asclex_strsort(context, clip->args);
	
	// ft_printf("5 main\n");
	// ft_strlist_print(clip->args);
	// ft_printf("get\n\n\n");
	// ft_strlist_print(dirList);
	// context->sort
	i = -1;
	if (clip->args || dirList)
	{
		if (clip->args)
			while ((clip->args)[++i])
			{
				// ft_printf("context->path: %s\n", context->path);
				ls_args_handleFile(context, (clip->args)[i]);
			}

		i = -1;
		if (dirList)
			while (dirList[++i])
			{
				// ft_printf("%s\n", );
				t_context_add_path(context, dirList[i]);
				ls_engine(context);
				t_context_minus_path(context);
			}
	}
	else
		ls_engine(context);

	// ft_printf("6 main\n");
	t_context_destroy(&context);
	ft_strlist_del(&dirList);
	

	t_clip_destroy(&clip);

	return (0);
}




