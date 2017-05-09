/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 10:23:12 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/08 10:23:19 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static struct stat		*get_file_stat(char *file, struct stat *file_stat)
{
	struct stat		*tmp;

	file_stat = NULL;
	if (!(tmp = malloc(sizeof(struct stat*))))
		return (NULL);
	if (lstat(check_newline(file), tmp) < 0)
		return (NULL);
	return (tmp);
}

int						check_if_readable(struct stat *file_stat, char *args, \
t_client *client)
{
	if (file_stat->st_mode & S_IRUSR)
		return (1);
	else
	{
		printf("ERROR: permission denied\n");
		return (0);
	}
}

struct stat				*check_access_file(char *file, t_client *client)
{
	struct stat		*file_stat;

	if ((file_stat = get_file_stat(file, file_stat)) != NULL)
	{
		if (!check_if_readable(file_stat, file, client))
			return (NULL);
		if (!S_ISREG(file_stat->st_mode))
		{
			printf("ERROR: not a file\n");
			return (NULL);
		}
		return (file_stat);
	}
	else
		printf("ERROR: no such file or directory\n");
	return (NULL);
}
