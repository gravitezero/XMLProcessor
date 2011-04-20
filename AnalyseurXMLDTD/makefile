all: analyseDTD
analyseXML: *.l *.y makefile
	flex  -Pxml xml.l 
	bison --debug -p xml --verbose --defines=xml.tab.h xml.y
analyseDTD: *.l *.y makefile
	flex  -Pxml xml.l 
	bison --debug -p xml --verbose --defines=xml.tab.h xml.y
	flex   -Pdtd dtd.l
	bison  --debug -p dtd --verbose --defines=dtd.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -o analyseXMLDTD  lex.xml.c lex.dtd.c dtd.tab.c xml.tab.c main.c  \
	../src/XMLDocument.cpp \
	../src/ElementComplexe.cpp \
	../src/ElementTextuel.cpp \
	../src/Declaration.cpp \
	../src/Doctype.cpp \
	../src/VisitorDisplay.cpp \
	../src/DTD.cpp \
	../src/Contenu.cpp \
	../src/contenusequence.cpp \
	../src/contenuchoix.cpp \
	../src/contenusimple.cpp \
	../src/DeclarationElement.cpp \
	../src/DeclarationAttribut.cpp
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXMLDTD
