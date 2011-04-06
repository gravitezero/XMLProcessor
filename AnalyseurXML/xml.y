%{

using namespace std;
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "commun.h"
#include "yy.tab.h"

int yywrap(void);
void yyerror(char *msg);
int yylex(void);

XMLDocument *doc;

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
   list<pair<string,string>> *la;

}


%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL

%type <la> attributs

%%

document
 : declarations element misc_seq_opt { doc.setElement($2); $$ = doc;}
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
 | declarations doctype {$$ = $1; $$->push_back($2); doc->setHeader($1);}
 | /*empty*/ {declarations = new List<Declaration *>;} 
 ;
 
doctype
 : DOCTYPE NAME NAME VALUE CLOSE {$$ = new Doctype($2,$3,$4); doc = new XMLDocument($2,$3,$4); }
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
 : attributs NAME EQ VALUE {$$ = $1; $$->push_back(make_pair($2,$4));}
 | /* empty */ {$$ = new_list<Attribut>();}
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
 | /*empty*/ {$$ = new List<Element>();}        
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

