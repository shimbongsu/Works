/***********************************************************
 SRC Name		: log.c 
 INC Header		: log.h
 Function		: Log Generator
 Create Date	: 2011. 03. 02
 Last Edited	: 2011. 03. 02 
 Finish Date	: Not Yet 
 Creator		: by DongHan Kim 
***********************************************************/
/***********************************************************
	Include Header
***********************************************************/
#include "main.h"
#include "log.h"

/***********************************************************
	Function GetLocalTime
***********************************************************/
int GetLocalTime(char *tmBuff, char *Type, int tmBuffSize)
{

    char lc_tmbuff[40];
    memset(lc_tmbuff,  0x00, sizeof(lc_tmbuff));
    
	/******************************/
	time_t now;
	time(&now);

	struct tm *tmp = localtime(&now);

	/******************************/
	if( strncmp(Type,"S",1) == 0 ){
		strftime(lc_tmbuff,40,"%H:%M:%S",tmp); /* HH:MM:SS */
	}
	else if( strncmp(Type,"D",1) == 0 ){
		strftime(lc_tmbuff,40,"%Y%m%d",tmp); /* YYYYMMDD */
	}
	/******************************/

	strcpy(tmBuff,lc_tmbuff);

	return RETURN_TRUE;/* return TRUE */
}

