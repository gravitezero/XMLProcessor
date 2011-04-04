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

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL

%%

document
 : declarations element misc_seq_opt 
 ;
misc_seq_opt
 : misc_seq_opt misc
 | /*empty*/
 ;
misc
 : COMMENT		
 ;

declarations
 : declaration
 | /*empty*/
 ;
 
declaration
 : DOCTYPE NAME NAME VALUE CLOSE 
 ;

element
 : start          
   empty_or_content {$$ = new Element($1,$2);} //on construit un element à partir de son nom $1 et de ses fils $2
 ;
start
 : START {$$ = $1;}		
 | NSSTART {$$ = $1;}	
 ;
empty_or_content
 : SLASH CLOSE	{$$ = NULL;}
 | close_content_and_end name_or_nsname_opt CLOSE 
 ;

attributs
 : attributs NAME EQ VALUE {$$ = $1; $$->push.back(make_pair($2,$4));}
 | /* empty */ {$$ = new_list<Attribut>();}
 ;

name_or_nsname_opt 
 : NAME     
 | NSNAME  
 | /* empty */
 ;
close_content_and_end
 : attributs CLOSE content END ;
content 
 : content DATA		
 | content misc        
 | content element      
 | /*empty*/         
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

