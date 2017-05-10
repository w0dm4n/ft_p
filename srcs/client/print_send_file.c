/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_send_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:46:32 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/10 17:46:39 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void			print_send_file(t_client *client)
{
	if (client->current_file != NULL)
	{
		printf("%s", "\033[2J");
		printf("\033[;H");
		printf("\033[%dB", (get_line() / 2));
		printf("\033[%dC", (get_cols() / 2) - 10);
		printf("%s%d / 100 %c sending... %s\n", "\e[38;05;168m", \
		get_percent(client->current_file), '%', KNRM);
	}
}
