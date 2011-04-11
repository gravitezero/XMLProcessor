all: analyseXML
analyseXML: *.l *.y makefile
	flex  xml.l
	bison --debug --verbose --defines=yy.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.yy.c  xml.tab.c \
	../src/XMLDocument.cpp \
	../src/ElementComplexe.cpp \
	../src/ElementTextuel.cpp \
	../src/Declaration.cpp \
	../src/Doctype.cpp \
	../src/VisitorDisplay.cpp
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML

