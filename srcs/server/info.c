/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:18:50 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/04 16:18:56 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char		*serialize_info(char *data)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, INFO_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	ft_strcat(to_send, data);
	return (to_send);
}

void			send_info(t_client *client, char *msg)
{
	if (client != NULL)
		send_data(client, serialize_info(msg));
}
