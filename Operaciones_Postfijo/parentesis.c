#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

boolean Verify_Parenthesis(char *auxiliar)
{
    pila parentesis;
    element e;
    int i;
    boolean verify;

    Initialize(&parentesis);

    for(i = 0; auxiliar[i] != '\n'; i++)
    {
        if(auxiliar[i] == '(')
        {
            e.conteo = '(';
            Push(&parentesis, e);
        }
        else if(auxiliar[i] == ')')
        {
            if(Empty(&parentesis))
            {
                verify = FALSE;
                return verify;
            }
            Pop(&parentesis);
        }
    }

        if(!Empty(&parentesis))
            verify = FALSE;
        else
            verify = TRUE;

        Destroy(&parentesis);

        return verify;
}


char *Postfijo(char *cadena)
{
    pila operadores;
    char *postfijo = 0;
    element e;
    int i, j;

    Initialize(&operadores);

    for(i = 0, j = 0; cadena[i] != '\n'; i++)
    {
      switch(cadena[i])
      {
          case '(':
          e.conteo = cadena[i];
          Push(&operadores, e);
          break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        
        if(!Empty(&operadores)){
            postfijo = realloc(postfijo, sizeof(char) *(j+2));
            e = Pop(&operadores);
            postfijo[j] = e.conteo;
            j++;
            break;
        }
          e.conteo = cadena[i];
          Push(&operadores, e);
          break;
        case ')':
          e = Pop(&operadores);
          while(e.conteo != '(')
          {
            postfijo = realloc(postfijo, sizeof(char)*(j+2));
            postfijo[j] = e.conteo;
            e = Pop(&operadores);
              j++;
          }
          if(!Empty(&operadores))
          {
            e = Pop(&operadores);
            postfijo = realloc(postfijo, sizeof(char)*(j+2));
            postfijo[j] = e.conteo;
            j++;
          }
          break;
        default:
          postfijo = realloc(postfijo, sizeof(char)*(j+2));
          postfijo[j] = cadena[i];
            j++;
      }
    }

    while(!Empty(&operadores))
      {
        e = Pop(&operadores);
        postfijo = realloc(postfijo, sizeof(char)*(j+2));
        postfijo[j] = e.conteo;
        j++;
      }
      postfijo[j] = '\0';
    Destroy(&operadores);

    return postfijo;
}

int main (void){
      char auxiliar[101], *postfijo;

    fgets(auxiliar, 100, stdin);

    if(!Verify_Parenthesis(auxiliar))
    {
        puts("No estan bien los parentesis");
    } else {
    puts("Estan bien los parentesis");
}

postfijo = Postfijo(auxiliar);
puts (postfijo);
    return 0;
}
