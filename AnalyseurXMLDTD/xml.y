%{

using namespace std;
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "commun.h"
#include "xml.tab.h"

int xmlwrap(void);
void xmlerror(char *msg);
int xmllex(void);

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
   empty_or_content 
 ;
start
 : START		
 | NSSTART	
 ;
empty_or_content
 : SLASH CLOSE	
 | close_content_and_end 
   name_or_nsname_opt CLOSE 
 ;

attributs
 : attributs NAME EQ VALUE
 | /* empty */
 ;

name_or_nsname_opt 
 : NAME     
 | NSNAME  
 | /* empty */
 ;
close_content_and_end
 : attributs CLOSE			
   content 
   END 
 ;
content 
 : content DATA		
 | content misc        
 | content element      
 | /*empty*/         
 ;
%%
/*
int main(int argc, char **argv)
{
  int err;

  err = xmlparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  	else  printf("Parse ended with sucess\n", err);
  return 0;
}
*/
int xmlwrap(void)
{
  return 1;
}

void xmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

