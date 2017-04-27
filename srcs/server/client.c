/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 03:37:14 by frmarinh          #+#    #+#             */
/*   Updated: 2017/04/27 03:37:20 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char				*get_client_addr(struct sockaddr_in client)
{
	return (inet_ntoa(client.sin_addr));
}

int					get_client_port(struct sockaddr_in client)
{
	return (ntohs(client.sin_port));
}

t_client			*alloc_new_client(SOCKET sock, struct sockaddr_in in)
{
	t_client	*client;

	if (!(client = (t_client*)malloc(sizeof(t_client))))
		return (NULL);
	client->fd = sock;
	client->in = in;
	return (client);
}

void				accept_client(t_server *server)
{
	t_client			*client;
	socklen_t			length;
	SOCKET				sock;
	struct sockaddr_in	in;
	pid_t				child_pid;

	length = sizeof(in);
	if ((sock = \
		accept(server->fd, (struct sockaddr*)&in, &length)) == -1)
		print_error("Can't accept one client connection", 0);
	else
	{
		if (!(client = alloc_new_client(sock, in)))
			return ;
		child_pid = fork();
		if (child_pid == 0)
			child(client);
	}
}