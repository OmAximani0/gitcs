%{
#include <stdio.h>
%}
%%
[\t]+ {;}
[ab]*abb$ {printf("%s -> matches RE (a+b)*abb \n", yytext);}
^a[ab]* {printf("%s -> matches RE a(a+b)* \n", yytext);}
b*ab* {printf("%s -> matches RE b*ab* \n", yytext);}
([ab][ab][ab])* { if(yyleng % 3 == 0)
                   printf("%s -> matches RE [w] mod 3 == 0\n", yytext);}
\n {;}
.* {printf("%s -> does not matches to any RE \n", yytext);}
%%
int main(){
 printf("Enter the string of 'a' and 'b': ");
 yylex();
 return 0;
}
