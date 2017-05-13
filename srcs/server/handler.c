/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 06:10:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 06:10:49 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static int		handle_esc(char **split, t_client *client)
{
	if (!ft_strcmp(split[0], PWD_MESSAGE))
		return (send_current_pwd(client));
	else if (!ft_strcmp(split[0], CHDIR_MESSAGE))
		chdir_command(split, client);
	else if (!ft_strcmp(split[0], LS_MESSAGE))
		send_current_directory_files(client);
	else if (!ft_strcmp(split[0], GET_MESSAGE))
		get_file(split, client);
	else if (!ft_strcmp(split[0], GET_DATA_MESSAGE))
		send_file_data(client, client->current_file);
	else if (!ft_strcmp(split[0], PUT_MESSAGE))
		set_receive_file(split, client);
	return (TRUE);
}

int				handle(char *buffer, t_client *client)
{
	char	**split;

	if (client != NULL)
	{
		split = ft_strsplit(buffer, ESCAPE_CHAR[0]);
		if (split[0] != NULL)
			return (handle_esc(split, client));
	}
	return (TRUE);
}