void log_printf(int LogLevel,
				const char *FileName, 
				const char *FunctionName,
				const int   LineNumber,
				const char *fmsg, ...)
{
	if ( LogLevel > gi_LogLevel ) {
		return;
	}

	static va_list arg;
	static char format[2048];
	static char buf[1024*8];

	static int  len = 0;
	static int  fdate = 0;
	static int  cdate = 0;
	static int  file = -1;
	static char path[256];

	int stat;

	char lc_DateSec[40];
	char lc_Date[40];

	memset(lc_DateSec,0x00,40);
	memset(lc_Date,0x00,40);

	GetLocalTime(lc_DateSec,"S",sizeof(lc_DateSec));
	GetLocalTime(lc_Date,"D",sizeof(lc_Date));
	
	/*	LOG LEVEL
		ARG - 0, LOG
		ARG - 1, LOG ERROR
		ARG - 2, LOG ERROR DEBUG
	*/

	if ( LogLevel == 0 ) {
		sprintf(format,"[LOG][%s]:[%12s][%04d]::%s\n",lc_DateSec,FileName,LineNumber,fmsg);
	} else if ( LogLevel == 1 ) {
		sprintf(format,"[ERR][%s]:[%12s][%04d]::%s\n",lc_DateSec,FileName,LineNumber,fmsg);
	} else if ( LogLevel == 2 ) {
		sprintf(format,"[DBG][%s]:[%12s][%04d]::%s\n",lc_DateSec,FileName,LineNumber,fmsg);
	}

	va_start(arg, fmsg);
	vsprintf(buf, format, arg);
	va_end(arg);

	len = strlen(buf);
	cdate = atoi(lc_Date);
	
	/* FOR TEST
	if( gi_LogLevel == 2 ) {
		fprintf(stdout,format);
	}
	*/

LOG_CREATE:

	if(file == -1 || fdate != cdate) {
		fdate = cdate;
		if(file != -1) close(file);
		sprintf(path, "%s/work/log/stockGen_%s", getenv("HOME"), lc_Date);
		/*file = open(path, O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);*/
		file = open(path, O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
	}

	if(write(file, buf, len) == -1) {
		close(file);
		file = -1;
		goto LOG_CREATE;
	}

}

void dump_printf(char *fmsg,unsigned int fmsg_size) {
	
	unsigned int	li_stop;
	unsigned int	li_count;
	unsigned int	li_pointer;
	unsigned int	li_abs;
	int				li_temp;
	int				li_remains;
	int				li_addrescnt;
	char			*lc_cpointer_count;

	li_stop = fmsg_size;

	li_count = 1;
	li_addrescnt = 0;
	
	char lc_temp[128];
	char lc_omsg[1024];
	
	memset(lc_omsg,0x00,1024);
	
	/******************************************************************/
	log_printf(LOG_ARG,"-------------------------------------------------------     -----------------");
	/******************************************************************/			
		
	/* FOR LOOP START */
	for(li_pointer = 0 ; li_pointer <= li_stop; li_pointer++)	{
		
		if(0 == li_count%16 - 1) {
		
			memset(lc_temp,0x00,128);
			memset(lc_omsg,0x00,1024);
			sprintf(lc_temp,"%05d: ", li_addrescnt++*16);
			strcat(lc_omsg,lc_temp);
			
		}
		
		memset(lc_temp,0x00,128);
		sprintf(lc_temp,"%02X ", (unsigned char)*((char *)fmsg + li_pointer)); 
		strcat(lc_omsg,lc_temp);
		
		if(0 == (li_count%8)) {
			memset(lc_temp,0x00,128);
			sprintf(lc_temp," "); 
			strcat(lc_omsg,lc_temp);
		}
		
		if(0 == (li_count%16)) {
		
			memset(lc_temp,0x00,128);
			sprintf(lc_temp,"   ");
			strcat(lc_omsg,lc_temp);
			
			lc_cpointer_count = (char *)fmsg + li_pointer - 15;
			
			for(li_temp = 0;li_temp <= 15;li_temp++) {
			
				li_abs = (int)*((char *)lc_cpointer_count + li_temp);

				if ((li_abs > 32) && (li_abs <127)) {
				
					memset(lc_temp,0x00,128);
					sprintf(lc_temp,"%c", (unsigned char)*((char *)lc_cpointer_count + li_temp));
					strcat(lc_omsg,lc_temp);
					
				} else {
				
					memset(lc_temp,0x00,128);
					sprintf(lc_temp,"."); 
					strcat(lc_omsg,lc_temp);
					
				}
				
				if(li_temp == 7) {
				
					memset(lc_temp,0x00,128);
					sprintf(lc_temp," ");
					strcat(lc_omsg,lc_temp);
					
				}
				
			} /* END OF FOR LOOP */
			
			/******************************************************************/
			/* LOG PUSH */
			log_printf(LOG_ARG,lc_omsg);
			/******************************************************************/
			
		}
		
		if(0 == (li_count%128)) {
			/******************************************************************/
			/* LOG PUSH */
			log_printf(LOG_ARG,"-------------------------------------------------------     -----------------");
			/******************************************************************/			
		}

		li_count++;
	
	} /* END OF FOR LOOP */
	
	li_remains = fmsg_size%16+1;
	
	/* REMAINS */
	if(((li_stop)%16) != 0) {
	
		if(((li_stop)%16) < 8) {
		
			memset(lc_temp,0x00,128);
			sprintf(lc_temp," "); 
			strcat(lc_omsg,lc_temp);
			
		}

		for(li_temp = 0;li_temp <= ((16 - li_remains)*3+3); li_temp++) {
		
			memset(lc_temp,0x00,128);
			sprintf(lc_temp," "); 
			strcat(lc_omsg,lc_temp);
			
		}

		lc_cpointer_count = (char *)fmsg + li_pointer - li_remains;
		
		for(li_temp=0;li_temp < li_remains;li_temp++) {
		
			li_abs = (int)*((char *)lc_cpointer_count + li_temp);
	
			if ((li_abs > 32) && (li_abs <127)) {
			
				memset(lc_temp,0x00,128);
				sprintf(lc_temp,"%c", (unsigned char)*((char *)lc_cpointer_count + li_temp)); 
				strcat(lc_omsg,lc_temp);
				
			} else {
			
				memset(lc_temp,0x00,128);
				sprintf(lc_temp,"."); 
				strcat(lc_omsg,lc_temp);
			}

			if(li_temp == 7) {
			
				memset(lc_temp,0x00,128);
				sprintf(lc_temp," ");
				strcat(lc_omsg,lc_temp);
				
			}

		} /* END OF FOR LOOP */

		/******************************************************************/
		/* LOG PUSH */
		log_printf(LOG_ARG,lc_omsg);
		/******************************************************************/
	}/* END OF REMAINS */
	
	if(0 != (li_count%130)) {
		/*log_printf(DBG_ARG,"li_count : [%d]",li_count);*/
		log_printf(LOG_ARG,"-------------------------------------------------------     -----------------");
	}
	
}

/* EOF */
