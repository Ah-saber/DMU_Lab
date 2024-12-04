CC = gcc

FLEX = flex

EXEC = scanner

$(EXEC): lex.yy.c
	$(CC) $^ -lfl -o $@ 

lex.yy.c: lexical.l
	$(FLEX) $^

clean:
	rm *.yy.c
	rm $(EXEC)
	



