#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Validation.h"
#define EMPLOYEES_LEN 1000

int main(void)
{
	setbuf(stdout, NULL);

	eEmpleado listaEmpleados[EMPLOYEES_LEN];
	int opcion;
	int a;
	int sector;
	int m;
	int idMod;
	int b;
	int idEliminar;
	int i;

	char nombre[51];
	char apellido[51];
	char nombreFunc[51];
	char apellidoFunc[51];

	float salario;

	int init;

	init = initEmpleados(listaEmpleados,EMPLOYEES_LEN);
    if(init == 0)
    {
        printf("Empleado inicializados correctamente");
    }else {
        printf("No se pudo inicializar los empleados");
    }

    do
        {
            system("cls");
            printf("1. Alta de empleado\n");
            printf("2. Modificar empleado\n");
            printf("3. Baja de empleado\n");
            printf("4. Informar\n");
            printf("5. Salir\n");
            printf("Elija una opcion: ");

            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                getString("Ingrese el nombre: ", nombreFunc);
                while(isOnlyLetters(nombreFunc) == 0)
                {
                	fflush(stdin);
                    printf("Por favor ingrese un nombre valido\n");
                    getString("Ingrese el nombre: ", nombreFunc);
                }

                getString("Ingrese el apellido: ", apellidoFunc);
                while(isOnlyLetters(apellidoFunc) == 0)
                {
                	fflush(stdin);
                    printf("Por favor ingrese un apellido valido\n");
                    getString("Ingrese el apellido: ", apellidoFunc);
                }

                strcpy(nombre, nombreFunc);
                strcpy(apellido, apellidoFunc);

                salario = getFloat("Ingrese el salario: ");
                while(isPositive(salario) == 0)
                {
                    printf("Por favor ingrese un salario valido\n");
                    salario = getFloat("Ingrese el salario: ");
                }

                sector = getInt("Ingrese el sector: ");
                while(isPositive(sector) == 0)
                {
                	fflush(stdin);
                    printf("Por favor ingrese un sector valido\n");
                    sector = getInt("Ingrese el sector: ");
                }

                a = addEmpleado(listaEmpleados, EMPLOYEES_LEN, nombre,
                		apellido, salario, sector);
                if(a == 0)
                {
                    printf("Empleado agregado correctamente\n");
                }else {
                    printf("No se pudo agregar el empleado\n");
                }
                system("pause");
                fflush(stdin);
                break;
            case 2:
                if(chequearEmpleados(listaEmpleados, EMPLOYEES_LEN) == 1)
                {
                    printf("Ingrese el id del empleado a modificar: ");
                    scanf("%d", &idMod);
                    m = buscarEmpleadoPorId(listaEmpleados, EMPLOYEES_LEN, idMod);
                    if(m != -1)
                    {
                    	modificarEmpleado(listaEmpleados, m);
                    }else {
                        printf("No se pudo modificar el empleado, Ingrese un id valido\n");
                    }
                } else
                {
                    printf("Primero debe cargar un empleado\n");
                }

                system("pause");
                break;
            case 3:
                if(chequearEmpleados(listaEmpleados, EMPLOYEES_LEN) == 1)
                {
                	fflush(stdin);
                    printf("Ingrese el id del empleado a borrar: ");
                    scanf("%d", &idEliminar);
                    b = eliminarEmpleado(listaEmpleados, EMPLOYEES_LEN, idEliminar);
                    if(b == 0)
                    {
                        printf("Empleado borrado correctamente\n");
                    }else {
                        printf("No se pudo borrar el empleado, Ingrese un id valido\n");
                    }
                } else
                {
                    printf("Primero debe cargar un empleado\n");
                }
                system("pause");
                break;
            case 4:
                if(chequearEmpleados(listaEmpleados, EMPLOYEES_LEN) == 1)
                {
                    i = ordenarEmpleados(listaEmpleados, EMPLOYEES_LEN, 1);
                    if(i == 0)
                    {
                        system("cls");
                        printf("Los empleados se ordenaron correctamente\n");
                        imprimirEmpleados(listaEmpleados, EMPLOYEES_LEN);
                        calcularSalario(listaEmpleados, EMPLOYEES_LEN);
                    }else {
                        system("cls");
                        printf("No se pudo ordenar los empleados correctamente\n");
                    }
                } else
                {
                    printf("Primero debe cargar un empleado\n");
                }
                system("pause");
                break;
            case 5:
                break;
            default:
                printf("\nOpcion incorrecta");
                system("pause");
                break;
            }
        } while(opcion != 5);
	return EXIT_SUCCESS;
}
