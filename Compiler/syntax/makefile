CC = gcc

FLEX = flex
BISON = bison
MAIN = main.c

C_LEX = lex.yy.c
C_SYN = syntax.tab.c
H_SYN = syntax.tab.h

EXEC = parser

all: $(C_LEX) $(EXEC)

$(EXEC): ${MAIN} ${C_SYN}
	$(CC) $^ -lfl -o $@ 

${C_LEX}: lexical.l
	$(FLEX) $^

${C_SYN}: syntax.y
	${BISON} -d $^

clean:
	rm *.yy.c
	rm *.tab.*
	rm $(EXEC)
	



