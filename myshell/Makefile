CC = gcc
CFLAGS = -Wall -g


HEADER = cd.h help.h exit.h
EXEC = main
SUB_EXEC = pwd.o
SUB_SRC = $(SUB_EXEC:.o=.c)

BIN_DIR = ./bin


all: $(BIN_DIR) $(EXEC) $(BIN_DIR)/$(SUB_EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(EXEC): main.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)/$(SUB_EXEC): %.o :$(SUB_SRC)
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf  $(BIN_DIR)/
	rm -f $(EXEC)
