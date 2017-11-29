
TARGET 		= call
TOP_DIR 	= $(shell pwd)
CC 			= $(CROSS_COMPILE)gcc
PYTHON_PATH = /usr/include/python2.7

INCLUDE     = -I$(PYTHON_PATH)
LDFLAGS     = -lpython2.7
CFLAGS      = -Wall -g
#MAKEFLAGS   += --silent

SRC = ./call.c

.SUFFIXES:.c .o

OBJS = $(SRC:.c=.o)

.c.o:
	@echo COMPILING: $<
	$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<

all: app

app: $(OBJS)
	@echo "    >>LINKING: $(TARGET)"
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -vf $(OBJS) $(TARGET)

obj-clean:
	rm -vf $(OBJS)
