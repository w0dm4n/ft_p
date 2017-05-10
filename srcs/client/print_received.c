/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_received.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:22:31 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/09 16:22:38 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int						get_percent(t_file *file)
{
	size_t			current_offset;
	size_t			percent;

	current_offset = file->offset;
	percent = (current_offset * 100) / file->size;
	return (percent);
}

int						get_cols(void)
{
	struct winsize	size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return (size.ws_col);
}

int						get_line(void)
{
	struct winsize	size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return (size.ws_row);
}

void					print_received_file(t_client *client)
{
	if (client->current_file != NULL)
	{
		printf("%s", "\033[2J");
		printf("\033[;H");
		printf("\033[%dB", (get_line() / 2));
		printf("\033[%dC", (get_cols() / 2) - 10);
		printf("%s%d / 100 %c downloading... %s\n", "\e[38;05;168m", \
		get_percent(client->current_file), '%', KNRM);
	}
}
