/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 03:38:15 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 03:38:25 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char				*check_newline(char *buffer)
{
	if (buffer[ft_strlen(buffer) - 1] == '\n')
		buffer[ft_strlen(buffer) - 1] = '\0';
	return (buffer);
}

char				*get_client_addr(struct sockaddr_in client)
{
	return (inet_ntoa(client.sin_addr));
}

int					get_client_port(struct sockaddr_in client)
{
	return (ntohs(client.sin_port));
}

char				*int_to_hexastring(char c)
{
	char		*res;

	res = ft_itoabase_uint(c, "0123456789ABCDEF");
	if (ft_strlen(res) < 2)
		res = ft_strjoin("0", res);
	return (res);
}

char				hexastring_to_int(char *s)
{
	char xor;

	xor = ft_atoi_base(s, 16);
	ft_strdel(&s);
	return (xor);
}
