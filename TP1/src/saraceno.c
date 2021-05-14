/*
 * saraceno.c
 *
 *  Created on: 17 Apr 2021
 *      Author: Santi
 */
#include "saraceno.h"

float ingresoVariableX(void)
{
	float ingreso;
	printf("ingresa el valor de X\n");
	scanf("%f",&ingreso);
	return ingreso;
}

float ingresoVariableY(void)
{
	float ingreso;
	printf("ingresa el valor de Y\n");
	scanf("%f",&ingreso);
	return ingreso;
}

float realizarSumatoria(float A,float B)
{
	float resultado;
	resultado=A+B;
	return resultado;
}

float realizarResta(float A,float B)
{
	float resultado;
	resultado=A-B;
	return resultado;
}

float realizarDivicion(float A,float B)
{
	float resultado;
	resultado=A/B;
	return resultado;
}

float realizarMultiplicacion(float A,float B)
{
	float resultado;
	resultado=A*B;
	return resultado;
}

float realizarFactorial(float A)
{
	float resultadoA;
	float i;
	for(i=1;i<=A;i++)
	{
		if (A<0)
		printf("¡Error! El factorial de un numero negativo NO existe");
	    else
	    {
			if (A>10)
			{
			printf("¡Error! El numero es demasiado grande");
			}
			else
			{
				for(i=1;i<=A;i++)
				{
					resultadoA = resultadoA+(A*i);
				}
			}
		}
	}
	return resultadoA;
}
