
%{
	/* From Aho, Seti, Ullman, fig. 4.59, p. 266, but somewhat extended
	   by Hans Aberg. Try inputs:
	     pi
		 sqrt sqrt 2143/22 - pi
		 355/113 - pi
		 22/7 - pi
	*/

#include "calc.h"

%}

%token NUMBER
%token SQRT PI
%token EXIT

%left '+' '-'
%right SQRT
%left '*' '/'
%right '^'
%right UMINUS

%%
lines:	lines expr '\n'		{ printf("%.12g\n", $2.value) }
	|	lines '\n'
	|	lines EXIT '\n'		{ return EXIT_SUCCESS; }
	|	/* empty */
	|	error '\n' 		{ printf("Please re-enter last line: ");
	                	  yyerrok; }
	;

expr:	expr '+' expr	{ $$.value = $1.value + $3.value }
	|	expr '-' expr	{ $$.value = $1.value - $3.value }
	|	expr '*' expr	{ $$.value = $1.value * $3.value }
	|	expr '/' expr	{ $$.value = $1.value / $3.value }
	|	expr '^' expr	{ $$.value = pow($1.value, $3.value) }
	|	'(' expr ')'	{ $$.value = $2.value }
	|	'-' expr  %prec UMINUS { $$.value = -$2.value }
	|	SQRT expr       { $$.value = sqrt($2.value) }
	|	PI              { $$.value = 4*atan(1) }
	|	NUMBER
	;

%%
#include <ctype.h>
#include <stdio.h>

#if 0
#include "lex.calc_.c"
#endif

#if __MWERKS__ && macintosh
#include <SIOUX.h>
#endif

int main() {
#if __MWERKS__ && macintosh
	SIOUXSettings.asktosaveonclose = 0;
	SIOUXSettings.autocloseonquit = 1;
#endif
	return yyparse();
}

int yyerror(char* errstr) {
	printf("Error: %s\n", errstr);
	return EXIT_FAILURE;
}

