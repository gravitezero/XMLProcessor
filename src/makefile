all: analyseDTD
analyseXML: *.l *.y makefile
	flex  -Pxml xml.l 
	bison --debug -p xml --verbose --defines=xml.tab.h xml.y
analyseDTD: *.l *.y makefile
	flex  -Pxml xml.l 
	bison --debug -p xml --verbose --defines=xml.tab.h xml.y
	flex   -Pdtd dtd.l
	bison  --debug -p dtd --verbose --defines=dtd.tab.h dtd.y

clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXMLDTD
