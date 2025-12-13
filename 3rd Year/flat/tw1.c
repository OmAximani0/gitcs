%{
    #include <stdio.h>

    int wc = 0, lc = 0, cc = 0;  
%}
word    [a-zA-Z]+
%%

[\t ]+          { cc += yyleng; }    
\n              { lc++; cc++; }
{word}          { wc++; cc += yyleng; }
.               { cc++; }

%%

int yywrap() { return 1; }

int main() {
    printf("Enter the input:\n");
    yylex();
    printf("No of words: %d\n", wc);
    printf("No of lines: %d\n", lc);
    printf("No of characters: %d\n", cc);
    return 0;
}
