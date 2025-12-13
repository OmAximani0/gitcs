//yacc code 
%{
#include <stdio.h>
#include <stdlib.h>
%}
%left '+' '-'
%left '*' '/'
%token D ID
%%
s: e '\n' {printf("Exp is valid and its value is %d", $1);}
;
e: e '+' e  { printf("+"); }
 | e '-' e  { printf("-"); }
 | e '*' e  { printf("*"); }
 | e '/' e  { printf("/"); }
 | '(' e ')' {;}
 | D        { printf("%d", $1); }
 | ID       { printf("0"); }
;
%%
int main(){
    printf("Enter the arithmatic exp: ");
    printf("Exp is mode of single digit [0-9] and char: ");
    yyparse();
    return 0;
}
void yyerror(const char *s){
    printf("Exp is invalid");
}

//lex code 
%{
#include "y.tab.h"
#include <stdlib.h>
extern int yylval;
%}
%%
[0-9]  { yylval = atoi(yytext); return D; }
a      { return ID; }
[\+\-\*\/\(\)] { return yytext[0]; }
[\n]   { return yytext[0]; }
%%