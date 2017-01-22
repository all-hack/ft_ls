/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearch_ov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 07:18:08 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 07:18:14 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static int	recursive_loop(char const s, char const *c)
{
	if (c)
	{
		while (*c)
			if (s == *c++)
				return (1);
		return (0);
	}
	return (-1);
}

int			ft_strsearch_ov(char const *s, char const *c)
{
	if (s && c)
	{
		if (recursive_loop(*s, c) == 0)
			return (0);
		while (*++s)
			if (recursive_loop(*s, c) == 0)
				return (0);
		return (1);
	}
	return (-1);
}
