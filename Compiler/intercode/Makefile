CC = gcc
CFLAG = -g

FLEX = flex
BISON = bison
MAIN = main.c

C_LEX = lex.yy.c
C_SYN = syntax.tab.c
C_SEM = semantic.c inter.c
H_SYN = syntax.tab.h 
H_SEM = semantic.h inter.h
C_ALL = $(C_LEX) $(C_SEM) $(C_SYN)
OBJS = $(C_ALL:.c=.o)

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
	rm -f parser lex.yy.c syntax.tab.c syntax.tab.h syntax.output
	rm -f $(OBJS) $(OBJS:.o=.d)
	rm -f *~
	



