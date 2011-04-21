#include<cstdlib>
#include<cstdio>
#include "commun.h"
#include "../src/DTD.h"
#include "../src/XMLDocument.h"

#include <regex.h>

/*#include "xml.tab.h"
#include "dtd.tab.h"*/

//#include<iostream>
int xmlparse(void);
int dtdparse(void);

extern XMLDocument *docXML;
extern DTD *docDTD;

extern FILE * xmlin;
extern FILE * dtdin;

int main(int argc, char **argv)
{
  int err = -1;
  int errXML, errDTD;

  FILE *fidXML, *fidDTD;

  if(argc != 2){
 	printf("Parse ended with %d error(s)\n", err);
  }

  /* Analyse XML */
  fidXML = fopen(argv[1], "r");
  xmlin  = fidXML;

  errXML = xmlparse();
  fclose(fidXML);
  if (errXML != 0) printf("Parse XML ended with %d error(s)\n", errXML);
  	else  printf("Parse XML ended with sucess\n", errXML);


  /* Analyse DTD */
  fidDTD = fopen(argv[2], "r");
  dtdin  = fidDTD;

  errDTD = dtdparse();
  fclose(fidXML);
  if (errDTD != 0) printf("Parse DTD ended with %d error(s)\n", errDTD);
  	else  printf("Parse DTD ended with sucess\n", errDTD);




  printf("\n%s\n\n",docDTD->getRoot()->getElementName().c_str());
  return 0;

}
