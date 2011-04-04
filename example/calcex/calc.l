
%{

	/* From Aho, Seti, Ullman, fig. 4.58, p. 265, but somewhat extended
	   by Hans Aberg. */


#include "calc.h"

#define yylval calc_lval

#include "calc.tab.h"



%}

%option noyywrap

digit		[0-9]
number		{digit}+\.?|{digit}*\.{digit}+
identifier  [a-zA-Z]+

%%

[ ]			 { /* Skip blanks. */ }
{number}	 { sscanf(yytext, "%lf", &yylval.value);
			   return NUMBER; }
"sqrt"       { yylval.name = yytext; yylval.length = yyleng; return SQRT; }
"pi"         { yylval.name = yytext; yylval.length = yyleng; return PI; }
"exit"		 { return EXIT; }
\n|.		 { return yytext[0]; }

%%

