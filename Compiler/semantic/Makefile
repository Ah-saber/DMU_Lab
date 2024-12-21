CC = gcc
CFLAG = -g

FLEX = flex
BISON = bison
MAIN = main.c

C_LEX = lex.yy.c
C_SYN = syntax.tab.c
C_SEM = semantic.c
H_SYN = syntax.tab.h 
H_SEM = semantic.h

EXEC = parser

all: $(C_LEX) $(C_SYN)  $(EXEC)

$(EXEC): $(MAIN) $(C_SYN) $(C_SEM)
	$(CC) $(CFLAG) $^ -lfl -o $@ 



$(C_LEX): lexical.l
	$(FLEX) $^

$(C_SYN) $(H_SYN): syntax.y $(C_LEX)
	${BISON} -d -t -v $<

$(C_SEM:.c=.o): $(H_SEM)
	$(CC) $(CFILES) $^

clean:
	rm *.yy.c
	rm *.tab.*
	rm $(EXEC)
	



