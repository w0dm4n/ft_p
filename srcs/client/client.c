/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 01:57:20 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 01:57:30 by frmarinh         ###   ########.fr       */
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

t_client			*get_client(char *host, int port)
{
	t_client	*client;

	if (!(client = (t_client*)malloc(sizeof(struct s_client))))
		return (NULL);
	client->fd = 0;
	client->connected = FALSE;
	client->remote_host = host;
	client->remote_port = port;
	client->current_file = NULL;
	client->len = 0;
	ft_bzero(client->tmp, CLIENT_READ);
	return (client);
}

static void			read_entry(char *entry, t_client *client)
{
	if ((read(STDIN_FILENO, entry, CLIENT_READ)) > 0)
	{
		if ((handle(entry, client) == TRUE))
			print_prompt(client);
		ft_bzero(entry, CLIENT_BUFFER);
	}
}

void				init_client(t_client *client)
{
	int			res;
	char		entry[CLIENT_BUFFER];

	res = 0;
	ft_bzero(entry, CLIENT_BUFFER);
	while (client->connected != FALSE)
	{
		FD_ZERO(&client->read_fds);
		FD_SET(client->fd, &client->read_fds);
		FD_SET(STDIN_FILENO, &client->read_fds);
		res = select(client->fd + 1, &client->read_fds, NULL, NULL, NULL);
		if (res == -1)
			print_error("An error occured with the select", -1);
		if (FD_ISSET(STDIN_FILENO, &client->read_fds))
			read_entry(entry, client);
		if (FD_ISSET(client->fd, &client->read_fds))
			if ((read_server(client)) <= 0)
				print_error("You have been disconnected from the server", -1);
	}
}
