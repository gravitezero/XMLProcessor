%{
using namespace std;
#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>


void yyerror(char *msg);
int yywrap(void);
int yylex(void);
%}

%union { 
   char *s; 
   }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> NAME TOKENTYPE DECLARATION STRING
%%

main
 : main attlist { $1->addAtt($2); $$ = $1;}
 | main element { $1->addElt($2); $$ = $1;}
 |/* empty */ { $$ = new DTD();}
 ;

attlist
 : ATTLIST NAME att_definition CLOSE {$$ = new DeclarationAtt($2,$3);}
 ;


element
 : ELEMENT NAME choice_or_sequence CLOSE {$$ = new DeclarationElt($2,$3);}
 ;

choice_or_sequence
 : choice cardinality 
 | sequence cardinality
 ;

sequence
 : OPENPAR list_sequence CLOSEPAR {$$ = $2;}
 ;

choice
 : OPENPAR list_choice_plus CLOSEPAR {$$ = $2;}
 ;

list_choice_plus
 : list_choice PIPE item {$$ -> $1; $$->push_back($3);}
 ;

list_choice
 : item  // si list_sequence est une liste alors push_back, sinon créer une liste ???
 | list_choice PIPE item {$$ -> $1; $$->push_back($3);}
 ;

list_sequence
 : item  // si list_sequence est une liste alors push_back, sinon créer une liste ???
 | list_sequence COMMA item {$$ -> $1; $$->push_back($3);}
 ;

item
 : NAME cardinality
 | PCDATA
 | choice_or_sequence cardinality
 ;

cardinality
 : AST
 | QMARK
 | PLUS
 | /*empty*/
 ;



att_definition
 : att_definition attribut {$$ = $1; $$->push_back($2);}
 | /* empty */ {new list<Attribut>();}
 ;

attribut
 : NAME att_type defaut_declaration {$$ = new Attribut($1,$2,$3);}
 ;

att_type
 : CDATA {$$ = $1;}
 | TOKENTYPE
 | type_enumere
 ;

// OLD

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

// \OLD

defaut_declaration
 : DECLARATION 
 | STRING     
 | FIXED STRING 
 ;

%%
int main(int argc, char **argv)
{
  int err;
  yydebug=1;

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


