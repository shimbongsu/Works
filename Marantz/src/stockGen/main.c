
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[8];
};
static struct sqlcxp sqlfpn =
{
    7,
    "main.pc"
};


static unsigned int sqlctx = 9211;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[1];
   unsigned int   sqhstl[1];
            int   sqhsts[1];
            void  *sqindv[1];
            int   sqinds[1];
   unsigned int   sqharm[1];
   unsigned int   *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned int *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ char *, int * _*/);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4274,840,0,0,
};


/******************************************************************************/
/* NEW DELTA DATE : 2012.04.12                                                */
/* BLOCK          : main.pc                                                   */
/* PROC-NAME      :                                                           */
/* DATE           : 2012.04.12                                                */
/* FUNCTIONS      :                                                           */
/* DESCRIPTION    :                                                           */
/* REMARKS        :                                                           */
/******************************************************************************/
/***********************************************************
	Include Header
***********************************************************/
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "log.h"
#include "bizfunc.h"

int main( int argc, char *argv[])	{

	/*	SET LOG LEVEL
		[PROCESS NAME] [ARG]
		ARG - 0, LOG             | LOG_ARG 0
		ARG - 1, LOG ERROR       | ERR_ARG 1
		ARG - 2, LOG ERROR DEBUG | DBG_ARG 2

		DEFAULT - 2, LOG ERROR DEBUG
	*/
	if ( argc > 1 ) {
#ifdef  __XLC__
		gi_LogLevel = (int)atoi((char *)&argv[1]);
#endif
#ifndef	__XLC__
		gi_LogLevel = atoi( argv[1] );
#endif
	} else {
		gi_LogLevel = 2;
	}
		
	log_printf(LOG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>");
	log_printf(LOG_ARG,"STOCK GEN START!!  ARGC [%d]" , argc);
	log_printf(LOG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>");
	/*
	if( argc > 1 ) {
		log_printf(LOG_ARG,"LOG LEVEL[%s] FROM INPUT",argv[1]);
		log_printf(LOG_ARG,"LOG LEVEL[%d] FROM LOCAL",gi_LogLevel);
	} else {
		log_printf(LOG_ARG,"LOG LEVEL[%d] FROM LOCAL",gi_LogLevel);
	}
	*/
	log_printf(LOG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>");
	//dump_printf(lc_temp,sizeof(lc_temp));
	
	//-------------------------------------------------------------------------
	// 입력종목번호 매핑 시작
	char lc_StockNo [32+1] = { 0x00, }; // 
	
	if( argc > 2 ) {
		if( strlen( argv[2] ) < 7 ) {
			strcpy( lc_StockNo, argv[2] );
		}
	}
	// 입력종목번호 매핑 종료
	//-------------------------------------------------------------------------
	
	db_Conn();
	/**************************************************************************/
	/* WRITE BIZ START */
	/**************************************************************************/
	StockCreateRunner( lc_StockNo );
	
	/**************************************************************************/
	/* WRITE BIZ END */
	/**************************************************************************/
	db_Close();

	log_printf(LOG_ARG,"<<<<<<<<<<<<<<<<<<<<<<<<<");
	log_printf(LOG_ARG,"STOCK GEN END!!");
	log_printf(LOG_ARG,"<<<<<<<<<<<<<<<<<<<<<<<<<");

	return 0;
	
}
