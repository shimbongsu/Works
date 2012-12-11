#/*****************************************************************************/
#/* NEW DELTA DATE : 2002.05.21                                               */
#/* BLOCK          : Makefile                                                 */
#/* VERSION        : 1.00                                                     */
#/* DATE           : 2002.01.18                                               */
#/* AUTHOR         : LGNSYS                                                   */
#/* HISTORY        : 1. 2002.01.18 Prototype                                  */
#/* FUNCTIONS      :                                                          */
#/* DESCRIPTION    : makefile                                                 */
#/* REMARKS        :                                                          */
#/*                                                                           */
#/* COPYRIGHT¿Î LGN-Sys Ltd. 2002, 2004                                       */
#/*****************************************************************************/

#-----------------------------------------------------------------------
# Include Rule file
include common.rule

#-----------------------------------------------------------------------
# Compile Flags
CFLAGS =
PCCFLAGS = DURATION=TRANSACTION CLOSE_ON_COMMIT=NO AUTO_CONNECT=NO \
		MODE=ORACLE SQLCHECK=SYNTAX MAXOPENCURSORS=50 \
		RELEASE_CURSOR=YES UNSAFE_NULL=YES DEFINE=DEBUG \
		DBMS=V8 CHAR_MAP=STRING

#-----------------------------------------------------------------------
# Define Flags
#DFLAGS = -DUSER_BIG_ENDIAN

#-----------------------------------------------------------------------
# include path 
#COMINC = $(BPPLUS)/work/inc

#-----------------------------------------------------------------------
# include
INCS  = -I$(ORACLE_HOME)/rdbms/demo \
	    -I$(ORACLE_HOME)/precomp/public \
	    -I$(ORACLE_HOME)/rdbms/public \
	    -I$(ORACLE_HOME)/plsql/public \
	    -I$(ORACLE_HOME)/network/public

PCCINCS = include=$(ORACLE_HOME)/precomp/public \
	      include=$(ORACLE_HOME)/rdbms/public \
	      include=$(ORACLE_HOME)/rdbms/demo \
	      include=$(ORACLE_HOME)/plsql/public \
	      include=$(ORACLE_HOME)/network/public 

#-----------------------------------------------------------------------
# lib path 
OLIBS= -L$(ORACLE_HOME)/lib -lclntsh -ldl -lc -lm -lclient10 -lsql10

LIBS=$(SOCKLIB) $(COMLIB) $(ORALIBS) $(SYSLIBS)

#-----------------------------------------------------------------------
# Src File 
PRCS = main.pc dbutil.pc
SOURCES = log.c

#-----------------------------------------------------------------------
# load name & path
LOAD_FILE = example

# ---------------------------------------------------------------------
all: $(LOAD_FILE) targetecho
clobber: clobberlib

$(LOAD_FILE): $(OBJS)
# 	generate binary file ### 
	@echo =======================================================
	@echo BUILD
	@echo =======================================================
#	$(CC) $(LIBLIC) $(OLIBS) $(LIBS) -o $(LOAD_FILE) $(OBJS)
	$(CC) $(LIBLIC) $(OLIBS) -o $(LOAD_FILE) $(OBJS)

