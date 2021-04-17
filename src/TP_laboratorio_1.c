/*Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funcione*/
#include <stdio.h>
#include <stdlib.h>
#include "saraceno.h"

int main(void)
{
	setbuf(stdout,NULL);
	float ingresoNumeroA;
	float ingresoNumeroB;
	int selector;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivicion;
	float resultadoMultiplicacion;
	float resultadoFactorialA;
	float resultadoFactorialB;

	ingresoNumeroA=0;
	ingresoNumeroB=0;

	while(selector!=5)
	{
		printf("1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n");
		scanf("%d",&selector);
		switch(selector)
		{
			case 1:
				ingresoNumeroA=ingresoVariableX();
			break;
			case 2:
				ingresoNumeroB=ingresoVariableY();
			break;
			case 3:
				resultadoSuma = realizarSumatoria(ingresoNumeroA,ingresoNumeroB);
				resultadoResta = realizarResta(ingresoNumeroA,ingresoNumeroB);
				resultadoDivicion = realizarDivicion(ingresoNumeroA,ingresoNumeroB);
				resultadoMultiplicacion = realizarMultiplicacion(ingresoNumeroA,ingresoNumeroB);
				resultadoFactorialA = realizarFactorial(ingresoNumeroA);
				resultadoFactorialB = realizarFactorial(ingresoNumeroB);
				printf("Se han realizado con exito tus calculos");
			break;

			case 4:
				printf("El resultado de %.2f + %.2f es: %.2f \n", ingresoNumeroA, ingresoNumeroB, resultadoSuma);
				printf(" El resultado de %.2f - %.2f es: %.2f \n", ingresoNumeroA, ingresoNumeroB, resultadoResta);
				if(ingresoNumeroB==0)
				{
					printf("No es posible dividir por cero\n");
				}
				else
				{
				printf("El resultado de %.2f / %.2f es: %.2f \n", ingresoNumeroA, ingresoNumeroB, resultadoDivicion);
				}
				printf("El resultado de %.2f * %.2f es: %.2f \n", ingresoNumeroA, ingresoNumeroB, resultadoMultiplicacion);
				printf("El factorial de %.2f es: %.2f y El de %.2f es: %.2f\n", ingresoNumeroA, resultadoFactorialA, ingresoNumeroB, resultadoFactorialB);
			break;

			case 5:
				printf("gracias por usar la calculadora cientifica");
				system("exit");
			break;

			default:
				printf("ESTA MAL\tiene que ser de las opciones");
				scanf("%d",&selector);
			break;
		}
	}

	return EXIT_SUCCESS;
}
