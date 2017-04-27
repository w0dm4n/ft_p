/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 03:32:33 by frmarinh          #+#    #+#             */
/*   Updated: 2017/04/27 03:32:40 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void			print_error(char *msg, int exit_code)
{
	printf("ft_p: %s\n", msg);
	if (exit_code != 0)
		exit(exit_code);
}