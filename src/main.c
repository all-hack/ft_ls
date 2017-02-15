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
	// printf("hdfoiahfoh\n");
	if (context && filename)
	{		
		// t_context_add_path(context, filename);
		// printf("context->path: %s\n", context->path);

		if ((add = ft_strrchr(filename, '/')) != NULL)
		{
			// printf("context: %s\n", context->path);
			// printf("add: %p\n", add);
			// printf("add: %d\n", add);
			// printf("add: %s\n", add);
			// printf("diff: %d\n", add - filename);
			context->path = ft_fstrmcatf(ls_pathname(context->path), ft_strsub(filename, 0, add - filename));			
		}
		// printf("a context: %s\n", context->path);
		// printf("add: %s\n", add);
		// printf("diff: %d\n", add - filename);

		// if (ft_strchri(filename, '/', &j) == 1)
		// 	ft_strmcatf(context->path, )

		if ((filelist = filelist_init(context, context->path, &der)) == NULL)
			printf("%s: is not an existing file.\n\n", filename);
		// t_context_add_path(context, filename);
		// printf("jhh\n");
		i = -1;
		// filelist_print(filelist);
		if (filelist)
			while (filelist[++i])
			{
				// printf("%s == %s\n", (*filelist)->d_name, filename);
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
		// printf("foidfhoah\n");
		// filelist_print(file);

		if (file)
			context->filelist_action(context, file);
		else
			printf("%s: is not an existing file.\n\n", filename);

		
		
		// free(file);
		// free(filelist);
		filelist_destroy(&file);
		filelist_destroy(&filelist);
		if (der)
			closedir(der);
		// t_context_minus_path(context);
		// printf("end\n");
	}
}




int	main(int argc, char **argv)
{
	t_clip		*clip;
	t_context	*context;
	char		**dirList;
	int			i;

	context = t_context_build();
	t_clip_init((clip = t_clip_build(ls_cli_error)));
	t_clip_engine(clip, context, argv);

	// ft_strlist_print(clip->args);


	// ls_engine(context);
	// printf("get\n\n\n");
	dirList = NULL;
	dirList = algo_asclex_strsort(context, ls_get_directories(context, &clip->args));
	clip->args = algo_asclex_strsort(context, clip->args);
	
	// ft_strlist_print(clip->args);
	// printf("get\n\n\n");
	// ft_strlist_print(dirList);
	// context->sort
	i = -1;
	if (clip->args || dirList)
	{
		if (clip->args)
			while ((clip->args)[++i])
			{
				// printf("context->path: %s\n", context->path);
				ls_args_handleFile(context, (clip->args)[i]);
			}

		i = -1;
		if (dirList)
			while (dirList[++i])
			{
				// printf("%s\n", );
				t_context_add_path(context, dirList[i]);
				ls_engine(context);
				t_context_minus_path(context);
			}
	}
	else
		ls_engine(context);

	t_context_destroy(&context);
	ft_strlist_del(&dirList);
	

	t_clip_destroy(&clip);

	return (0);
}




