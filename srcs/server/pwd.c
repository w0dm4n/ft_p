/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 06:15:30 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 06:15:37 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char				*serialize_pwd(char *data)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, PWD_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	ft_strcat(to_send, data);
	return (to_send);
}

bool					send_current_pwd(t_client *client)
{
	char	*current_path;

	if (!(current_path = (char*)malloc(sizeof(PATH_MAX_SIZE))))
		return (FALSE);
	getcwd(current_path, PATH_MAX_SIZE);
	send_data(client, serialize_pwd(current_path));
	return (TRUE);
}
