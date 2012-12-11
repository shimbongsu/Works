
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "bizfunc.pc"
};


static unsigned int sqlctx = 73395;


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
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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

 static char *sq0001 = 
"select STOCK_NO ,STOCK_NM ,OPEN_DT ,AREA_NM  from TB_STOCK_BASE where (1=1 \
and (:b0 is null  or STOCK_NO=:b0)) order by STOCK_NO,OPEN_DT            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4274,840,0,0,
5,0,0,1,148,0,521,73,0,0,2,2,0,1,0,1,5,0,0,1,5,0,0,
28,0,0,1,0,0,525,96,0,0,4,0,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
59,0,0,1,0,0,527,102,0,0,0,0,0,1,0,
74,0,0,1,0,0,527,122,0,0,0,0,0,1,0,
};


/***********************************************************
 Header         : bizfunc.h
 Function       : Biz Header
 Create Date    : 2011. 03. 02
 Last Edited    : 2011. 03. 02 
 Finish Date    : Not Yet 
 Creator        : by DongHan Kim 
***********************************************************/
/***********************************************************
    Include Header
***********************************************************/
#include "main.h"
#include "bizfunc.h"

/* EXEC SQL INCLUDE SQLCA;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */
/* EXEC SQL INCLUDE "sqlca.h";
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */
/* EXEC SQL INCLUDE "oraca.h";
 */ 
/*
 * $Header: oraca.h 24-apr-2003.12:50:59 mkandarp Exp $ oraca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  ORACA : Oracle Communications Area.
FUNCTION
  Contains no code. Provides supplementary communications to/from
  Oracle (in addition to standard SQLCA).
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  oracchf : Check cursor cache consistency flag. If set AND oradbgf
            is set, then directs SQLLIB to perform cursor cache
            consistency checks before every cursor operation
            (OPEN, FETCH, SELECT, INSERT, etc.).
  oradbgf : Master DEBUG flag. Used to turn all DEBUG options
            on or off.
  orahchf : Check Heap consistency flag. If set AND oradbgf is set,
            then directs SQLLIB to perform heap consistency checks
            everytime memory is dynamically allocated/free'd via
            sqlalc/sqlfre/sqlrlc. MUST BE SET BEFORE 1ST CONNECT
            and once set cannot be cleared (subsequent requests
            to change it are ignored).
  orastxtf: Save SQL stmt text flag. If set, then directs SQLLIB
            to save the text of the current SQL stmt in orastxt
            (in VARCHAR format).
  orastxt : Saved len and text of current SQL stmt (in VARCHAR
            format).
  orasfnm : Saved len and text of filename containing current SQL
            stmt (in VARCHAR format).
  oraslnr : Saved line nr within orasfnm of current SQL stmt.
 
  Cursor cache statistics. Set after COMMIT or ROLLBACK. Each
  CONNECT'd DATABASE has its own set of statistics.
 
  orahoc  : Highest Max Open OraCursors requested. Highest value
            for MAXOPENCURSORS by any CONNECT to this DATABASE.
  oramoc  : Max Open OraCursors required. Specifies the max nr
            of OraCursors required to run this pgm. Can be higher
            than orahoc if working set (MAXOPENCURSORS) was set
            too low, thus forcing the PCC to expand the cache.
  oracoc  : Current nr of OraCursors used.
  oranor  : Nr of OraCursor cache reassignments. Can show the
            degree of "thrashing" in the cache. Optimally, this
            nr should be kept as low as possible (time vs space
            optimization).
  oranpr  : Nr of SQL stmt "parses".
  oranex  : Nr of SQL stmt "executes". Optimally, the relation-
            ship of oranex to oranpr should be kept as high as
            possible.
 
 
  If the symbol ORACA_NONE is defined, then there will be no ORACA
  *variable*, although there will still be a struct defined.  This
  macro should not normally be defined in application code.

  If the symbol ORACA_INIT is defined, then the ORACA will be
  statically initialized. Although this is not necessary in order
  to use the ORACA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the ORACA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then ORACA_INIT should be left undefined --
  all others can define ORACA_INIT if they wish.
 
OWNER
  Clare
DATE
  10/19/85
MODIFIED
    apopat     05/08/02  - [2362423] MVS PE to make lines shorter than 79
    apopat     07/31/99 -  [707588] TAB to blanks for OCCS
    lvbcheng   10/27/98 -  change long to int for oraca
    pccint     10/03/96 -  Add IS_OSD for linting
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   09/04/92 -  Make oraca variable optional 
    Osborne    05/24/90 - Add ORACA_STORAGE_CLASS construct
  Clare      02/20/86 - PCC [10101l] Feature: Heap consistency check.
  Clare      03/04/86 - PCC [10101r] Port: ORACA init ifdef.
  Clare      03/12/86 - PCC [10101ab] Feature: ORACA cuc statistics.
*/
/* IS_OSD */ 
#ifndef  ORACA
#define  ORACA     1
 
