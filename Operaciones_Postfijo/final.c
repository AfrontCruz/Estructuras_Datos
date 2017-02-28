#include "PilaDin.h"
#include <stdio.h>
#include <stdlib.h>

boolean Verify_Parenthesis (char *auxiliar);
char *Postfijo (char *cadena);

char *
Postfijo (char *cadena)
{
  pila operadores;
  char *postfijo;
  element e;
  int i, j;

  Initialize (&operadores);

  for (i = 0, j = 0; cadena[i] != '\n'; i++)
    {
      switch (cadena[i])
		{
			case '(':
			  e.conteo = cadena[i];
			  Push (&operadores, e);
			  break;
			case '+':
			case '-':
			case '*':
			case '/':
			  e.conteo = cadena[i];
			  Push (&operadores, e);
			  break;
			case ')':
			  e.conteo = cadena[i];
			  while (e.conteo != '(')
			    {
			      postfijo = realloc (postfijo, sizeof (char) * (j + 2));
			      postfijo[j] = e.conteo;
			      e = Pop (&operadores);
			      j++;
			    }
			  break;
			default:
			  postfijo = realloc (postfijo, sizeof (char) * (j + 2));
			  postfijo[j] = cadena[i];
			  j++;
		}
    }
  Destroy (&operadores);

  return postfijo;
}

boolean
Verify_Parenthesis (char *auxiliar)
{
  pila parentesis;
  element e;
  int i;
  boolean verify;

  Initialize (&parentesis);

  for (i = 0; auxiliar[i] != '\n'; i++)
    {
      if (auxiliar[i] == '(')
		{
		  e.conteo = '(';
		  Push (&parentesis, e);
		}
	  else if (auxiliar[i] == ')')
		{
		  if (Empty (&parentesis))
		    {
		      verify = FALSE;
		      return verify;
		    }
		  Pop (&parentesis);
		}
    }

  if (!Empty (&parentesis))
    verify = FALSE;
  else
    verify = TRUE;

  Destroy (&parentesis);

  return verify;
}

int
main (void)
{
  char auxiliar[101], *postfijo;

  fgets (auxiliar, 100, stdin);

  if (!Verify_Parenthesis (auxiliar))
    {
      puts ("Hay un error en paréntesis.");
      return 0;
    }

  postfijo = Postfijo (auxiliar);
  puts (postfijo);
  free (postfijo);

  return 0;
}
