/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:03:43 by frmarinh          #+#    #+#             */
/*   Updated: 2017/04/20 14:04:17 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
/*
** COLORS
*/
# define KNRM  "\e[38;05;194m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define TRUE	1
# define FALSE	0
# define MAX_PORT 65535
# define SOCKET int
# define CLIENT_BUFFER 8193
# define CLIENT_READ 8192

typedef struct			s_client
{
	int					fd;
	struct sockaddr_in	in;
}						t_client;

typedef struct			s_server
{
	int					fd;
	struct sockaddr_in	in;
}						t_server;

void	print_ascii_art(void);
void	init_server(int port);
void	print_error(char *msg, int exit_code);
void	accept_client(t_server *server);
void    child(t_client *client);
int		get_client_port(struct sockaddr_in client);
char	*get_client_addr(struct sockaddr_in client);

#endif
