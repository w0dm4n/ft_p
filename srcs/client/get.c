/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 10:12:58 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/08 10:13:05 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void				end_file(t_client *client)
{
	char *path;

	path = NULL;
	if (client->current_file != NULL)
	{
		print_prompt(client);
		path = ft_strnew(1024);
		ft_strcat(path, "uploads/");
		ft_strcat(path, client->current_file->name);
		int fd = open(path, O_RDWR|O_CREAT, 0777); 
		if (fd != -1)
			write(fd, client->current_file->content, client->current_file->size);
		free(client->current_file->content);
		free(client->current_file);
		client->current_file = NULL;
	}
}

static char			*serialize_get(char *file)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, GET_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	ft_strcat(to_send, file);
	return (to_send);
}

bool				send_get_command(t_client *client, char *file)
{
	if (client != NULL && file != NULL)
		send_data(client, serialize_get(file));
	return (FALSE);
}

static t_file		*init_file_data(char *name, int len)
{
	t_file		*data;

	if(!(data = (t_file*)malloc(sizeof(t_file))))
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

void				set_get_file(char **split, t_client *client)
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
			send_get_file_data(client);
		}
	}
}
