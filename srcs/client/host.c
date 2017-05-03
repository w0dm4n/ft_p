/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:29:46 by frmarinh          #+#    #+#             */
/*   Updated: 2017/03/19 05:29:47 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	*get_host(int argc, char **argv)
{
	char	**split;

	split = NULL;
	if (argc == 2)
	{
		split = ft_strsplit(argv[1], ':');
		if (split[0] != NULL)
			return ((check_address_v4(split[0])) ? split[0] : NULL);
	}
	else
		return ((check_address_v4(argv[1])) ? argv[1] : NULL);
	return (NULL);
}

int		get_port(int argc, char **argv)
{
	char	**split;

	split = NULL;
	if (argc == 2)
	{
		split = ft_strsplit(argv[1], ':');
		if (split[1] != NULL)
			return (ft_atoi(split[1]));
	}
	else
		return (ft_atoi(argv[2]));
	return (0);
}
