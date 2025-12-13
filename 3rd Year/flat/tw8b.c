//yacc code 
%{
#include <stdio.h>
%}

%token WHILE ID LE GE NE EQ

%%
S : S1 '\n' { printf("Valid while statement\n"); }
  ;

S1 : WHILE '(' cond ')' '{' S1 S2 '}'
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
    printf("Enter While statement: \n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid while statement\n");
}


//lex code 
%{
#include "y.tab.h"
%}

%%
while       { return WHILE; }
[<>]        { return yytext[0]; }
"<="        { return LE; }
">="        { return GE; }
"!="        { return NE; }
"=="        { return EQ; }
[a-zA-Z]+   { return ID; }
[\+\-\*\/\=] { return yytext[0]; }
[\(\)\{\}\;] { return yytext[0]; }
\n          { return yytext[0]; }
%%
