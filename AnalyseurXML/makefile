all: analyseXML
analyseXML: *.l *.y makefile
	flex  -Pxml xml.l
	bison --debug -p xml --verbose --defines=xml.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.xml.c  xml.tab.c \
	../src/XMLDocument.cpp \
	../src/ElementComplexe.cpp \
	../src/ElementTextuel.cpp \
	../src/Declaration.cpp \
	../src/Doctype.cpp \
	../src/VisitorDisplay.cpp
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML

