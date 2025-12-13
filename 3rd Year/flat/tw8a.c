// LEX CODE 
%{
#include "y.tab.h"
%}

%%
if          { return IF; }
else        { return ELSE; }
"<="        { return LE; }
">="        { return GE; }
"!="        { return NE; }
"=="        { return EQ; }
[<>]        { return yytext[0]; }
[a-zA-Z]+   { return ID; }
[\+\-\*\/\=] { return yytext[0]; }
[\(\)\{\}\;] { return yytext[0]; }
\n          { return yytext[0]; }
%%

//YACC CODE 
%{
#include <stdio.h>
%}

%token IF ELSE ID LE GE NE EQ

%%

S : S1 '\n' { printf("Valid if statement\n"); }
  ;

S1 : IF '(' cond ')' '{' S1 '}' ELSE '{' S2 '}'
   ;

cond : ID relop ID
     ;

relop : '<'
      | '>'
      | LE
      | GE
      | NE
      | EQ
      ;

S2 : ID '=' ID op ID ';'
   ;

op : '+'
   | '-'
   | '*'
   | '/'
   ;

%%

int main() {
    printf("Enter statement: \n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Not a valid If statement\n");
}

int yywrap() {
    return 1;
}