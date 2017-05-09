/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:49:51 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/09 19:49:58 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char			*serialize_data(void)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, GET_DATA_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	return (to_send);
}

void				send_get_client_data(t_client *client)
{
	if (client != NULL)
		send_data(client, serialize_data());
}


static t_file		*init_file_data(char *name, int len)
{
	t_file		*data;

	if (!(data = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	data->file = NULL;
	data->name = name;
	data->size = len;
	data->offset = 0;
	if (!(data->content = (void*)malloc(len)))
		return (NULL);
	ft_bzero(data->content, len);
	return (data);
}

void			set_receive_file(char **split, t_client *client)
{
	char	**datas;

	datas = NULL;
	if (split[1])
	{
		datas = ft_strsplit(split[1], ESCAPE_DATA[0]);
		if (datas[0] && datas[1])
		{
			if (!(client->current_file = init_file_data(datas[0], \
			ft_atoi(datas[1]))))
				return ;
			send_get_client_data(client);
			client->receiving = TRUE;
			printf("Receiving the file %s from client (%s:%d)\n", datas[0], \
			get_client_addr(client->in), get_client_port(client->in));
		}
	}
}
