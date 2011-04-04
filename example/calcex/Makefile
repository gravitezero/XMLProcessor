
srcdir = .

CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = 

LEX = /usr/bin/flex
LEXFLAGS = -Pcalc_
YACC = /usr/local/bin/bison
YACCFLAGS =  --defines --name-prefix=calc_


all: calc

calc: lex.calc_.o calc.tab.o
	gcc -o calc lex.calc_.o calc.tab.o

lex.calc_.o: lex.calc_.c calc.tab.h
	gcc -c lex.calc_.c

calc.tab.o: calc.tab.c calc.tab.h
	gcc -c calc.tab.c

lexer: lex.calc_.c

parser: calc.tab.c calc.tab.h

lex.calc_.c: calc.l calc.h
	/usr/bin/flex -Pcalc_ calc.l

calc.tab.c calc.tab.h: calc.y calc.h
	/usr/local/bin/bison --defines --name-prefix=calc_ calc.y

clean-object:
	rm -f lex.calc_.o calc.tab.o

clean-lexer:
	rm -f lex.calc_.c

clean-parser:
	rm -f calc.tab.c calc.tab.h

clean: clean-object clean-lexer clean-parser 

