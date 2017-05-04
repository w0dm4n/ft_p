/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_command_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 03:58:26 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/27 03:58:32 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	chdir_command_ext(char *args, char *path, int args_nbr, \
t_client *client)
{
	char current_path[CLIENT_READ];

	current_path[0] = '\0';
	getcwd(current_path, CLIENT_READ);
	args_nbr = get_args_nbr(args);
	args = ft_strtrim(args);
	if (args_nbr == 0)
	{
		if (!ft_strcmp(args, "/"))
			change_folder("/", 1);
		if (!ft_strcmp(args, ".") || !ft_strcmp(args, "./"))
			return ;
		if (get_path(current_path, args, client))
		{
			chdir(args);
			getcwd(path, CLIENT_READ);
			change_folder(path, 0);
		}
	}
	else
		send_info(client, "cd: bad arguments !");
}
