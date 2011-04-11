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

DTD() * doc;

%}

%union { 
   char *s;
   list<Contenu *> *lc;
   DTD *dtd;
   DeclarationAtt *dAtt;
   DeclarationElt *dElt;
   Contenu *content;
   list<Attribut> *lAtt;
   Attribut *Att;
   }

%token <s> ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> NAME TOKENTYPE DECLARATION STRING
%%

%type <lc> list_choice list_choice_plus list_sequence;
%type <dtd> main;
%type <dAtt> attlist;
%type <dElt> element;
%type <content> choice sequence choice_or_sequence item;
%type <lAtt> att_definition;
%type <Att> attribut;
%type <s> cardinality att_type type_enumere liste_enum_plus liste_enum item_enum;
%type <s> defaut_declaration;


main
 : main attlist { $1->addAtt($2); $$ = $1;}
 | main element { $1->addElt($2); $$ = $1;}
 |/* empty */ { doc = new DTD(); $$ = doc;}
 ;

attlist
 : ATTLIST NAME att_definition CLOSE {$$ = new DeclarationAtt($2,$3);}
 ;


element
 : ELEMENT NAME choice_or_sequence CLOSE {$$ = new DeclarationElt($2,$3);}
 ;

choice_or_sequence
 : choice cardinality {$1->setCardinality($2); $$ = $1;} 
 | sequence cardinality {$1->setCardinality($2); $$ = $1;}
 ;

sequence
 : OPENPAR list_sequence CLOSEPAR {if ($2->size() !=1) {$$ = new ContenuSequence($2);} else {$$ = $2->begin()}}
 ;

choice
 : OPENPAR list_choice_plus CLOSEPAR {$$ = new ContenuChoix($2);}
 ;

list_choice_plus
 : list_choice PIPE item {$$ = $1; $$->push_back($3);}
 ;

list_choice
 : item  {$$ = new list<Contenu>(); $$->push_back($1);}
 | list_choice PIPE item {$$ = $1; $$->push_back($3);}
 ;

list_sequence
 : item  {$$ = new list<Contenu>(); $$->push_back($1)}
 | list_sequence COMMA item {$$ = $1; $$->push_back($3);}
 ;

item /*on renvoie un contenu*/
 : NAME cardinality {$$ = new ContenuSimple($1,doc); $$->setCardinality($2);}
 | PCDATA {$$ = new ContenuSimple($1,doc);}
 | choice_or_sequence cardinality {$1->setCardinality($2); $$ = $1;}
 ;

cardinality
 : AST {$$ = $1;}
 | QMARK {$$ = $1;}
 | PLUS {$$ = $1;}
 | /*empty*/ {$$ = "";}
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
 : DECLARATION {$$ = $1;} 
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
