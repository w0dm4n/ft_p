/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:01:03 by frmarinh          #+#    #+#             */
/*   Updated: 2017/04/20 14:04:33 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static void		connection(char *host, int port)
{
	t_client	*client;
	char		entry[CLIENT_BUFFER];

	if (!(client = get_client(host, port)))
		return ;
	if ((client->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		print_error("Can't create socket", -1);
	client->in.sin_addr.s_addr = inet_addr(host);
	client->in.sin_family = AF_INET;
	client->in.sin_port = htons(port);
	if ((connect(client->fd, (struct sockaddr*)&client->in, \
		sizeof(client->in))) < 0)
		print_error("Can't connect to remote server", -1);
	client->connected = TRUE;
	ft_bzero(entry, CLIENT_BUFFER);
	print_prompt(client);
	init_client(client);
}

int				main(int argc, char **argv)
{
	char	*host;
	int		port;

	host = NULL;
	port = 0;
	if (argc == 2 || argc == 3)
	{
		if ((host = get_host(argc, argv)) != NULL)
		{
			if ((port = get_port(argc, argv)) > 0)
				connection(host, port);
			else
				printf("ft_p client: Syntax error \"host:port\"\n");
		}
		else
			printf("ft_p client: Syntax error \"host:port\"\n");
	}
	else
		printf("ft_p client: Syntax error \"host:port\"\n");
	return (0);
}
