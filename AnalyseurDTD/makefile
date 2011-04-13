all: analyseDTD
analyseDTD: *.l *.y makefile
	flex  dtd.l
	bison  --debug --verbose --defines=yy.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -o analyseDTD  lex.yy.c dtd.tab.c \
	../src/DTD.cpp \
	../src/Contenu.cpp \
	../src/contenusequence.cpp \
	../src/contenuchoix.cpp \
	../src/contenusimple.cpp \
	../src/DeclarationElement.cpp \
	../src/DeclarationAttribut.cpp

clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD

