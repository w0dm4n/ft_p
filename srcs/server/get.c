/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 10:17:17 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/08 10:17:22 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char		*serialize_begin(t_file *data)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, GET_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	ft_strcat(to_send, data->name);
	ft_strcat(to_send, ESCAPE_DATA);
	ft_strcat(to_send, ft_itoa(data->size));
	ft_strcat(to_send, "\n");
	return (to_send);
}

int				get_len(int total)
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

void			*get_offset(void *buff, int offset)
{
	return (buff + offset);
}

void			get_file(char **datas, t_client *client)
{
	struct stat		*file_stat;

	file_stat = NULL;
	if (datas[1] != NULL)
	{
		if ((file_stat = check_access_file(datas[1], client)) != NULL)
		{
			if ((client->current_file = get_file_data(datas[1], \
			file_stat)) != NULL)
			{
				send_data(client, serialize_begin(client->current_file));
				printf("%sSending file name \"%s\" to client %s:%d%s\n", \
				KCYN, client->current_file->name, get_client_addr(client->in), \
				get_client_port(client->in), KNRM);
			}
		}
	}
}
