all: analyseDTD
analyseDTD: *.l *.y makefile
	flex  -Pdtd dtd.l
	bison  --debug -p dtd --verbose --defines=dtd.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -o analyseDTD  lex.dtd.c dtd.tab.c \
	../src/DTD.cpp \
	../src/Contenu.cpp \
	../src/contenusequence.cpp \
	../src/contenuchoix.cpp \
	../src/contenusimple.cpp \
	../src/DeclarationElement.cpp \
	../src/DeclarationAttribut.cpp

clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD

