/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 10:48:58 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/08 10:49:04 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static void			send_end_of_file(t_client *client, t_file *data)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return ;
	ft_strcat(to_send, EOF_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	send_data(client, to_send);
}

void				send_file_data(t_client *client, t_file *file)
{
	int		part_len;
	bool	over;

	over = FALSE;
	if (client->current_file == NULL)
		return;
	part_len = get_len(file->size);
	if ((file->offset + part_len) > file->size)
	{
		part_len = -(file->offset - file->size);
		over = TRUE;
	}
	write(client->fd, get_offset(file->content, file->offset), part_len);
	file->offset += part_len;
	printf("File [%s]: [%d/%d] bytes sent\n", file->name, \
	file->offset, file->size);
	if (over)
	{
		if (client->current_file != NULL)
		{
			free(client->current_file->content);
			free(client->current_file);
			client->current_file = NULL;
		}
	}
}

static t_file		*init_file_data(char *name, struct stat *file_stat)
{
	t_file		*data;

	if(!(data = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	data->file = file_stat;
	data->name = name;
	data->size = file_stat->st_size;
	data->offset = 0;
	data->content = NULL;
	return (data);
}

t_file				*get_file_data(char *name, struct stat *file_stat)
{
	t_file		*file_data;
	int			fd;
	int			res;

	fd = 0;
	res = 0;
	if (!(file_data = init_file_data(check_newline(name), file_stat)))
		return (NULL);
	if ((fd = open(name, O_RDONLY)) <= 0)
		return (NULL);
	if (!(file_data->content = ft_strnew(file_data->size + 1)))
		return (NULL);
	res = read(fd, file_data->content, file_data->size);
	return ((res > 0) ? file_data : NULL);
}
