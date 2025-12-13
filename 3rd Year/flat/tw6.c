//YACC CODE 
%{
#include<stdio.h>
#include<stdlib.h> 
int yylex();       /* Prototype to avoid warnings */
void yyerror(char *s);
%}

%left '+' '-'
%left '*' '/'
%token D

%%
s: e '\n' {printf("expression is valid and its value is %d \n", $1);}
;
e: e '+' e  { $$ = $1 + $3; }
 | e '-' e  { $$ = $1 - $3; }
 | e '*' e  { $$ = $1 * $3; }
 | e '/' e  { 
     if($3 == 0) {
         printf("Divide by Zero error\n");
         exit(0);
     } else {
         $$ = $1 / $3; 
     }
   }
 | '(' e ')' { $$ = $2; }
 | D        { $$ = $1; }
;
%%

int main(){
    printf("Enter the arithmetic expression: ");
    yyparse();
    return 0;
}

void yyerror (char * s){
    printf("Expression is Not Valid \n");
}

// LEX CODE 
%{
#include "y.tab.h"
#include <stdlib.h> 
extern int yylval;
%}

%%
[0-9]+  {yylval = atoi(yytext); return D;} 
[\+\-\/\*\(\)] {return yytext[0];}
[\n]    {return yytext[0];}
.       { ; }
%%
