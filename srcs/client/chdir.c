/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 05:07:47 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 05:07:56 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char		*serialize_chdir(char *data)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
	return (NULL);
	ft_strcat(to_send, CHDIR_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	ft_strcat(to_send, data);
	return (to_send);
}

bool			handle_chdir(t_client *client, char *path)
{
	if (path != NULL)
		send_data(client, serialize_chdir(path));
	return (TRUE);
}