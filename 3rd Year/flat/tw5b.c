//YACC CODE 
%{
#include <stdio.h>
%}

%token A B C

%%
S : S1 '\n' { printf("Valid\n"); }
  ;
S1 : A S1 A
   | B S1 B
   | C
   ;
%%
int main(){
    printf("Enter the string:");
    yyparse();
    return 0;
}

void yyerror(const char *s){
    printf("Invalid\n");
}
//LEX CODE 
%{
#include "y.tab.h"
%}

"a"   { return A; }
"b"   { return B; }
"\n"  { return yytext[0]; }
"c"   { return C; }

%%
