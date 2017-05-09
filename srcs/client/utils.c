/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 01:03:28 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 01:03:41 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static int		split_size(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int				check_address_v4(char *adress)
{
	char	**split;
	int		i;
	int		tmp;

	i = 0;
	split = ft_strsplit(adress, '.');
	while (split[i])
	{
		tmp = ft_atoi(split[i]);
		if (tmp > 255 || tmp < 0)
			return (FALSE);
		i++;
	}
	return ((split_size(split) == 4) ? TRUE : FALSE);
}

char			*int_to_hexastring(char c)
{
	char		*res;

	res = ft_itoabase_uint(c, "0123456789ABCDEF");
	if (ft_strlen(res) < 2)
		res = ft_strjoin("0", res);
	return (res);
}

char			hexastring_to_int(char *s)
{
	char xor;

	xor = ft_atoi_base(s, 16);
	ft_strdel(&s);
	return (xor);
}

char				*check_newline(char *buffer)
{
	if (buffer[ft_strlen(buffer) - 1] == '\n')
		buffer[ft_strlen(buffer) - 1] = '\0';
	return (buffer);
}
