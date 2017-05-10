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

static void				print_received(t_client *client, char *buffer)
{
	buffer = encrypt_message(buffer);
	printf("%sReceived message from client (%s:%d): %s%s\n", KMAG, \
	get_client_addr(client->in), get_client_port(client->in), \
		buffer, KNRM);
}

static void				close_child(t_client *client)
{
	close(client->fd);
	printf("%sOne client disconnected (%s:%d)%s\n", KRED, \
	get_client_addr(client->in), get_client_port(client->in), KNRM);
	exit(0);
}

static void				handle_receive_file_server(t_client *client, \
void *buffer, int len)
{
	ft_memcpy(client->current_file->content + client->current_file->offset, \
	buffer, len);
	client->current_file->offset += len;
	if (client->current_file->offset >= client->current_file->size)
	{
		printf("The file %s was received successfully !\n", \
		client->current_file->name);
		end_file_server(client);
		return ;
	}
	send_get_client_data(client);
	ft_bzero(buffer, CLIENT_BUFFER);
}

static int				receiving_file(t_client *client, char *buffer, int res)
{
	client->len += res;
	ft_memcpy(client->tmp, buffer, res);
	if (client->len >= get_real_len(client->current_file))
	{
		handle_receive_file_server(client, (void*)client->tmp, client->len);
		client->len = 0;
		ft_bzero(client->tmp, CLIENT_READ);
	}
	return (res);
}

void					child(t_client *client)
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
			if (client->receiving)
				receiving_file(client, buffer, res);
			else
			{
				buffer[res] = '\0';
				print_received(client, buffer);
				handle(buffer, client);
				ft_bzero(buffer, CLIENT_READ);
			}
		}
		else
			close_child(client);
	}
}