struct   oraca
         {
    /* text */ char oracaid[8];      /* Reserved                            */
    /* ub4  */ int oracabc;          /* Reserved                            */
 
    /*       Flags which are setable by User. */
 
   /* ub4 */ int  oracchf;           /* <> 0 if "check cur cache consistncy"*/
   /* ub4 */ int  oradbgf;           /* <> 0 if "do DEBUG mode checking"    */
   /* ub4 */ int  orahchf;           /* <> 0 if "do Heap consistency check" */
   /* ub4 */ int  orastxtf;          /* SQL stmt text flag                  */
#define  ORASTFNON 0                 /* = don't save text of SQL stmt       */
#define  ORASTFERR 1                 /* = only save on SQLERROR             */
#define  ORASTFWRN 2                 /* = only save on SQLWARNING/SQLERROR  */
#define  ORASTFANY 3                 /* = always save                       */
         struct
           {
  /* ub2  */ unsigned short orastxtl;
  /* text */ char  orastxtc[70];
           } orastxt;                /* text of last SQL stmt               */
         struct
           {
  /* ub2  */   unsigned short orasfnml;
  /* text */   char       orasfnmc[70];
           } orasfnm;                /* name of file containing SQL stmt    */
  /* ub4 */ int   oraslnr;           /* line nr-within-file of SQL stmt     */

  /* ub4 */ int   orahoc;            /* highest max open OraCurs requested  */
  /* ub4 */ int   oramoc;            /* max open OraCursors required        */
  /* ub4 */ int   oracoc;            /* current OraCursors open             */
  /* ub4 */ int   oranor;            /* nr of OraCursor re-assignments      */
  /* ub4 */ int   oranpr;            /* nr of parses                        */
  /* ub4 */ int   oranex;            /* nr of executes                      */
         };

#ifndef ORACA_NONE

#ifdef ORACA_STORAGE_CLASS
ORACA_STORAGE_CLASS struct oraca oraca
#else
struct oraca oraca
#endif
#ifdef ORACA_INIT
         =
         {
         {'O','R','A','C','A',' ',' ',' '},
         sizeof(struct oraca),
         0,0,0,0,
         {0,{0}},
         {0,{0}},
         0,
         0,0,0,0,0,0
         }
#endif
         ;

#endif

#endif
/* end oraca.h */
/* EXEC SQL INCLUDE "sqlcpr.h";
 */ 
/*
 * $Header: sqlcpr.h 09-apr-2003.11:06:57 apopat Exp $
 */

/* Copyright (c) 1988, 2003, Oracle Corporation.  All rights reserved.  */
 
/* NAME
     sqlcpr.h
   FUNCTION
     Contains 'customer' prototypes for the sql* routines generated by the
     precompiler.  
     sqlald, sqlglm, sqlnul and sqlprc are included because, although we don't
     generate calls to them, users may include calls to them.

     'customer' prototypes for dynamic method 4 (i.e., sqlda) reside
     in the sqlda.h public header file.

   NOTES
     There should be no 'modified' notes in this file when it goes to the
     customer.  Remove them as they are put in.  */

#ifndef SQLCA
#  include <sqlca.h>
#endif
#ifndef ORACA
#  include <oraca.h>
#endif

#ifndef SQLPRO
#  define SQLPRO

/* -------------------- */
/* defines for sqlcpr.h */
/* -------------------- */

#define SQL_SUCCESS (sword)0
#define SQL_ERROR (sword)-1
#define SQL_SINGLE_RCTX (dvoid *)0

#define SQLErrorGetText(arg1, arg2, arg3, arg4) sqlglmt(arg1, arg2, arg3, arg4)

#define SQLStmtGetText(arg1, arg2, arg3, arg4) sqlglst(arg1, arg2, arg3, arg4)

#define SQLColumnNullCheck(arg1, arg2, arg3, arg4) \
        sqlnult(arg1, arg2, arg3, arg4)

#define SQLNumberPrecV6(arg1, arg2, arg3, arg4) sqlprct(arg1, arg2, arg3, arg4)

