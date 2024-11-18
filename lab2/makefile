CC = gcc
CFLAGS = -Wall -g


HEADER = cd.h help.h exit.h
EXEC = 2202222948_mysh 
MAIN = main.c
SUB_EXEC = pwd.o ls.o rm.o mkdir.o wc.o cat.o echo.o
SUB_SRC = $(SUB_EXEC):%.c

BIN_DIR = ./bin
SRC_DIR = ./src


all: $(BIN_DIR) $(EXEC) $(SUB_EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(EXEC): $(SRC_DIR)/$(MAIN) $(addprefix $(SRC_DIR)/, $(HEADER))
	$(CC) $(CFLAGS) -o $@ $^

$(SUB_EXEC): %.o : $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@  


clean:
	rm -rf  $(BIN_DIR)/
	rm -f $(EXEC)
	rm -f *.o
