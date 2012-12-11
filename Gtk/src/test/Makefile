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
CC=g++
CFLAG=$(GTK_GCC_OPTION)
DFLAG=-D__DEBUG__
#DFLAG =

############################################################
# Set Include Files
############################################################
USERS_INC_DIR=-I/usr/include
LOCAL_INC_DIR=-I/usr/local/include
INC=$(LOCAL_INC_DIR) $(USERS_INC_DIR)

############################################################
# Set Directories
############################################################
HOME_DIR = 
COMMON_LIB_DIR =
NETWRK_LIB_DIR =
SOCKET_LIB_DIR =
ORACLE_LIB_DIR =
CURL_LIB_DIR =/usr/local/lib 
LOLCAL_LIB_DIR =/usr/local/lib
LD_LIB_DIR =$(LD_LIBRARY_PATH)

############################################################
# Set Library Files
############################################################
#TERMCAP_LIB=-lncurses
LOCLAL_LIB =
NETWRK_LIB =
SOCKET_LIB =
ORACLE_LIB =
COMMON_LIB =$(GTK_LIBS)

############################################################
# Set Source Files
############################################################
SRC = main.cpp
OBJ = main.o

############################################################
# Set Target Name
############################################################
TARGET = test

############################################################
# BUILD
############################################################
all :
	@echo =======================================================
	@echo BUILD
	@echo =======================================================
	$(CC) $(CFLAG) $(INC) $(DFLAG) -c $(SRC)
	
	@echo =======================================================
	@echo LINK
	@echo =======================================================
	$(CC) $(CFLAG) $(INC) $(DFLAG) -o $(TARGET) $(OBJ) $(COMMON_LIB)

clean :
	rm -rf $(OBJ) $(TARGET) core

#install :
#	cp $(TARGET) $(HOME_DIR)/bin/

# EOF #
