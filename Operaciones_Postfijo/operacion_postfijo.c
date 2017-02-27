#include <stdio.h>
#include <stdlib.h>
#include "PilaDin.h"

float Realizar_operaciones(char *postfijo, float *variables)
{
  int i, j;
  float resultado = 0;
  pila operaciones;
  element e;

	Initialize(&operaciones);

	for(i = 0; postfijo[i] != '\n'; i++)
	{
		if(postfijo[i] >= 'A' && postfijo[i] <= 'Z')
		{
			e.valor = variables[postfijo[i] - 'A'];
			Push(&operaciones, e);
			break;
		}
		switch(postfijo[i])
		{
			float variable_1, variable_2;
			case '+':
				e = Pop(&operaciones);
				variable_1 = e.valor;
				e = Pop(&operaciones);
				variable_2 = e.valor;
				e.valor = variable_1 + variable_2;
				Push(&operaciones, e);
				break;
			case '-':
				e = Pop(&operaciones);
				variable_1 = e.valor;
				e = Pop(&operaciones);
				variable_2 = e.valor;
				e.valor = variable_1 - variable_2;
				Push(&operaciones, e);
				break;
			case '*':
				e = Pop(&operaciones);
				variable_1 = e.valor;
				e = Pop(&operaciones);
				variable_2 = e.valor;
				e.valor = variable_1 * variable_2;
				Push(&operaciones, e);
				break;
			case '/':
				e = Pop(&operaciones);
				variable_1 = e.valor;
				e = Pop(&operaciones);
				variable_2 = e.valor;
				e.valor = variable_1 / variable_2;
				Push(&operaciones, e);
				break;
			case '^':
				variable_1 = Pop(&operaciones).valor;
				variable_2 = Pop(&operaciones).valor;
				e.valor = variable_1;
				for(j = 1; j < variable_2; j++)
					e.valor *= variable_1;
				Push(&operaciones, e);
		}
	}

	e = Pop(&operaciones);
	resultado = e.valor;

	Destroy(&operaciones);

	return resultado;
}

float *Obtener_variables (char *postfijo)
{
	int i;
	float *valores = malloc(sizeof(valores) * 27);

//Inicializamos a cero el arreglo que contendrá los valores de las variables.
	for (i = 0; i < 27; i++)
		valores[i] = 0;
//Buscamos qué variables aparecen en la operación.
	for (i = 0; postfijo[i] != '\n'; i++)
		if(postfijo[i] >= 'A' && postfijo[i] <= 'Z')
			valores[postfijo[i] - 'A']++;
//Pedimos los varoler de todas las variables.
	for (i = 0; i < 27; i++)
		if (valores[i] > 0)
		{
			//printf("\nIntroduzca el valor de %c: ", 'A' + i);
			scanf("%f", &valores[i]);
		}

	return valores;
}

int main (void)
{
	char postfijo[101];
	float resultado = 0, *variables;
	int i;

	fgets(postfijo, 100, stdin);

	variables = Obtener_variables(postfijo);
	resultado = Realizar_operaciones(postfijo, variables);

	free(variables);

	printf("\nEl resultado es: %d\n", resultado);

	return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include "TADPilaDin.h"

int Realizar_operaciones(char *postfijo, int *variables)
{
	int resultado = 0, i, j;
	pila operaciones;
	elemento e;

	Initialize(&operaciones);

	for(i = 0; postfijo[i] != '\n'; i++)
	{
		if(postfijo[i] >= 'A' && postfijo[i] <= 'Z')
		{
			e.valor = variables[postfijo[i] - 'A'];
			Push(e, &operaciones);
			break;
		}
		switch(postfijo[i])
		{
			int variable_1, variable_2;
			case '+':
				variable_1 = Pop(&operaciones).valor;
				variable_2 = Pop(&operaciones).valor;
				e.valor = variable_1 + variable_2;
				Push(e, &operaciones);
				break;
			case '-':
				variable_1 = Pop(&operaciones).valor;
				variable_2 = Pop(&operaciones).valor;
				e.valor = variable_1 - variable_2;
				Push(e, &operaciones);
				break;
			case '*':
				variable_1 = Pop(&operaciones).valor;
				variable_2 = Pop(&operaciones).valor;
				e.valor = variable_1 * variable_2;
				Push(e, &operaciones);
				break;
			case '/':
				variable_1 = Pop(&operaciones).valor;
				variable_2 = Pop(&operaciones).valor;
				e.valor = variable_1 / variable_2;
				Push(e, &operaciones);
				break;
			case '^':
				variable_1 = Pop(&operaciones).valor;
				variable_2 = Pop(&operaciones).valor;
				e.valor = variable_1;
				for(j = 1; j < variable_2; j++)
					e.resultado *= variable_1;
				Push(e, &operaciones);
		}
	}

	resultado = Pop(&operaciones).valor;

	Destroy(&operaciones);

	return resultado;
}

int *Obtener_variables (char *postfijo)
{
	int i, *valores = malloc(sizeof(int) * 27);

//Inicializamos a cero el arreglo que contendrá los valores de las variables.
	for (i = 0; i < 27; i++)
		valores[i] = 0;
//Buscamos qué variables aparecen en la operación.
	for (i = 0; postfijo[i] != '\n'; i++)
		if(postfijo[i] >= 'A' && postfijo[i] <= 'Z')
			valores[postfijo[i] - 'A']++;
//Pedimos los varoler de todas las variables.
	for (i = 0; i < 27; i++)
		if (valores[i] > 0)
		{
			printf("\nIntroduzca el valor de: %c", 'A' + i);
			scanf("%d", valores + i);
		}

	return valores;
}

int main (void)
{
	char postfijo[101];
	int resultado = 0, *variables, i;

	fgets(postfijo, 100, stdin);

	variables = Obtener_variables(postfijo);
	resultado = Realizar_operaciones(postfijo, variables);

	free(variables);

	printf("\nEl resultado es: %d", resultado);

	return 0;
}
