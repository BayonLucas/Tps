/*
 * Parser.h
 *
 *  Created on: 4 jun. 2021
 *      Author: lucas
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
