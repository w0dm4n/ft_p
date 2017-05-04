/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:22:53 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/04 16:23:02 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		print_info(char **split, t_client *client)
{
	if (split[1] != NULL)
		printf("%sSERVER: %s%s\n", KCYN, split[1], KNRM);
	print_prompt(client);
}
