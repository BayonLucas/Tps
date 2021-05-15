/*
 * ArrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: lucas
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct {
 int id;
 char name[15];
 char lastName[15];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;


/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len);

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \param posicion int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee list[], int len, int* id, char name[], char lastName[], float salary, int sector, int posicion);

/*
 *
 */
int altaEmployee(Employee list[], int len, int* IncresCount);

/** \brief find an Employee by Id en returns the index position in array.
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee list[], int len);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order);

/** \brief print the content of employees array
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee list[], int length);

/*
 *
 */
void printEmployee(Employee list[], int i);

/*
 *
 */
int searchFreeEmployee(Employee list[], int len);

/*
 *
 */
void findSectorById(char* tipoR, Employee list[],int posicion);

/*
 *
 */
int modifyData(Employee list[],int len);

/*
 *
 */
void hardcodearEmployee(Employee list[], int len, int* firstAdd);

/*
 *
 */
int sortEmployeeAlphabetic(Employee list[],int len);
#endif /* ARRAYEMPLOYEES_H_ */
