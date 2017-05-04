/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 06:04:53 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 06:05:01 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static char		*serialize_pwd(void)
{
	char	*to_send;

	if (!(to_send = ft_strnew(CLIENT_READ)))
		return (NULL);
	ft_strcat(to_send, PWD_MESSAGE);
	ft_strcat(to_send, ESCAPE_CHAR);
	return (to_send);
}

bool			pwd(t_client *client)
{
	send_data(client, serialize_pwd());
	return (TRUE);
}

void			print_pwd(char **split, t_client *client)
{
	if (split[1] != NULL)
		printf("%s%s%s\n", KCYN, split[1], KNRM);
	print_prompt(client);
}
