#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct employee {
	int id;
	char name[50];
	float salary;
	int numberOfDependents;
	struct employee * next;
	struct employee * below;
};

int getId ( char * name);

void printEmployee ( struct employee );

void printAllEmployees ( struct employee * list);

struct employee * addEmployee ( struct employee * list, struct employee e);

int searchEmployee ( struct employee * list, char * name);

float highestNetSalary ( struct employee * list);

int main() {
	struct employee * company = NULL, tempEmployee;
	int tempInt = 0;
	char tempName [50] = "Allal Kamch" ;
	char dummy;

	printf ("Enter 1 to add a new employee, 0 to stop: ");
	scanf ("%d", &tempInt);

	while ( tempInt == 1 ) {
		printf("Enter Full Name: ");
		scanf("%c",&dummy);
		fgets(tempEmployee.name, 50, stdin);
		tempEmployee.id = getId (tempEmployee.name);

		printf ("Enter salary-numberOfDependents: ");
		scanf ("%f-%d", &tempEmployee.salary, &tempEmployee.numberOfDependents);

		company = addEmployee ( company, tempEmployee );
		printf ("Enter 1 to add a new employee, 0 to stop: ");
		scanf ("%d", &tempInt);
	}

	printAllEmployees ( company ) ;

	printf ("Highest Net Salary = %.2f\n", highestNetSalary(company) );

	tempInt = searchEmployee ( company, tempName) ;

	if ( tempInt == 1 )
		printf ("%s is found!\n", tempName);
	else
		printf ("%s is NOT found!\n", tempName);
	return 0;
}

int getId ( char * name ) {
	int id = 0;

	while (*name != '\n') {
		int temp = toupper(*name);
		temp = (int) temp;
		id = id + temp;
		name++;
	}
	if(*name=='\n')
		*name='\0';
	return id;
}

void printEmployee ( struct employee employee) {
	/*
	prints an employee in the format [id,name,net salary], where:
	Net salary = salary*0.91 + (numberOfDependent *0.01*salary)
	Examples: [562,AaBc xYz,1253.56] [562,bAac ZyX,6253.06]
	*/

	float netSalary = 0;
	netSalary = (employee.salary*.91) + (employee.numberOfDependents*.01*employee.salary);

	printf("[%d, %s, %.2f]\n", employee.id, employee.name, netSalary);
}

void printAllEmployees ( struct employee * list) {
	while (list != NULL) {
		printEmployee(*list);
		struct employee *ptr = list->below;
		while (ptr != NULL) {
			printEmployee(*ptr);
			ptr = ptr -> below;
		}
		list = list -> next;
	}
}

struct employee * addEmployee ( struct employee * list, struct employee e) {
	struct employee* newEmployee = (struct employee*)malloc(sizeof(struct employee));
	strcpy(newEmployee->name, e.name);
	newEmployee->id = e.id;
	newEmployee->salary = e.salary;
	newEmployee->numberOfDependents = e.numberOfDependents;
	newEmployee->next = NULL;
	newEmployee->below = NULL;

	struct employee* ptr = list;

	while (ptr != NULL) {
		if (e.id == ptr->id) {
			newEmployee->below = ptr->below;
			ptr->below = newEmployee;
			return list;
		}
		else {
			ptr++;
		}
	}
	if (list == NULL) {
		list = newEmployee;
	} else {
		struct employee* ptr = list;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newEmployee;
	}
	return list;
}

int searchEmployee ( struct employee * list, char * name) {
	struct employee* ptr = list;
	while (list != NULL) {
		if (strcmp(list -> name, name) == 0) {
			return 1;
		}
		struct employee *ptr = list -> below;
		while (ptr != NULL) {
			if (strcmp(ptr -> name, name) == 0) {
				return 1;
			}
			ptr = ptr -> below;
		}
		list = list -> next;
	}
	return 0;
}

float highestNetSalary ( struct employee * list) {
	float highestSalary = list->salary;
	struct employee* current = list->next;
	while (current != NULL) {
		if (current->salary > highestSalary) {
			highestSalary = current->salary; // Update highest salary if a
			higher one is found
		}
		current = current->next; // Move to the next employee
	}
	return highestSalary;
}