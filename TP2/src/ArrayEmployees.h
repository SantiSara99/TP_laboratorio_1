#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
} eEmpleado;

/**
 * @brief para indicar que todas las posiciones estan vacias esta funcion setea isEmpty como TRUE
 *
 * @param listaEmpleados[] eEmpleados
 * @param lenEmpleados int
 * @return int retorna (-1) if error [longitud invalida o puntero null] - (0) if ok
 */
int initEmpleados(eEmpleado listaEmpleados[],int lenEmpleados);

/**
 * @brief agregar en una lista existente los valores recibidos como parámetros en la primera posición vacía
 *
 * @param listaEmpleados[] eEmpleado
 * @param lenEmpleados int
 * @param id int
 * @param nombre[] char
 * @param apellido[] char
 * @param salario float
 * @param sector int
 * @return int retorna (-1) if error [longitud invalida o puntero null] - (0) if ok
 */
int addEmpleado(eEmpleado listaEmpleados[],int lenEmpleados,char nombre[],char apellido[],float salario,int sector);

/**
 * @brief encuentra a un empleado por su ID retornando su posicion en el array
 *
 * @param listaEmpleados[] eEmpleado
 * @param lenEmpleados int
 * @param id int
 * @return int retorna (-1) if error [longitud invalida o puntero null] - (0) if ok
 */
int buscarEmpleadoPorId(eEmpleado listaEmpleados[],int lenEmpleados,int id);

/**
 * @brief Elimina un empleado por su ID, cambia isEmpty por FALSE
 *
 * @param listaEmpleados[] eEmpleado
 * @param lenEmpleados int
 * @param id int
 * @return int retorna (-1) if error [longitud invalida o puntero null] - (0) if ok
 */
int eliminarEmpleado(eEmpleado listaEmpleados[],int lenEmpleados,int id);

/**
 * @brief ordena los elementos del array de empleados, puede ser en orden UP o DOWN (ascendente y descendente)
 *
 * @param listaEmpleados[] eEmpleado
 * @param lenEmpleados int
 * @param orden int
 * @return
 */
int ordenarEmpleados(eEmpleado listaEmpleados[],int lenEmpleados,int orden);

/**
 * @brief imprime el contenido del array de empleados
 *
 * @param listaEmpleados[] eEmpleado
 * @param lenEmpleados int
 * @return int
 */
int imprimirEmpleados(eEmpleado listaEmpleados[],int lenEmpleados);

/**
 * @brief inprime un empleado
 *
 * @param miEmpleado eEmpleado
 * @return void
 */
void imprimirEmpleado(eEmpleado miEmpleado);

/**
 * @brief recive la posicion a modificar y vuelve a escribir sus datos
 *
 * @param listaEmpleados[] eEmpleados
 * @param lenEmpleados int
 * @return int
 */
int modificarEmpleado(eEmpleado listaEmpleados[],int posicion);

/**
 * @brief calcula e imprime el total, promedio y cuantos empleados superan el salario promedio
 *
 * @param listaEmpleados[] eEmpleado
 * @param lenEmpleados int
 */
void calcularSalario(eEmpleado listaEmpleados[],int lenEmpleados);

/**
 * @brief busca un empleado en en array listaEmpleados
 *
 * @param listaEmpleados[] eEmpleado
 * @param lenEmpleados int
 * @return int retorna (-1) if error [longitud invalida o puntero null] - (0) if ok
 */
int chequearEmpleados(eEmpleado listaEmpleados[],int lenEmpleados);
#endif /* ARRAYEMPLOYEES_H_ */
