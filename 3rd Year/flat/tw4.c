%{
#include <stdio.h>
#include <string.h>

int n=10, key=0, id=0, cons=0, op=0, punct=0;
char *keywords[] = {"int", "include", "printf", "float", "char", "double", "for"};
char temp[100];

int iskeyword(char *word) {
    for (int i = 0; i < n; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
%}

digit [0-9]+
id [a-zA-Z][a-zA-Z0-9]*
operator [\+\-\*\/\=<>]
punctuation [,\.;:\(\)\{\}\"%#]

%%
[\t ]+ {;}
{digit} {cons++;}
{id} {
    strcpy(temp, yytext);
    if (iskeyword(temp))
        key++;
    else
        id++;
}
{operator} {op++;}
{punctuation} {punct++;}
.|\n {;}
%%

int main(){
  printf("Enter lexemes\n");
  yylex();
  printf("Keywords = %d\n", key);
  printf("IDs = %d\n", id);
  printf("Consonants = %d\n", cons);
  printf("Operators = %d\n", op);
  printf("Punctuation symbols = %d\n", punct);
  return 0;
}
