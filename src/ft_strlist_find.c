/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 22:43:15 by obelange          #+#    #+#             */
/*   Updated: 2017/01/24 22:43:16 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int	ft_strlist_find(char **strlist, char *str)
{
	int	i;

	i = -1;
	if (strlist && str)
	{
		while (strlist[++i])
			if (ft_strcmp(strlist[i], str) == 0)
				return (i);
		i = -1;
	}
	return (i);
}




