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
	
typedef struct	s_node
{
	char			*name;
	char			*path;	
	size_t			path_size;
	size_t			size;	
}				t_node;

typedef struct dirent t_filelist;
typedef struct stat t_lstat;

void ft_ls_error(int k, char *err);

void	t_node_print(t_node *node);

t_node	*t_node_init(char *name, char *path);
void	t_node_clean(t_node **node);
void	t_node_add_node(t_node *node, char *name);
void	t_node_remove_node(t_node *node);

void	t_filelist_print(t_filelist **list);
t_filelist	**t_filelist_append(t_filelist **list, t_filelist *file, size_t size);
t_filelist	**t_filelist_make(DIR	*der, int (*t_filelist_name_validator)(char*, char**), char **invalid_names);
int		t_filelist_name_validator(char *file_name, char	**invalid_name);

# include						<stdio.h>
#endif



