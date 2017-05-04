/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:46:35 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/04 16:46:40 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char		*serialize_pwd(void)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, LS_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	return (to_send);
}

bool			send_ls_client(t_client *client)
{
	if (client != NULL)
		send_data(client, serialize_pwd());
	return (TRUE);
}

void			print_ls(char **split)
{
	char	**files;
	int		i;

	i = 0;
	files = NULL;
	if (split[1] != NULL)
	{
		files = ft_strsplit(split[1], ESCAPE_DATA[0]);
		if (files != NULL)
		{
			while (files[i])
				printf("%s%s%s\n", KCYN, files[i++], KNRM);
		}
	}
}
