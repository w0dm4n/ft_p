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

void				send_data(t_client *client, char *msg)
{
	if (client->fd)
	{
		write(client->fd, msg, ft_strlen(msg));
		ft_bzero(msg, ft_strlen(msg));
	}
}

t_client			*alloc_new_client(SOCKET sock, struct sockaddr_in in)
{
	t_client	*client;

	if (!(client = (t_client*)malloc(sizeof(t_client))))
		return (NULL);
	client->fd = sock;
	client->in = in;
	client->connected = TRUE;
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
