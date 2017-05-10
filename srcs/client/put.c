/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:12:33 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/09 18:13:17 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char				*get_ptr(char *file, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		file++;
		i++;
	}
	file++;
	return (file);
}

char					*check_file_name(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	while (i > 0)
	{
		if (file[i] == '/')
			return (get_ptr(file, i));
		i--;
	}
	return (file);
}

static char				*serialize_put_begin(t_file *data)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, PUT_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	ft_strcat(to_send, check_file_name(data->name));
	ft_strcat(to_send, ESCAPE_DATA);
	ft_strcat(to_send, ft_itoa(data->size));
	return (to_send);
}

bool					send_put_command(t_client *client, char *file)
{
	struct stat		*file_stat;

	file_stat = NULL;
	if (client != NULL && file != NULL)
	{
		if ((file_stat = check_access_file(file, client)) != NULL)
		{
			if ((client->current_file = get_file_data(file, \
			file_stat)) != NULL)
			{
				send_data(client, serialize_put_begin(client->current_file));
				printf("%sSending file name \"%s\" to server..\n", \
				KCYN, client->current_file->name);
				client->sending = TRUE;
			}
		}
		else
			print_prompt(client);
	}
	else
		print_prompt(client);
	return (FALSE);
}
