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
		else if (!ft_strcmp(split[0], GET_MESSAGE))
			set_get_file(split, client);
		else if (!ft_strcmp(split[0], EOF_MESSAGE))
			end_file(client);
		else if (!ft_strcmp(split[0], GET_DATA_MESSAGE))
			send_file_data(client, client->current_file);
	}
}

int			get_real_len(t_file *file)
{
	int part_len;

	part_len = get_len_client(file->size);
	if ((file->offset + part_len) > file->size)
		part_len = -(file->offset - file->size);
	return (part_len);
}

static int	receiving_file(t_client *client, char *buffer, int res)
{
	client->len += res;
	ft_memcpy(client->tmp, buffer, res);
	if (client->len >= get_real_len(client->current_file))
	{
		handle_receive_file(client, (void*)client->tmp, client->len);
		client->len = 0;
		ft_bzero(client->tmp, CLIENT_READ);
	}
	return (res);
}

static int	handle_file(t_client *client, char *buffer, int res)
{
	if (client->receiving == TRUE)
		return (receiving_file(client, buffer, res));
	else if (client->sending == TRUE)
	{
		send_file_data(client, client->current_file);
		return (res);
	}
	return (res);
}

int			read_server(t_client *client)
{
	int			res;
	char		buffer[CLIENT_BUFFER];
	char		**result;
	int			i;
	int			len;

	i = 0;
	len = 0;
	result = NULL;
	res = recv(client->fd, buffer, CLIENT_READ, 0);
	if (res > 0)
	{
		if (client->current_file != NULL)
			return (handle_file(client, buffer, res));
		buffer[res] = '\0';
		result = ft_strsplit(buffer, '\n');
		while (result[i])
			from_server(result[i++], client);
		if (result[1] != NULL)
			ft_bzero(buffer, CLIENT_BUFFER);
	}
	return (res);
}
