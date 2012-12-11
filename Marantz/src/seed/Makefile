CC = gcc -DUSER_LITTLE_ENDIAN

#LIBLIC = -Wl,-G
LIBLIC =

#CFLAGS = -g -w
#CFLAGS = -g -Wall -W
CFLAGS =

DFLAGS=-DUSER_LITTLE_ENDIAN
#DFLAGS=-DUSER_BIG_ENDIAN

.SUFFIXES : .c .o

.c.o :
	$(CC) $(DFLAGS) $(CFLAGS) -o $*.o -c $(DFLAGS) $(CCINCS) $<

# Oracle Library

# Libevent Library
#LIBS =	-lpthread -lrt $(ORALIBS)
LIBS =

TARGET  =	seed_test

OBJECTS =	log.o\
			seed.o \
			seed_test.o

SOURCES	=	log.c\
			seed.c \
			seed_test.c 

$(TARGET) : $(OBJECTS)
	$(CC) $(LIBLIC) $(DFLAGS) $(CFLAGS) -o $(TARGET) $(OBJECTS)  $(LIBS)
	@echo =======================================================
	@echo $(TARGET) is made!!
	@echo =======================================================
	rm -rf *.lis

clean :
	rm -rf $(OBJECTS) $(TARGET) core *.lis

log.o			 : log.h log.c
ajms_seed.o      : seed.h seed.c
ajms_seed_test.o : seed.h seed_test.h seed_test.c
