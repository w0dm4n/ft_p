/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 02:34:32 by frmarinh          #+#    #+#             */
/*   Updated: 2017/04/27 02:34:41 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static void	print_suite_suite(void)
{
	printf("             p::::::::::::::::p \n");
	printf(" f:::::::f                    tt:::::::::::tt            ");
	printf("             p::::::::::::::pp  \n");
	printf(" fffffffff                      ttttttttttt              ");
	printf("             p::::::pppppppp    \n");
	printf("                                             ____________");
	printf("____________ p:::::p            \n");
	printf("                                             _::::::::::::");
	printf("::::::::::_ p:::::p            \n");
	printf("                                             _____________");
	printf("___________p:::::::p           \n");
	printf("                                                          ");
	printf("           p:::::::p           \n");
	printf("                                                          ");
	printf("           p:::::::p           \n");
	printf("                                                          ");
	printf("           ppppppppp           \n");
	printf("%s", KNRM);
}

static void	print_suite(void)
{
	printf(" f::::::::::::f       tttttt:::::::tttttt                 ");
	printf("           pp::::::ppppp::::::p\n");
	printf(" f::::::::::::f             t:::::t                       ");
	printf("            p:::::p     p:::::p\n");
	printf(" f:::::::ffffff             t:::::t                      ");
	printf("             p:::::p     p:::::p\n");
	printf("  f:::::f                   t:::::t                     ");
	printf("              p:::::p     p:::::p\n");
	printf("  f:::::f                   t:::::t    tttttt            ");
	printf("             p:::::p    p::::::p\n");
	printf(" f:::::::f                  t::::::tttt:::::t            ");
	printf("             p:::::ppppp:::::::p\n");
	printf(" f:::::::f                  tt::::::::::::::t            ");
	print_suite_suite();
}

void		print_ascii_art(void)
{
	printf("%s", KCYN);
	printf("                                               ");
	printf("                                          \n");
	printf("    ffffffffffffffff           tttt                 ");
	printf("                                     \n");
	printf("   f::::::::::::::::f       ttt:::t                ");
	printf("                                      \n");
	printf("  f::::::::::::::::::f      t:::::t                   ");
	printf("                                   \n");
	printf("  f::::::fffffff:::::f      t:::::t                   ");
	printf("                                   \n");
	printf("  f:::::f       ffffffttttttt:::::ttttttt           ");
	printf("                 ppppp   ppppppppp   \n");
	printf("  f:::::f             t:::::::::::::::::t              ");
	printf("              p::::ppp:::::::::p  \n");
	printf(" f:::::::ffffff       t:::::::::::::::::t                ");
	printf("            p:::::::::::::::::p \n");
	print_suite();
}
