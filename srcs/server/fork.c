/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:13:35 by frmarinh          #+#    #+#             */
/*   Updated: 2017/04/27 04:13:43 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static void		print_received(t_client *client, char *buffer)
{
	printf("%sReceived message from client (%s:%d): %s%s\n", KMAG, \
	get_client_addr(client->in), get_client_port(client->in), \
		buffer, KNRM);
}

static void		close_child(t_client *client)
{
	close(client->fd);
	printf("%sOne client disconnected (%s:%d)%s\n", KRED, \
	get_client_addr(client->in), get_client_port(client->in), KNRM);
	exit(0);
}

void			child(t_client *client)
{
	char		buffer[CLIENT_BUFFER];
	int			res;

	res = 0;
	ft_bzero(buffer, CLIENT_READ);
	printf("%sNew client connected from %s:%d%s\n", KGRN, \
	get_client_addr(client->in), get_client_port(client->in), KNRM);
	while (42)
	{
		res = recv(client->fd, buffer, CLIENT_READ, 0);
		if (res > 0)
		{
			print_received(client, buffer);
			handle(decrypt_message(buffer), client);
			ft_bzero(buffer, CLIENT_READ);
		}
		else
			close_child(client);
	}
}