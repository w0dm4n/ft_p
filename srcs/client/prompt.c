/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 02:31:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 02:31:49 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static void		print_host(t_client *client)
{
	ft_putstr(KGRN);
	ft_putstr(client->remote_host);
	ft_putstr(KNRM);
	ft_putstr(":");
	ft_putstr(KGRN);
	ft_putnbr(client->remote_port);
	ft_putstr(KNRM);
}

void			print_prompt(t_client *client)
{
	if (client != NULL && client->connected == TRUE)
	{
		ft_putstr(KNRM);
		ft_putstr("[ft_p (");
		print_host(client);
		ft_putstr(")]: ");
	}
	else
		ft_putstr("[ft_p]: ");
}
