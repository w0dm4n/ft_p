/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 04:20:11 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 04:20:18 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static void		not_found(void)
{
	printf("ft_p: Command not found ! Please use help to get the list ");
	printf("of all commands available.\n");
}

static int		handle_suite(char **split, t_client *client)
{
	if (!ft_strncmp(split[0], PWD_COMMAND, \
		ft_strlen(PWD_COMMAND)))
		return (pwd(client));
	else if (!ft_strncmp(split[0], LS_COMMAND, \
		ft_strlen(LS_COMMAND)))
		return (send_ls_client(client));
	else
		not_found();
	return (TRUE);
}

int				handle(char *entry, t_client *client)
{
	char	**split;

	split = ft_strsplit(entry, ' ');
	if (split[0] != NULL)
	{
		if (!ft_strncmp(split[0], HELP_COMMAND, \
			ft_strlen(HELP_COMMAND)))
			return (help());
		else if (!ft_strncmp(split[0], CLEAR_COMMAND, \
			ft_strlen(CLEAR_COMMAND)))
			ft_putstr(CLEAR_SCREEN);
		else if (!ft_strncmp(split[0], QUIT_COMMAND, \
			ft_strlen(QUIT_COMMAND)))
			exit(0);
		else if (!ft_strncmp(split[0], CHDIR_COMMAND, \
			ft_strlen(CHDIR_COMMAND)))
			handle_chdir(client, split[1]);
		else
			return (handle_suite(split, client));
	}
	return (TRUE);
}
