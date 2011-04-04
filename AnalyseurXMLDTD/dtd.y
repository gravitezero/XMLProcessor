%{
using namespace std;
#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>


void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);
%}

%union { 
   char *s; 
   }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> NAME TOKENTYPE DECLARATION STRING
%%

main: main dtd
    | main element
    |/* empty */
    ;

dtd: ATTLIST NAME 
     att_definition CLOSE;


element: ELEMENT NAME choice_or_sequence cardinality CLOSE;

choice_or_sequence: choice | sequence;

sequence: OPENPAR list_sequence CLOSEPAR;

choice: OPENPAR list_choice_plus CLOSEPAR;

list_choice_plus: list_choice PIPE item;

list_choice: item
	| list_choice PIPE item;

list_sequence: item
	| list_sequence COMMA item;

item: NAME cardinality
    | PCDATA
    | choice_or_sequence cardinality;

cardinality: AST|QMARK|PLUS|/*empty*/;



att_definition
: att_definition attribut
| /* empty */
;

attribut
: NAME att_type defaut_declaration
;

att_type
: CDATA    
| TOKENTYPE
| type_enumere
;

type_enumere
: OPENPAR liste_enum_plus CLOSEPAR
;

liste_enum_plus
: liste_enum PIPE item_enum
;

liste_enum
: item_enum               
| liste_enum PIPE item_enum
;

item_enum
: NAME
;

defaut_declaration
: DECLARATION 
| STRING     
| FIXED STRING 
;
%%
/*
int main(int argc, char **argv)
{
  int err;
  dtddebug=1;

  err = dtdparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with sucess\n", err);
  return 0;
}
*/

int dtdwrap(void)
{
  return 1;
}

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


