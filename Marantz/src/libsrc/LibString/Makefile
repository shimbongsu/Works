############################################################
# Makefile for [Project Name]
# 				Create : 2005. 09. 18.
# 				Edited : 2005. 12. 09.
# 				Closed :
#
# 				Made by DongHan Kim
############################################################

############################################################
# Set Variable for Compiler
############################################################
#CC = /usr/bin/gcc
CC = gcc
CFLAG = -Waggregate-return  -Wunused \
	-O2 -Wall -W -Wpointer-arith -Wbad-function-cast \
	-Wmissing-declarations -Wnested-externs -Winline \
	-Wstrict-prototypes -Wmissing-prototypes \
	-Wcast-qual
#DFLAG = -D__DEBUG__ -D_XOPEN_SOURCE=500 
DFLAG =

############################################################
# Set Include Files
############################################################
USERS_INC_DIR = -I/usr/include
LOCAL_INC_DIR = -I/usr/local/include
INC = $(LOCAL_INC_DIR) $(USERS_INC_DIR)

############################################################
# Set Directories
############################################################
HOME_DIR = $(HOME)work/lib
COMMON_LIB_DIR =
NETWRK_LIB_DIR =
SOCKET_LIB_DIR =
ORACLE_LIB_DIR =
CURL_LIB_DIR = /usr/local/lib 
LOLCAL_LIB_DIR = /usr/local/lib
LD_LIB_DIR = $(LD_LIBRARY_PATH)

############################################################
# Set Library Files
############################################################
#TERMCAP_LIB=-lncurses
LOCLAL_LIB =
NETWRK_LIB =
SOCKET_LIB =
ORACLE_LIB =
TRHEAD_LIB =
CURL_LIB   =
COMMON_LIB = 

############################################################
# Set Source Files
############################################################
SRC = LibString.c
OBJ = LibString.o

############################################################
# Set Target Name
############################################################
TARGET = libString.so

############################################################
# BUILD
############################################################
all :
	$(CC) $(CFLAG) $(DFLAG) $(INC) -c $(SRC)
	$(CC) -shared $(CFLAG) $(DFLAG) $(INC) -L$(LD_LIB_DIR) $(COMMON_LIB) -o $(TARGET) $(OBJ)

clean :
	rm -rf $(OBJ) $(TARGET)

install :
	cp $(TARGET) $(HOME_DIR)

# EOF #
