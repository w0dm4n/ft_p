/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:51:31 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/04 16:51:35 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char		*serialize_ls(char *data)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, LS_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	ft_strcat(to_send, data);
	return (to_send);
}

void			send_file(t_client *client, char *file)
{
	char data[CLIENT_READ];

	data[0] = '\0';
	ft_strcat(data, LS_MESSAGE);
	ft_strcat(data, ESCAPE_CHAR);
	ft_strcat(data, file);
	ft_strcat(data, "\n");
	write(client->fd, data, ft_strlen(data));
}

void			send_current_directory_files(t_client *client)
{
	char				*current_path;
	DIR					*dir;
	struct dirent		*ent;
	char				*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return ;
	dir = NULL;
	ent = NULL;
	if (!(current_path = (char*)malloc(sizeof(PATH_MAX_SIZE))))
		return ;
	getcwd(current_path, PATH_MAX_SIZE);
	if ((dir = opendir(current_path)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
			send_file(client, ft_strdup(ent->d_name));
		closedir(dir);
	}
	send_info(client, "");
}
