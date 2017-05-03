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

bool					send_current_pwd(t_client *client)
{
	char	*current_path;

	if (!(current_path = (char*)malloc(sizeof(PATH_MAX_SIZE))))
		return (FALSE);
	getcwd(current_path, PATH_MAX_SIZE);
	send_data(client, current_path);
	return (TRUE);
}