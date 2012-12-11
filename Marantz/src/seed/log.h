/***********************************************************
 Header			: log.h
 Function		: Log Header
 Create Date	: 2011. 03. 02
 Last Edited	: 2011. 03. 02 
 Finish Date	: Not Yet 
 Creator		: by DongHan Kim 
***********************************************************/
#ifndef _LOG_H_
#define _LOG_H_
/***********************************************************
	Include Header
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include <sys/ioctl.h>
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
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/stat.h>

/***********************************************************
	Pre-define Functions
***********************************************************/
extern void log_printf(int LogLevel, const char *FileName, const char *FunctionName, const int LineNumber, const char * fmsg, ...);
extern void dump_printf(char *fmsg,unsigned int fmsg_size);
extern int GetLocalTime(char *tmBuff, char *Type, int tmBuffSize);
/***********************************************************
	Define Global Variable and Structures
***********************************************************/
#define LOG_ARG 0, __FILE__, __FUNCTION__, __LINE__
#define ERR_ARG 1, __FILE__, __FUNCTION__, __LINE__
#define DBG_ARG 2, __FILE__, __FUNCTION__, __LINE__

#define	MAX_DATA_SIZE	8192
#define	MAX_SEND_SIZE	1024
#define	MAX_READ_SIZE	1024

#ifndef FALSE
	#define FALSE  0
#endif
#ifndef TRUE
	#define TRUE  1
#endif

#define RETURN_FALSE	FALSE
#define RETURN_TRUE		TRUE

int gi_LogLevel;

#endif
/* EOF */
