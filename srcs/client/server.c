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
		printf("%s\n", msg);
		print_prompt(client);
	}
}

int			read_server(t_client *client)
{
	int			res;
	char		buffer[CLIENT_BUFFER];

	res = recv(client->fd, buffer, CLIENT_READ, 0);
	if (res > 0)
	{
		buffer[res] = '\0';
		from_server(decrypt_message(buffer), client);
		ft_bzero(buffer, CLIENT_BUFFER);
	}
	return (res);
}
