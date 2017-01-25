/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:06:02 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:06:06 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
	
typedef struct	s_env
{
	char	*path;
	char	*chr;
	int		index;
	char	**invalid;
	
}				t_context;

typedef	struct 	s_clip
{
	char		*ssignal;
	char		*lsignal;
	char		*sflags;
	char		*valid_sflags;
	char		**lflags;
	char		*valid_lflags[2];
	char		**args;
	char		*valid_args[2];
	char		*sflags_exe;
	char		*lflags_exe;
	void		(*sflags_apply[0]) (void);
	void		(*lflags_apply[0]) (void);
	void		(*error)(int, char*);
}				t_clip;

typedef struct dirent t_file;
typedef struct stat t_lstat;


t_context	*t_context_init(char *path,  int index, char *chr, char **invalid);
t_context	*t_context_add_path(t_context *context, char *curr_path);
void		t_context_free(t_context **context);

t_clip		*t_clip_build(void (*error_apply)(int, char*));
void		t_clip_init(t_clip	*clip);
void		t_clip_build_valid_lflags(t_clip *clip);
void		t_clip_build_valid_args(t_clip *clip);
void		t_clip_build_sflags_apply(t_clip *clip);
void		t_clip_build_lflags_apply(t_clip *clip);
void		t_clip_destroy(t_clip **clip);


t_file		**filelist_init(t_context *context, char *filename);
t_file		**filelist_addfile(t_file **filelist, t_file *file, size_t size);
t_file		**filelist_build(size_t size);
void		filelist_destroy(t_file	**filelist);

int			file_validate(t_context *context, t_file *file);

void		ft_ls_cli_error(int x, char *err);

int			ft_strsearch_ov(char const *s, char const *c);

char		**ft_strlist_build(size_t size);
char		**ft_strlist_add(char **strlist, char *str);
char		**ft_strlist_minus(char **strlist);
char		**ft_strlist_remove(char **strlist, char *str);
int			ft_strlist_find(char **strlist, char *str);
void		ft_strlist_print(char **strlist);
size_t		ft_strlist_len(char	**strlist);
void		ft_strlist_del(char	***strlist);







# include						<stdio.h>
#endif



