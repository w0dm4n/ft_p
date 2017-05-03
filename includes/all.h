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
# define KNRM  "\e[38;05;140m"
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
# define bool int

# define ESCAPE_CHAR	"|"
# define ENCRYPTION_KEY "@#$KGERNGJR$#^#$#@(CG@$)+="
# define CLEAR_SCREEN 	"\033[2J"
# define PATH_MAX_SIZE	16192

typedef struct			s_client
{
	SOCKET				fd;
	struct sockaddr_in	in;
	bool				connected;
	char				*remote_host;
	int					remote_port;
	fd_set				read_fds;
}						t_client;

typedef struct			s_server
{
	SOCKET				fd;
	struct sockaddr_in	in;
}						t_server;

/*
** SERVER
*/

void					print_ascii_art(void);
void					init_server(int port);
void					accept_client(t_server *server);
void    				child(t_client *client);
int						get_client_port(struct sockaddr_in client);
char					*get_client_addr(struct sockaddr_in client);
int						get_path(char *path, char *args);
void					chdir_command(char *args);
void					chdir_command_ext(char *args, char *path, int args_nbr);
char					*get_subdir(char *path);
int						get_args_nbr(char *args);
void					change_folder(char *path, int change_path);
int						handle(char *buffer, t_client *client);
bool					send_current_pwd(t_client *client);

/*
** CLIENT
*/

char					*get_host(int argc, char **argv);
int						get_port(int argc, char **argv);
int						check_address_v4(char *adress);
t_client				*get_client(char *host, int port);
void					print_prompt(t_client *client);
void					init_client(t_client *client);
int						read_server(t_client *client);
int						handle(char *entry, t_client *client);
bool					help(void);
bool					handle_chdir(t_client *client, char *path);
bool					pwd(t_client *client);
/*
** BOTH SIDES
*/

void					send_data(t_client *client, char *msg);
void					print_error(char *msg, int exit_code);
char					*int_to_hexastring(char c);
char					hexastring_to_int(char *s);
char					*encrypt_message(char *msg);
char					*decrypt_message(char *crypted);


/*
** CLIENT COMMANDS
*/

# define QUIT_COMMAND "quit"
# define HELP_COMMAND "help"
# define CLEAR_COMMAND "clear"
# define CHDIR_COMMAND "cd"
# define PWD_COMMAND "pwd"

/*
** SOCKET SIZE DEFINE
*/

# define CLIENT_BUFFER 8193
# define CLIENT_READ 8192

/*
** SERVER MESSAGE
*/

# define CHDIR_MESSAGE "CHDIR_MESSAGE"
# define PWD_MESSAGE "PWD_MESSAGE"

#endif