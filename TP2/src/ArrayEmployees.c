#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int idAutoGenerico = 1;

int initEmpleados(eEmpleado listaEmpleados[],int lenEmpleados)
{
	int i;
    for(i=0;i < lenEmpleados;i++)
    {
    	listaEmpleados[i].isEmpty = LIBRE;
    }
    return 0;
}


int addEmpleado(eEmpleado listaEmpleados[],int lenEmpleados,char nombre[],char apellido[],float salario,int sector)
{
    int i;
    char banderaEmpty = 'n';
    for(i = 0;i < lenEmpleados;i++)
    {
        if(listaEmpleados[i].isEmpty == LIBRE)
        {
        	listaEmpleados[i].id = idAutoGenerico;
        	listaEmpleados[i].isEmpty = OCUPADO;
            strcpy(listaEmpleados[i].nombre,nombre);
            strcpy(listaEmpleados[i].apellido,apellido);
            listaEmpleados[i].salario = salario;
            listaEmpleados[i].sector = sector;
            banderaEmpty = 's';
            break;
        }
    }

    if(banderaEmpty == 'n')
    {
        return -1;
    }

    idAutoGenerico=idAutoGenerico+1;
    return 0;
}

int buscarEmpleadoPorId(eEmpleado listaEmpleados[],int lenEmpleados,int id)
{
    int i;
    for(i = 0;i < lenEmpleados;i++)
    {
        if(listaEmpleados[i].id == id)
        {
           return i;
        }
    }
    return -1;
}

int eliminarEmpleado(eEmpleado listaEmpleados[],int lenEmpleados,int id)
{
    int i;
    for(i=0;i<lenEmpleados;i++)
    {
        if(listaEmpleados[i].id == id)
        {
        	listaEmpleados[i].isEmpty = LIBRE;
           return 0;
        }
    }
    return -1;
}


int ordenarEmpleados(eEmpleado listaEmpleados[],int lenEmpleados,int orden)
{
    int i;
    int j;
    eEmpleado auxEmployee;

    for(i=0; i<lenEmpleados-1; i++)
    {
        for(j=i+1; j<lenEmpleados; j++)
        {
            if(strcmp(listaEmpleados[i].apellido,listaEmpleados[j].apellido)>0 && listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO)
            {
                if(orden == 1)
                {
                    auxEmployee =  listaEmpleados[i];
                    listaEmpleados[i] = listaEmpleados[j];
                    listaEmpleados[j] = auxEmployee;
                }else if(orden == 0)
                {
                    auxEmployee =  listaEmpleados[j];
                    listaEmpleados[j] = listaEmpleados[i];
                    listaEmpleados[i] = auxEmployee;
                }
            }
            else
            {
               if(strcmp(listaEmpleados[i].apellido,listaEmpleados[j].apellido)==0)
               {
                   if(listaEmpleados[i].sector>listaEmpleados[j].sector)
                   {
                        if(orden == 1)
                        {
                            auxEmployee =  listaEmpleados[i];
                            listaEmpleados[i] = listaEmpleados[j];
                            listaEmpleados[j] = auxEmployee;
                        }else if(orden == 0)
                        {
                            auxEmployee =  listaEmpleados[j];
                            listaEmpleados[j] = listaEmpleados[i];
                            listaEmpleados[i] = auxEmployee;
                        }
                   }
               }
            }
        }
    }
    return 0;
}

int imprimirEmpleados(eEmpleado listaEmpleados[],int lenEmpleados)
{
    int i;
    printf("%8s %20s %20s %10s %8s\n", "Id",
                                       "Nombre",
                                       "Apellido",
                                       "Salario",
                                       "Sector");

    for(i = 0; i < lenEmpleados; i++)
    {
          if(listaEmpleados[i].isEmpty == OCUPADO)
            {
        	  imprimirEmpleado(listaEmpleados[i]);
            }
    }
    return 0;
}

void imprimirEmpleado(eEmpleado miEmpleado)
{
    printf("%8d %20s %20s %10.2f %8d\n", miEmpleado.id,
    									 miEmpleado.nombre,
										 miEmpleado.apellido,
										 miEmpleado.salario,
										 miEmpleado.sector);
}

int modificarEmpleado(eEmpleado listaEmpleados[],int posicion)
{
    int opcion;
	int sector;
    char nombre[51];
    char apellido[51];
    float salario;
    puts("Ingrese el numero de opcion a modificar\n");
    puts("1. Nombre\n");
    puts("2. Apellido\n");
    puts("3. Salario\n");
    puts("4. Sector\n");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        printf("Ingrese el nuevo nombre de %s\n", listaEmpleados[posicion].nombre);
        scanf("%s", nombre);
        strcpy(listaEmpleados[posicion].nombre,nombre);
        break;

    case 2:
        printf("Ingrese el nuevo apellido de %s\n", listaEmpleados[posicion].apellido);
        scanf("%s", apellido);
        strcpy(listaEmpleados[posicion].apellido,apellido);
        break;

    case 3:
        printf("Ingrese el nuevo salario. Salario anterior: %.2f\n", listaEmpleados[posicion].salario);
        scanf("%f", &salario);
        listaEmpleados[posicion].salario = salario;
        break;

    case 4:
        printf("Ingrese el nuevo sector. Sector anterior: %d\n", listaEmpleados[posicion].sector);
        scanf("%d", &sector);
        listaEmpleados[posicion].sector = sector;
        break;
    }

    return 0;
}

void calcularSalario(eEmpleado listaEmpleados[],int lenEmpleados)
{
    float salarioTotal=0;
    float salarioPromedio;
    int contadorEmpleados=0;
    int contadorEmpleadosSalario=0;
    int i;
    for(i = 0; i < lenEmpleados; i++)
    {
      if(listaEmpleados[i].isEmpty == OCUPADO)
      {
    	  salarioTotal += listaEmpleados[i].salario;
    	  contadorEmpleados++;
      }
    }
    salarioPromedio = salarioTotal / contadorEmpleados;
    for(i = 0; i < lenEmpleados; i++)
    {
      if(listaEmpleados[i].isEmpty == OCUPADO)
      {
        if(listaEmpleados[i].salario >= salarioPromedio)
        {
        	contadorEmpleadosSalario++;
        }
      }
    }
    printf("\nEl salario total es: %.2f\nEl promedio de los salarios es: %.2f\n%d empleados superan o igualan el salario promedio\n",
    		salarioTotal, salarioPromedio, contadorEmpleadosSalario);
}

int chequearEmpleados(eEmpleado listaEmpleados[],int lenEmpleados)
{
    int i;
    for(i = 0; i < lenEmpleados; i++)
    {
        if(listaEmpleados[i].isEmpty == OCUPADO)
        {
            return 1;
        }
    }
    return 0;
}
