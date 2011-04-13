%{
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>

#include "../src/commun.h"
#include "../src/XMLDocument.h"
#include "../src/Doctype.h"
#include "../src/ElementComplexe.h"
#include "../src/ElementTextuel.h"

using namespace std;

int yywrap(void);
void yyerror(char *msg);
int yylex(void);

XMLDocument *doc;

%}

%union {
   char * s;
   ElementName *en;  /* le nom d'un element avec son namespace */
   AttList *la;

   XMLDocument *xdoc;
   Element *el;
   Doctype *dc;
   Declaration * de;
      
   list<Declaration * > * ld;
   list<Element *> *ct;
}


%token <s> EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL

%type <xdoc> document
%type <el> element
%type <s>  misc_seq_opt
%type <s>  misc
%type <ct> content
%type <ct> close_content_and_end
%type <ct> empty_or_content
%type <en>  start
%type <s>  name_or_nsname_opt

%type <de> declaration
%type <dc> doctype

%type <la> attributs
%type <ld> declarations

%%

document
 : declarations element misc_seq_opt { doc->setElement($2); $$ = doc;}
 ;

misc_seq_opt
 : misc_seq_opt misc {$$ = $1;}
 | /*empty*/ { $$ = "";}
 ;

misc
 : COMMENT {$$ = $1;}		
 ;

declarations
 : declarations declaration {$$ = $1; $$->push_back($2);}
 | declarations doctype {$$ = $1; $$->push_back($2);}
 | /*empty*/ {doc = new XMLDocument(); $$ = new list<Declaration *>; doc->setHeader($$);} 
 ;
 
doctype
 : DOCTYPE NAME NAME VALUE CLOSE {$$ = new Doctype($2,$3,$4);}
 ;

declaration
 : STARTSPECIAL attributs CLOSESPECIAL {$$ = new Declaration($2);}
 ;

element
 : start attributs empty_or_content {$$ = new ElementComplexe($1,$2,$3);} //on construit un element à partir de son nom $1 et de ses fils $2
 ;

start
 : START {$$ = $1;}		
 | NSSTART {$$ = $1;}	
 ;

empty_or_content
 : SLASH CLOSE	{$$ = NULL;}
 | close_content_and_end name_or_nsname_opt CLOSE {$$ = $1;}
 ;

attributs
 : attributs NAME EQ VALUE {$$ = $1; Attribut *a = new Attribut; *a = make_pair($2,$4); $$->push_back(a);}
 | /* empty */ {$$ = new AttList;}
 ;

name_or_nsname_opt 
 : NAME {$$ = $1;}
 | NSNAME  {$$ = $1;}
 | /* empty */ {$$ = "";}
 ;

close_content_and_end
 : CLOSE content END {$$ = $2;}
 ;

content 
 : content DATA {$$ = $1; $$->push_back(new ElementTextuel($2));}		
 | content misc {$$ = $1;}	// on ignore les commentaires misc = COMMENT        
 | content element {$$ = $1; $$->push_back($2);}     
 | /*empty*/ {$$ = new list<Element * >();}        
 ;

%%

int main(int argc, char **argv)
{
  int err;

  err = yyparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  	else  printf("Parse ended with sucess\n", err);
  return 0;
}
int yywrap(void)
{
  return 1;
}

void yyerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