#define SQLNumberPrecv7(arg1, arg2, arg3, arg4) sqlpr2t(arg1, arg2, arg3, arg4)

#define SQLVarcharGetLength(arg1, arg2, arg3) sqlvcpt(arg1, arg2, arg3) 

#define SQLGetStride(arg1, arg2, arg3, arg4) sqlstrdt(arg1, arg2, arg3, arg4)

#if defined (__STDC__) || defined (__cplusplus)

#ifdef  __cplusplus
extern "C" {
#endif

/* user-callable functions - non-threaded */
/* -------------------------------------- */

extern void sqlglm( char*, size_t*, size_t* );
extern void sqlgls( char*, size_t*, size_t* );
extern void sqliem( char*, int* );
extern void sqlnul( unsigned short*, unsigned short*, int* );
extern void sqlprc( unsigned int*, int*, int* );
extern void sqlpr2( unsigned int*, int*, int*);
extern void sqlvcp( unsigned int*, unsigned int* );

/* user-callable functions -- thread safe */
/* -------------------------------------- */

extern void sqlglmt( void*, char*, size_t*, size_t* ); 

extern void sqlglst( void*, char*, size_t*, size_t* );

extern void sqliemt( void*, char*, int*);

extern void sqlnult( void*, unsigned short*, unsigned short*, int*);

extern void sqlpr2t( void*, unsigned int*, int*, int*);

extern void sqlprct( void*, unsigned int*, int*, int*);

extern void sqlvcpt( void*, unsigned int*, unsigned int*);

extern void SQLExtProcError( void*, char*, size_t );

/* Removed generated Pro* 1.3 entry points */
/* --------------------------------------- */

/* Forms 3.0 compatibility functions */
/* --------------------------------- */

extern int iapprs( char* );      
extern int iappfo( char*, char*, unsigned int );
extern int exiterr( char* );

/* user-callable functions - non-threaded */
/* -------------------------------------- */

extern struct SQLDA *sqlald( int, size_t, size_t );
extern void sqlclu( struct SQLDA*);

/* user-callable functions -- thread safe */
/* -------------------------------------- */

extern struct SQLDA *sqlaldt( void*, int, size_t, size_t );

extern void sqlclut( void*, struct SQLDA*);

#ifdef  __cplusplus
}
#endif

#else /* k&r C - not ANSI standard */


/* user-callable functions - non-threaded */
/* -------------------------------------- */

extern void sqlglm( /*_ char*, size_t*, size_t* _*/ );
extern void sqlgls( /*_ char*, size_t*, size_t* _*/);
extern void sqliem( /*_ char*, int* _*/ );
extern void sqlnul( /*_ unsigned short*, unsigned short*, int* _*/ );
extern void sqlprc( /*_ unsigned int*, int*, int* _*/ );
extern void sqlpr2( /*_ unsigned int*, int*, int* _*/);
extern void sqlvcp( /*_ unsigned int *, unsigned int * _*/);
extern void sqlstrd(/*_ ub1 *, ub1 *, size_t _*/);  

/* user-callable functions -- thread safe */
/* -------------------------------------- */

extern void sqlglmt(/*_ void*, char*, size_t*, size_t* _*/ ); 

extern void sqlglst(/*_ void*, char*, size_t*, size_t* _*/);

extern void sqliemt(/*_ void*, char*, int* _*/ );

extern void sqlnult(/*_ void*, unsigned short*, unsigned short*, int* _*/ );

extern void sqlprct(/*_ void*, unsigned int*, int*, int* _*/ );

extern void sqlpr2t(/*_ void*, unsigned int*, int*, int* _*/);

extern void sqlvcpt(/*_ void*, unsigned int *, unsigned int * _*/);

extern void sqlstrdt(/*_ void *, ub1 *, ub1 *, size_t _*/);

extern void SQLExtProcError(/*_ void*, char*, size_t _*/);

extern void SQLRowidGet(/*_ void*, OCIRowid **urid _*/);

/* Removed generated Pro* 1.3 entry points */
/* --------------------------------------- */


/* Forms 3.0 compatibility functions */
/* --------------------------------- */

extern int iapprs( /*_ char* _*/ );      
extern int iappfo( /*_ char*, char*, unsigned int _*/ );
extern int exiterr( /*_ char* _*/ );

/* user-callable functions - non-threaded */
/* -------------------------------------- */

extern struct SQLDA *sqlald( /*_ int, size_t, size_t _*/ );
extern void sqlclu( /*_ struct SQLDA* _*/);

