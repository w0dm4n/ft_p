/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 03:15:04 by frmarinh          #+#    #+#             */
/*   Updated: 2017/04/27 03:15:13 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_server		*get_socket(int port)
{
	t_server	*server;
	int			opt;

	opt = TRUE;
	if (!(server = (t_server*)malloc(sizeof(struct s_server))))
		return (NULL);
	if ((server->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		print_error("Can't create socket", -1);
	server->in.sin_family = AF_INET;
	server->in.sin_addr.s_addr = INADDR_ANY;
	server->in.sin_port = htons(port);
	if ((setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, \
		sizeof(opt))) < 0)
		print_error("Can't allow multiple connection on socket", -1);
	if ((bind(server->fd, (struct sockaddr *)&server->in, \
		sizeof(server->in))) < 0)
		print_error("Can't bind socket", -1);
	if ((listen(server->fd, 3)) == -1)
		print_error("Can't listen the socket", -1);
	printf("ft_p launched on port %d, waiting for connections...\n", port);
	return (server);
}

void			init_server(int port)
{
	t_server	*server;

	if (port > 0 && port <= MAX_PORT)
	{
		server = get_socket(port);
		while (42)
			accept_client(server);
	}
	else
		printf("ft_p: Hey ! Give me a real port..\n");
}
