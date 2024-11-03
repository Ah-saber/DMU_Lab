CC = gcc
CFLAGS = -Wall -g


HEADER = cd.h help.h exit.h
EXEC = main
SUB_EXEC = pwd.o ls.o
SUB_SRC = $(SUB_EXEC):%.c

BIN_DIR = ./bin


all: $(BIN_DIR) $(EXEC) $(SUB_EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(EXEC): main.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ $^

$(SUB_EXEC): %.o :%.c
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@  


clean:
	rm -rf  $(BIN_DIR)/
	rm -f $(EXEC)
	rm -f *.o
