#/*****************************************************************************/
#/* NEW DELTA DATE : 2012.12.11.                                              */
#/* BLOCK          : Makefile                                                 */
#/* VERSION        : 1.00                                                     */
#/* DATE           : 2012.12.11.                                              */
#/* AUTHOR         : marantz                                                  */
#/* HISTORY        :                                                          */
#/* FUNCTIONS      :                                                          */
#/* DESCRIPTION    : makefile                                                 */
#/* REMARKS        :                                                          */
#/*****************************************************************************/

#-----------------------------------------------------------------------
# Include Rule file
include common.rule

#-----------------------------------------------------------------------
# Compile Flags
#CFLAGS=-fconstant-string-class=NSConstantString
#GSFLAGS=`gnustep-config --objc-flags`
CFLAGS=$(GSFLAGS)

#-----------------------------------------------------------------------
# Define Flags
DFLAGS=-g -ggdb

#-----------------------------------------------------------------------
# include path 
NSSTEP_INC=-I/usr/include/GNUstep/

#-----------------------------------------------------------------------
# include
INCS=$(NSSTEP_INC)

#-----------------------------------------------------------------------
# lib path 
NSSTEP_LIB=-lobjc -L/usr/lib/GNUstep/ -lgnustep-base

#-----------------------------------------------------------------------
# lib
LIBS=$(NSSTEP_LIB)

#-----------------------------------------------------------------------
# Src File 
SOURCES = main.m

#-----------------------------------------------------------------------
# load name & path
LOAD_FILE = test

# ---------------------------------------------------------------------
all: $(LOAD_FILE) targetecho
clobber: clobberlib

$(LOAD_FILE): $(OBJS)
# 	generate binary file ### 
	@echo =======================================================
	@echo BUILD
	@echo =======================================================
	$(CC) $(INCS) $(CFLAGS) -o $(LOAD_FILE) $(OBJS) $(LIBS)
	
#EOF
