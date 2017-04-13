/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:03:52 by obelange          #+#    #+#             */
/*   Updated: 2017/03/17 11:03:54 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char	*extract_access_path(char *str)
{
	char 	*rstr;
	char	*access_path;
	int		diff;

	if (str)
	{		
		rstr = ft_strrchr(str, '/');
		if (rstr)
		{
			diff = rstr - str;			
			if (diff == 0)
				return (ft_strdup("/"));
			access_path = ft_strnew(diff);
			ft_strncpy(access_path, str, diff);
			return (access_path);
		}
	}
	return (ft_strdup("."));
}

char	*extract_filename(char *str)
{
	char	*filename;

	if (str)
	{
		if((filename = ft_strrchr(str, '/')) == NULL)
			return (ft_strdup(str));
		if (ft_strlen(filename) > 1)
			return (ft_strdup(filename + 1));
		else
			return (ft_strdup("."));
	}
	return (NULL);
}


void	find_file(t_context *context, t_file **filelist)
{
	t_file	*list[2];
	int		i;

	if (filelist)
	{
		i = -1;
		while (filelist[++i])
		{
			if (ft_strcmp((filelist[i])->d_name, context->filename) == 0)
			{
				list[0] = filelist[i];
				list[1] = NULL;
				// context->bonus_action(context, list);
				filelist[0] = filelist[i];
				while (*++filelist)
					*filelist = NULL;
				return ;
			}			
		}
		ft_printf("ls: %s: is not an existing file.\n", context->filename);
		while (*filelist)
			*filelist++ = NULL;
	}
}



// t_file	*find_file(DIR *der, char *filename, char *str)
// {
// 	t_file *file;

// 	if (der)
// 	{
// 		while ((file = readdir(der)))
// 		{
// 			if (ft_strcmp(file->d_name, filename) == 0)
// 				return (file);
// 		}
// 		ft_printf("%s: No such file or directory", str);
// 	}
// 	return (NULL);

// }

// void	handle_files(t_context *context, char **strlist, t_file **filelist)
// {
// 	char	*access_path;
// 	DIR 	*der[ft_strlist_len(strlist) + 1];
// 	int		i;
// 	char	*filename;
// 	t_file	*file;

// 	i = -1;
// 	ft_bzero(der, sizeof(DIR*) * (ft_strlist_len(strlist) + 1));	
// 	while (strlist[++i])
// 	{
// 		access_path = extract_access_path(strlist[i]);
// 		filename = extract_filename(strlist[i]);
// 		printf("access_path: %s, filename: %s\n", access_path, filename);
// 		if ((der[i] = opendir(access_path)))
// 		{
// 			filelist = filelist_addfile(filelist, find_file(der[i], filename, strlist[i]), filelist_len(filelist));
// 			// context->filelist_sort(context, filelist);
// 		}
// 		else			
// 			perror(strlist[i]);
// 	}

// 	filelist_print(filelist);
// 	while (--i > -1)
// 		if (der[i] != NULL)
// 			closedir(der[i]);
// }

char	**extract_dir_str(char ***strlist)
{	
	char	**strdir;
	DIR 	*der;
	int		i;
	char	*str;

	strdir = NULL;
	if (strlist && *strlist)
	{
		i = -1;
		while ((*strlist)[++i])
		{
			str = (*strlist)[i];
			if ((der = opendir(str)))
			{
				strdir = ft_strlist_add(strdir, str);
				*strlist = ft_strlist_remove(*strlist, str);
				i--;
				closedir(der);
			}
		}
	}
	return (strdir);
}


// t_file	*find_a_file(DIR *der, char *filename, char *str)
// {	
// 	t_file	*file;

// 	if (der && filename)
// 	{	
// 		while ((file = readdir(der)))
// 		{
// 			if (ft_strcmp(file->d_name, filename) == 0)
// 			{	
// 				return (file);
// 			}
// 		}
// 		ft_printf("ls: %s: is not an existing file.\n", str);
// 	}
// 	return (NULL);
// }

int		file_does_exist(DIR *der, char *filename, char *str)
{
	t_file	*file;

	if (der && filename)
	{	
		while ((file = readdir(der)))
		{
			if (ft_strcmp(file->d_name, filename) == 0)
			{	
				return (1);
			}
		}
		ft_printf("ls: %s: No such file or directory\n", str);
	}
	return (0);
}

// void	perform_ls_files(t_context *context, char **strlist)
// {
// 	DIR 	*der[ft_strlist_len(strlist) + 1];
// 	int		i;
// 	char	*filename;	
// 	t_file	**filelist;
// 	char	**good_args;
// 	int size;


// 	strlist = context->arg_sort(context, strlist);
// 	strlist = context->arg_timesort(context, strlist);
// 	i = -1;
// 	ft_bzero(der, sizeof(DIR*) * (ft_strlist_len(strlist) + 1));
// 	filelist = NULL;
// 	while (strlist[++i])
// 	{
// 		filename = extract_filename(strlist[i]);
// 		// printf("access_path: %s, filename: %s\n", access_path, filename);
// 		if ((der[i] = opendir(extract_access_path(strlist[i]))))
// 		{
// 			size = filelist_len(filelist);
// 			filelist = filelist_addfile(filelist, find_a_file(der[i], filename, strlist[i]), filelist_len(filelist));
// 			if (size < filelist_len(filelist))
// 				ft_strlist_add(good_args, strlist[i]);

// 		}
// 		else
// 			perror(strlist[i]);

// 	}


// 	if (filelist)
// 	{

// 		context->presentation_path = 
// 		context->filelist_action(context, filelist);
// 	}

// 	while (--i > -1)
// 	{
// 		if (der[i] != NULL)
// 			closedir(der[i]);
// 	}
// }

char	**extract_valid_files(t_context *context, char **strlist)
{
	int		i;
	char	**good_args;
	DIR		*der;

	i = -1;
	good_args = NULL;
	while (strlist[++i])
	{
		der = NULL;
		if ((der = opendir(extract_access_path(strlist[i]))))
		{
			if (file_does_exist(der, extract_filename(strlist[i]), strlist[i]))
				good_args = ft_strlist_add(good_args, strlist[i]);
		}
		else
			perror(strlist[i]);
		if (der != NULL)
			closedir(der);
	}
	return (good_args);
}


void	perform_ls_files(t_context *context, char **strfile)
{
	if (strfile)
	{
		// printf("perform_ls_files 0\n");
		strfile = context->arg_sort(context, strfile);
		// printf("perform_ls_files 1\n");
		strfile = extract_valid_files(context, strfile);
		// printf("perform_ls_files 2\n");
		// printf("args: \n");
		// ft_strlist_print(strfile);
		if (strfile && *strfile)
		{
			strfile = context->file_timesort(context, strfile);
			// printf("perform_ls_files 3\n");
			while (*strfile)
			{
				context->access_path = extract_access_path(*strfile);
				context->presentation_path = *strfile;		
				context->pre_seed = context->presentation_path;
				context->filename = extract_filename(*strfile++);
				ls_engine(context);		
			}
			context->pre_seed = NULL;
		}
	}
}

void	perform_ls_dir(t_context *context, char **strdir)
{	
	int	i;

	if (strdir)
	{
		i = 1;
		strdir = context->arg_sort(context, strdir);
		strdir = context->arg_timesort(context, strdir);
		while (*strdir)
		{
			if (i == 0)
				ft_printf("\n");
			else
				i = 0;
			context->access_path = *strdir;
			ft_printf("%s:\n", *strdir++);
			ls_engine(context);
		}
	}
}


void	handle_arguments(t_clip *clip, t_context *context)
{
	char	**strdir;
	char	**strfile;
	void	(*tmp)(struct s_env *, t_file **);

	strdir = NULL;
	context->pre_seed = NULL;
	// clip->args = context->arg_sort(context, clip->args);
	strdir = extract_dir_str(&clip->args);
	strfile = clip->args;

	tmp = context->bonus_action;
	context->bonus_action = context->filelist_action;
	context->filelist_action = find_file;	

	if (strfile && *strfile)
		perform_ls_files(context, strfile);

	if (ft_strlist_len(strfile) > 0 && ft_strlist_len(strdir) > 0)	
		ft_printf("\n");
		
	context->filelist_action = context->bonus_action;
	context->bonus_action = tmp;
	if (strdir && *strdir)
	{
		context->access_path = *strdir;
		if (ft_strlist_len(strdir) + ft_strlist_len(strfile) == 1)
		{
			ls_engine(context);
		}
		else
		{
			perform_ls_dir(context, strdir);			
		}
	}
}





