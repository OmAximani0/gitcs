// 5 A YACC CODE  
%{
#include <stdio.h>
%}

%token A B

%%
S : S1 '\n' { printf("Valid\n"); }
  ;
S1 : A S1 B
   | 
   ;
%%
int main(){
    printf("Enter string:");
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
" "   { ; }

%%


