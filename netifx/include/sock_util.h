/**
 * Contains all necessary functions for 
 * low level socket programming.
 */

#ifndef _NETWORK_SOCKETS_H_
#define _NETWORK_SOCKETS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <signal.h>
#include <netdb.h>
#include <fcntl.h>
#include <arpa/inet.h>

int make_socket(int domain, int type);

struct sockaddr_un make_local_address(char *name);

struct sockaddr_in make_inet_address(char *address, uint16_t port);

int bind_local_socket(char *name, int type, int backlog);

int bind_inet_socket(uint16_t port,int type, int backlog);

int bind_inet_udp_socket(uint16_t port);

int connect_local_socket(char *name);

int connect_inet_socket(char *name, uint16_t port);

char* get_ip_address(struct sockaddr_in addr_int);

#endif
