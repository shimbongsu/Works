/***********************************************************
 SRC Name		: main.c 
 INC Header		: main.h 
 Function		: main process 
 Create Date	: 2011-02-24
 Last Edited	: 2011-03-03
 Finish Date	: Not Yet 
 Creator		: by DongHan Kim 
***********************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_
/***********************************************************
	Include Header
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <sys/signal.h>
#ifdef __SUN__
#include <sys/select.h>
#endif
#ifdef __HPUX__
#include <sys/times.h>
#endif
#ifdef __LINUX__
#include <sys/times.h>
#include <sys/select.h>
#endif
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/poll.h>

#define LOG_ARG 0, __FILE__, __FUNCTION__, __LINE__
#define ERR_ARG 1, __FILE__, __FUNCTION__, __LINE__
#define DBG_ARG 2, __FILE__, __FUNCTION__, __LINE__

#define	SERVER_PORT		41110
#define	SERVER_IP		"130.1.7.102"
#define	MAX_CLIENT_CNT	32 /* LISTEN FD -1, MAX 1024*/

#define	MAX_DATA_SIZE	8192
#define	MAX_SEND_SIZE	1024
#define	MAX_READ_SIZE	1024

#ifndef FALSE
	#define FALSE  0
#endif
#ifndef TRUE
	#define TRUE  1
#endif
#ifndef FAIL
	#define FAIL  -1	/* FOR MAIN PROCESS EXIT */
#endif

#define RETURN_FALSE	FALSE
#define RETURN_TRUE		TRUE

#define RETURN_FAIL		FAIL

int gi_LogLevel;

#endif

/* EOF */