/* user-callable functions -- thread safe */
/* -------------------------------------- */

extern struct SQLDA *sqlaldt(/*_ void*, int, size_t, size_t _*/ );
extern void sqlclut(/*_ void*, struct SQLDA* _*/);

#endif /* k&r C - not ANSI standard */

#endif /* SQLPRO */


/* SQL MACRO  */
#define SQLCODE         sqlca.sqlcode
#define SQLERRM         sqlca.sqlerrm.sqlerrmc
#define SQLCOUNT        sqlca.sqlerrd[2]
#define SQLNODATA       1403
#define SQLNULL         -1405
#define SQLDUP          -1
#define SQLOK           0

/***********************************************************
    주가 생성 MAIN RUNNER
***********************************************************/
int StockCreateRunner( char *StockNo ) {

	STOCK_INFO_RSLT st_stock_info_rslt;
	memset( (char *)&st_stock_info_rslt, 0x00, sizeof(STOCK_INFO_RSLT) );
	
	//-------------------------------------------------------------------------
	// 종목정보 DB 조회
	char lc_STOCK_NO [6+1] = { 0x00, };
	memset(lc_STOCK_NO,0x00,7);
	
	if( StockNo[0] != NULL ) {
		
		strncpy( lc_STOCK_NO, StockNo, 6 );
		
		log_printf( LOG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>" );
		log_printf( LOG_ARG," 입력종목번호 :[%s]", lc_STOCK_NO );
		log_printf( LOG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>" );
	
	} 
	
	//---------------------------------------------------------------
	// DECLARE CURSOR
	/* EXEC SQL DECLARE STOCK_INFO CURSOR FOR 
	SELECT STOCK_NO
		  ,STOCK_NM
		  ,OPEN_DT
		  ,AREA_NM
	 FROM TB_STOCK_BASE
	WHERE 1 = 1
	  AND (:StockNo IS NULL OR STOCK_NO = :StockNo)
	ORDER BY STOCK_NO,OPEN_DT
	; */ 

	
	if( SQLCODE != SQLOK ) {
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"커서 STOCK_INFO 선언시 에러발생 [%d]-[%s]", SQLCODE, SQLERRM );
		log_printf( ERR_ARG,"-------------------------" );
    }
	
	//---------------------------------------------------------------
	// OPEN CURSOR
	/* EXEC SQL OPEN STOCK_INFO; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (         void  *)StockNo;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)StockNo;
 sqlstm.sqhstl[1] = (unsigned int  )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	if( SQLCODE != SQLOK ) {
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"커서 STOCK_INFO 오픈시 에러발생 [%d]-[%s]", SQLCODE, SQLERRM );
		log_printf( ERR_ARG,"-------------------------" );
    }
	
	//---------------------------------------------------------------
	// FETCH CURSOR
	int li_FetchCount = 0;
	
	int isLoop = TRUE;
	
	//---------------------------------------------------------------
	while( isLoop ) {
	
		//---------------------------------------------------------------
		// FETCH STRUCT INIT
		memset( (char *)&st_stock_info_rslt, 0x00, sizeof(STOCK_INFO_RSLT) );
		
		//---------------------------------------------------------------
		// FETCH
		/* EXEC SQL FETCH STOCK_INFO INTO :st_stock_info_rslt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )28;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)st_stock_info_rslt.STOCK_NO;
  sqlstm.sqhstl[0] = (unsigned int  )7;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)st_stock_info_rslt.STOCK_NM;
  sqlstm.sqhstl[1] = (unsigned int  )201;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)st_stock_info_rslt.OPEN_DT;
  sqlstm.sqhstl[2] = (unsigned int  )9;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)st_stock_info_rslt.AREA_NM;
  sqlstm.sqhstl[3] = (unsigned int  )7;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		
		if(SQLCODE != SQLOK && SQLCODE != SQLNODATA) {

			log_printf( ERR_ARG,"커서 STOCK_INFO FETCH 에러발생 [%d]-[%s]", SQLCODE, SQLERRM );
            isLoop = FALSE;
			/* EXEC SQL CLOSE STOCK_INFO; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )59;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



		} else if(SQLCODE == SQLNODATA ) {
		
			isLoop = FALSE;
            break;
			
		}
		//---------------------------------------------------------------
		// USING FETCH DATA DO
		// 입력된 기초 정보로 주가생성 시작
		CreateVirtualStockData( &st_stock_info_rslt );
			
		//---------------------------------------------------------------
		li_FetchCount++;
	}
	// END OF WHILE

	//---------------------------------------------------------------
	// CLOSE CURSOR	
	/* EXEC SQL CLOSE STOCK_INFO; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )74;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	
	//-------------------------------------------------------------------------
	return (RETURN_TRUE);
}


/***********************************************************
    종목별 주가 생성
***********************************************************/
int CreateVirtualStockData( STOCK_INFO_RSLT *stock_info_rslt )
{
	//-------------------------------------------------------------------------
	// 기초정보 디버그 출력
	PrintStockInfoData( stock_info_rslt );
	
	//-------------------------------------------------------------------------
	// 주가 생성 MAIN FUNCION
	CalculateStockData( stock_info_rslt );
	
	return (RETURN_TRUE);
}

/***********************************************************
    주가 생성 MAIN FUNCION
***********************************************************/
int CalculateStockData( STOCK_INFO_RSLT *stock_info_rslt )
{
	int i = 0; /* FOR LOOP */
	int rtn = TRUE;
	
    STOCK_BASE st_stock_base;
    
    memset( (char *)&st_stock_base, 0x00,   sizeof(STOCK_BASE) );
	//-------------------------------------------------------------------------
	// 주가 기본 정보 생성 시작
	
	//-------------------------------------------------------------------------
	// 기초정보 조회 및 입력
	int li_StockCount = 0; // 종목갯수
		
	//---------------------------------------------------------------
	// 기초 정보 생성 테스트용
	st_stock_base.StrtPrice  = 10000; 	// 시작가   
	st_stock_base.ChngRatio  = 2.00;	// 변화비율 
	st_stock_base.CalcType   = 1; 		// 계산방식 
	st_stock_base.PrblDist   = 1; 		// 확률분포 
	st_stock_base.LevyAlpha  = 1.7; 	// LEVY 알파
	st_stock_base.LevyFactor = 2; 		// LEVY 팩터
	st_stock_base.Days       = 252; 	// 계산일수 
	
	//---------------------------------------------------------------
	// 기초 정보 체크
	
	// 시작단가 500원 이상
	if( st_stock_base.StrtPrice < 500 ) {
	
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"시작가격은 500보다 커야함" );
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"시작가      :[%ld]"     ,st_stock_base.StrtPrice  );
		log_printf( ERR_ARG,"-------------------------" );
		
		return (RETURN_FALSE);
	}
	
	// 변화비율
	if( st_stock_base.ChngRatio < 1.00 ) {
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"변화비율은 1.0보다 커야함" );
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"변화비율    :[%04f]"    ,st_stock_base.ChngRatio  );
		log_printf( ERR_ARG,"-------------------------" );
		return (RETURN_FALSE);
	}
	
	// 계산방식
	if( !(	st_stock_base.CalcType == 0 ||
			st_stock_base.CalcType == 1 ||
			st_stock_base.CalcType == 2 ) ) {
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"계산방식 0/1/2 만 사용됨" );
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"변화비율    :[%04f]"    ,st_stock_base.ChngRatio  );
		log_printf( ERR_ARG,"-------------------------" );
		return (RETURN_FALSE);
	}
	
	// 확률분포
	if( !(	st_stock_base.PrblDist == 0 ||
			st_stock_base.PrblDist == 1 ||
			st_stock_base.PrblDist == 2 ) ) {
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"확률분포 0/1/2 만 사용됨" );
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"변화비율    :[%04f]"    ,st_stock_base.PrblDist  );
		log_printf( ERR_ARG,"-------------------------" );
		return (RETURN_FALSE);
	}
	
	// LEVY 알파/팩터 체크 (확률분포 1일때만
	if( st_stock_base.PrblDist == 1 &&
		( st_stock_base.LevyAlpha <= 0 || st_stock_base.LevyFactor > 2 )) {
	
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"LEVY 알파는 1.0 보다 커야하고 팩터보다 작아야함" );
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"LEVY 알파    :[%04f]"    ,st_stock_base.LevyAlpha   );
		log_printf( ERR_ARG,"LEVY 팩터    :[%04f]"    ,st_stock_base.LevyFactor  );
		log_printf( ERR_ARG,"-------------------------" );
		
		return (RETURN_FALSE);
	
	}
	
	// 생성일
	if( st_stock_base.Days < 1 ) {
	
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"계산일수은 1보다 커야함" );
		log_printf( ERR_ARG,"-------------------------" );
		log_printf( ERR_ARG,"계산일수    :[%ld]"     ,st_stock_base.Days   );
		log_printf( ERR_ARG,"-------------------------" );
		
		return (RETURN_FALSE);
	}
	
	//-------------------------------------------------------------------------
	// 종목 기본 정보 출력
	PrintStockBaseData( &st_stock_base );
	
	//-------------------------------------------------------------------------
	// 일수만큼 STOCK DATA 변수 MALLOC
	long *li_StockPrice = NULL;
	li_StockPrice = (long *)malloc( sizeof(long) * st_stock_base.Days );
	
	//-------------------------------------------------------------------------
	if( li_StockPrice != NULL ) {
	
		memset( li_StockPrice,0x00, sizeof(long) * st_stock_base.Days );
	
		// 일수만큼 STOCK DATA 계산
		for( i = 0; i < st_stock_base.Days; i++ ) {
			
			rtn = GenerateStockData(&st_stock_base,i,(long *)&li_StockPrice[i]);
			
			if ( rtn == RETURN_FALSE ) {
				
				log_printf( ERR_ARG,"-------------------------" );
				log_printf( ERR_ARG,"주가 일별 생성중 에러 발생" );
				log_printf( ERR_ARG,"-------------------------" );
				
				free(li_StockPrice);
				return (RETURN_FALSE);
				
			}
			/*
			log_printf( DBG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>" );
			log_printf( DBG_ARG,"[%04d] PRICE : [%ld]" , i, li_StockPrice[i] );
			log_printf( DBG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>" );
			*/
						
		} 	
		// END OF FOR LOOP
	}
	// END OF IF
	
	//-------------------------------------------------------------------------
	// TODO : 종목정보와 함께 데이터 저장
		
	// ----------------------------------------------------
	// 금액을 생성하다 오류날 경우에 INSERT ROLLBACK 이 힘드므로 어레이에 담아 놓았다가
	// 정상 생성이 되면 한방에 INSERT 후 COMMIT
	{
		// MERGE INTO
	}
	/*
	EXEC SQL COMMIT WORK;
	*/
	//-------------------------------------------------------------------------
	// 종목정보와 함께 데이터 저장 종료
	//-------------------------------------------------------------------------
	
	free(li_StockPrice);
	// 주가 기본 정보 생성 종료
	//-------------------------------------------------------------------------
    return (RETURN_TRUE);
}

