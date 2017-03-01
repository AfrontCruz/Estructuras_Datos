#include "PilaDin.h"
#include <stdio.h>
#include <stdlib.h>

float
Realizar_operaciones (char *postfijo, float *variables)
{
  int i, j;
  float resultado = 0;
  pila operaciones;
  elemento e;

  Initialize (&operaciones);

  for (i = 0; postfijo[i] != '\0'; i++)
    {
      if (postfijo[i] >= 'A' && postfijo[i] <= 'Z')
	{
	  e.valor = variables[postfijo[i] - 'A'];
	  Push (&operaciones, e);
	  continue;
	}
      switch (postfijo[i])
	{
	  float variable_1, variable_2;
	case '+':
	  variable_2 = Pop (&operaciones).valor;
	  variable_1 = Pop (&operaciones).valor;
	  e.valor = variable_1 + variable_2;
	  Push (&operaciones, e);
	  break;
	case '-':
	  variable_2 = Pop (&operaciones).valor;
	  variable_1 = Pop (&operaciones).valor;
	  e.valor = variable_1 - variable_2;
	  Push (&operaciones, e);
	  break;
	case '*':
	  variable_2 = Pop (&operaciones).valor;
	  variable_1 = Pop (&operaciones).valor;
	  e.valor = variable_1 * variable_2;
	  Push (&operaciones, e);
	  break;
	case '/':
	  variable_2 = Pop (&operaciones).valor;
	  variable_1 = Pop (&operaciones).valor;
	  e.valor = variable_1 / variable_2;
	  Push (&operaciones, e);
	  break;
	case '^':
	  variable_2 = Pop (&operaciones).valor;
	  variable_1 = Pop (&operaciones).valor;
	  e.valor = variable_1;
	  for (j = 1; j < variable_2; j++)
	    e.valor *= variable_1;
	  Push (&operaciones, e);
	}
    }

  resultado = Pop (&operaciones).valor;

  Destroy (&operaciones);

  return resultado;
}

float *
Obtener_variables (char *postfijo)
{
  float *valores = malloc (sizeof (float) * 27);
  int i;

//Inicializamos a cero el arreglo que contendrá los valores de las variables.
  for (i = 0; i < 27; i++)
    valores[i] = 0.0f;
//Buscamos qué variables aparecen en la operación.
  for (i = 0; postfijo[i] != '\0'; i++)
    if (postfijo[i] >= 'A' && postfijo[i] <= 'Z')
      valores[postfijo[i] - 'A']++;
  for (i = 0; i < 27; i++)
//Pedimos los varoler de todas las variables.
    for (i = 0; i < 27; i++)
      if (valores[i] > 0)
	{
	  printf ("\nIntroduzca el valor de %c: ", 'A' + i);
	  scanf ("%f", valores + i);
	}

  return valores;
}

char *
Postfijo (char *cadena)
{
  pila operadores;
  char *postfijo;
  elemento e;
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
				if(!Empty(&operadores))
				{
					e = Pop(&operadores);
					while(!Empty(&operadores)
						&& e.conteo != '('
						&& (e.conteo == '*'
						|| e.conteo == '/'
						|| e.conteo == '^'
						|| e.conteo == '+'
						|| e.conteo == '-'))
					{
						postfijo = realloc(postfijo, sizeof(char) * (j + 2));
						postfijo[j++] = e.conteo;
						e = Pop(&operadores);
					}
					//if(e.conteo == '(')
						Push(&operadores, e);
					e.conteo = cadena[i];
					Push(&operadores, e);
				}
				else
				{
					e.conteo = cadena[i];
					Push(&operadores, e);
				}
				break;
			case '*':
			case '/':
				if(!Empty(&operadores))
				{
					e = Pop(&operadores);
					while(!Empty(&operadores)
						&& e.conteo != '('
						&& (e.conteo == '*'
						|| e.conteo == '/'
						|| e.conteo == '^'))
					{
						postfijo = realloc(postfijo, sizeof(char) * (j + 2));
						postfijo[j++] = e.conteo;
						e = Pop(&operadores);
					}
					//if(e.conteo == '(')
						Push(&operadores, e);
					e.conteo = cadena[i];
					Push(&operadores, e);
				}
				else
				{
					e.conteo = cadena[i];
					Push(&operadores, e);
				}
				break;
			case '^':
				e.conteo = cadena[i];
				Push(&operadores, e);
				break;
			case ')':
			  e = Pop(&operadores);
			  while (e.conteo != '(')
			    {
			      postfijo = realloc (postfijo, sizeof (char) * (j + 2));
			      postfijo[j++] = e.conteo;
			      e = Pop (&operadores);
			    }
			  break;
			default:
			  postfijo = realloc (postfijo, sizeof (char) * (j + 2));
			  postfijo[j] = cadena[i];
			  j++;
		}
    }

    while(!Empty(&operadores))
    {
    	postfijo = realloc (postfijo, sizeof (char) * (j + 2));
    	e = Pop(&operadores);
    	postfijo[j++] = e.conteo;
    }

    postfijo = realloc (postfijo, sizeof (char) * (j + 2));
    postfijo[j] = '\0';

  Destroy (&operadores);

  return postfijo;
}

boolean
Verify_Parenthesis (char *auxiliar)
{
  pila parentesis;
  elemento e;
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
  float resultado, *variables;

  fgets (auxiliar, 100, stdin);

  if (!Verify_Parenthesis (auxiliar))
    {
      puts ("Hay un error en paréntesis.");
      return 0;
    }

  postfijo = Postfijo (auxiliar);

  variables = Obtener_variables (postfijo);
  resultado = Realizar_operaciones (postfijo, variables);

  printf("\nLa operación en postfijo es: %s\n", postfijo);
  printf("\nEl resultado de la operación es: %.2f\n", resultado);

  return 0;
}