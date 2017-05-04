/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 01:27:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/04/27 01:27:43 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	main(int argc, char **argv)
{
	print_ascii_art();
	if (argc == 2)
		init_server(ft_atoi(argv[1]));
	else
		printf("ft_p: You must give me an arg as listen port !\n");
	return (0);
}