/***********************************************************
    주가 일별 생성
***********************************************************/
int GenerateStockData( STOCK_BASE *st_stock_base, int Day, long *StockPrice ) {

	long lc_StockPrice = 0;
	//---------------------------------------------------------------
	// 주가 일별 생성
	
	//---------------------------------------------------------------
	// 주가 일별 생성 결과저장
	(* StockPrice) = lc_StockPrice;
	//-------------------------------------------------------------------------
    return (RETURN_TRUE);
	
}

/***********************************************************
    종목 기본정보 출력
***********************************************************/
void PrintStockInfoData( STOCK_INFO_RSLT *stock_info_rslt )
{
    log_printf( DBG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>" );
    log_printf( DBG_ARG,"종목번호    :[%s]" ,stock_info_rslt->STOCK_NO );
    log_printf( DBG_ARG,"종목명      :[%s]" ,stock_info_rslt->STOCK_NM );
    log_printf( DBG_ARG,"상장일      :[%s]" ,stock_info_rslt->OPEN_DT	 );
    log_printf( DBG_ARG,"지역명      :[%s]" ,stock_info_rslt->AREA_NM	 );
    log_printf( DBG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>" );
}

/***********************************************************
    주가생성 기준정보 출력
***********************************************************/
void PrintStockBaseData( STOCK_BASE *st_stock_base )
{
    log_printf( DBG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>" );
    log_printf( DBG_ARG,"시작가      :[%ld]"     ,st_stock_base->StrtPrice  );
    log_printf( DBG_ARG,"변화비율    :[%04f]"    ,st_stock_base->ChngRatio  );
    log_printf( DBG_ARG,"계산방식    :[%d]"      ,st_stock_base->CalcType   );
    log_printf( DBG_ARG,"확률분포    :[%04f]"    ,st_stock_base->PrblDist   );
    log_printf( DBG_ARG,"LEVY 알파   :[%04f]"    ,st_stock_base->LevyAlpha  );
    log_printf( DBG_ARG,"LEVY 팩터   :[%04f]"    ,st_stock_base->LevyFactor );
    log_printf( DBG_ARG,"계산일수    :[%ld]"     ,st_stock_base->Days       );
    log_printf( DBG_ARG,">>>>>>>>>>>>>>>>>>>>>>>>>" );
}

/* EOF */
