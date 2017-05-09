/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:27:17 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/08 14:27:24 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int					get_len_client(int total)
{
	if (total <= 1024)
		return (total);
	else if (total <= 10024)
		return (1024);
	else if (total <= 100024)
		return (10024);
	else if (total <= 100024)
		return (10024);
	else
		return (10024);
}

void				handle_receive_file(t_client *client, void *buffer, int len)
{
	ft_memcpy(client->current_file->content + client->current_file->offset, \
	buffer, len);
	client->current_file->offset += len;
	if (client->current_file->offset >= client->current_file->size)
	{
		if (client->current_file->offset <= 1024)
			print_received_file(client);
		printf("\033[%dB", get_line());
		printf("The file %s was downloaded successfully !\n", \
		client->current_file->name);
		end_file(client);
		return ;
	}
	print_received_file(client);
	send_get_file_data(client);
	ft_bzero(buffer, CLIENT_BUFFER);
}

static char			*serialize_data(void)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, GET_DATA_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	return (to_send);
}

void				send_get_file_data(t_client *client)
{
	if (client != NULL)
		send_data(client, serialize_data());
}
