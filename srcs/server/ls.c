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
	char				current_path[PATH_MAX_SIZE];
	DIR					*dir;
	struct dirent		*ent;

	dir = NULL;
	ent = NULL;
	getcwd(current_path, PATH_MAX_SIZE);
	if ((dir = opendir(current_path)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
			send_file(client, ft_strdup(ent->d_name));
		closedir(dir);
	}
	send_info(client, "");
}
