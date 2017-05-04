/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 02:48:12 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 02:48:16 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		from_server(char *msg, t_client *client)
{
	char	**split;

	split = ft_strsplit(msg, ESCAPE_CHAR[0]);
	if (split[0] != NULL)
	{
		if (!ft_strcmp(split[0], PWD_MESSAGE))
			print_pwd(split, client);
		else if (!ft_strcmp(split[0], INFO_MESSAGE))
			print_info(split, client);
		else if (!ft_strcmp(split[0], LS_MESSAGE))
			print_ls(split);
	}
}

int			read_server(t_client *client)
{
	int			res;
	char		buffer[CLIENT_BUFFER];
	char		**result;
	int			i;

	i = 0;
	result = NULL;
	res = recv(client->fd, buffer, CLIENT_READ, 0);
	if (res > 0)
	{
		buffer[res] = '\0';
		result = ft_strsplit(buffer, '\n');
		while (result[i])
			from_server(result[i++], client);
		ft_bzero(buffer, CLIENT_BUFFER);
	}
	return (res);
}
