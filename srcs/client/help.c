/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 04:30:12 by frmarinh          #+#    #+#             */
/*   Updated: 2017/05/03 04:30:23 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

bool		help(void)
{
	printf("List of commands for ft_p: \n");
	printf("- quit: Cuts the connection and close the program\n");
	printf("- help: Show all commands available\n");
	printf("- clear: Clear the screen for more visibility\n");
	printf("- cd: Change the current directory of the server\n");
	printf("- pwd: Displays the current directory path on the server\n");
	printf("- ls: List the current directory of the server\n");
	return (TRUE);
}
