#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

void employee_show(Employee* this);

void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_sortId(void* pElementA, void* pElementB);
int employee_sortName(void* pElementA, void* pElementB);
int employee_sortHoras(void* pElementA, void* pElementB);
int employee_sortSueldo(void* pElementA, void* pElementB);

void employee_IncresSalary(void* this);


#endif // employee_H_INCLUDED
