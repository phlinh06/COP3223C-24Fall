/*
Final Project

Suraj Basdeo
Linh Phan
Samantha Toole
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MaxStudents 100
#define MaxStaff 30

//Structure to store student info
typedef struct {
    char name[50];
    char id[10];
    float gpa;
    int credits;
} Student;

//Structure to store staff info
typedef struct {
    char name[50];
    char id[10];
    char department[10];
    char rank[10];
} Staff;

//Arrays to store data
Student students[MaxStudents];
Staff staff[MaxStaff];
int studentCount = 0;
int staffCount = 0;

void addStaff();
void addStudent();
void printInvoice();
void printStaff();
int menu();
void report();
void UpperCase(char * str);
int checkID(char * id);
int validateDepartment (char *department);
int validateRank (char *rank);
int attemptInputStr (int (*validation)(char *), char *input, const char *prompt, int maxAttempts);
int attemptInputInt (int(*validation)(int), int *input, const char *prompt, int maxAttempts);
int attemptInputFloat (int (*validation)(float), float *input, const char *prompt, int maxAttempts);
int attemptInputRank (char *rank, const char *prompt, int maxAttempts);
int validMenu (int option);
int validCredits (int credits);
int validGPA (float gpa);
void sortStaffName();
void sortStaffDepartment();
void sortStaffRank();
void sortStudentName();
void sortStudentGPA();
void sortMenu();
int attemptInputChar (const char *prompt, char *input, const char *validChoice, int maxAttempts);

//Dsiplays menu and takes users input
int main()
{
    int option;
    do
    {
        option = menu();
        switch(option)
        {
            case 1:
                addStaff();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                printInvoice();
                break;
            case 4:
                printStaff();
                break;
            case 5:
                report();
                break;
            default:
                printf("\nInvalid choice - please try again.\n\n");
        }
    } while (option != 5);

    return 0;
}

//Checks for valid input for menu
int validMenu(int option)
{
    return option >= 1 && option <= 5;
}

//Displays menu and validates input
int menu()
{
    int option;
    int attempts = 0;

    while (attempts < 3)
    {
        printf("Choose one of the options:\n\n");
        printf("1- Add a new faculty member\n");
        printf("2- Add a new student\n");
        printf("3- Print tuition invoice for a student\n");
        printf("4- Print information of a faculty\n");
        printf("5- Exit Program\n\n");
        printf("Enter your selection: ");

        if (scanf(" %d", &option) == 1 && validMenu(option))
        {
            return option;
        }
        else
        {
            printf("\n\nIvalid input. Try again.\n\n");
            attempts++;
            while (getchar() != '\n');
        }
    }

    //terminates after three invalid inputs
    printf("\n\tYou have tried too many times...\n\n\tThank you for using PerPro. Goodbye!\n");
    exit(0);
}

//Makes string uppercase
void UpperCase(char * str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

//checks for valid format of ID
int checkID(char * id)
{
    if (strlen(id) != 8) return 0;
    return isalpha(id[0]) && isalpha(id[1]) &&
           isdigit(id[2]) && isdigit(id[3]) &&
           isdigit(id[4]) && isdigit(id[5]) &&
           isdigit(id[6]) && isdigit(id[7]);
}

//checks for valid string input
int validateDepartment(char *department)
{
    UpperCase(department);
    return (strcmp(department, "MATH") == 0 ||
            strcmp(department, "CS") == 0 ||
            strcmp(department, "SCIENCE") == 0);
}

int validateRank (char *rank)
{
    UpperCase(rank);
    return (strcmp(rank, "PROFESSOR") == 0 ||
            strcmp(rank, "ADJUNCT") == 0);
}


//checks for valid int input
int validCredits(int credits)
{
    return credits >= 0;
}

int validGPA(float gpa)
{
    return gpa >= 0.0 && gpa <= 4.0;
}

//checks for valid input and allows for three tries if invalid
int attemptInputStr (int(*valdation)(char *), char *input, const char *prompt, int maxAttempts)
{
    int attempts = 0;
    while (attempts < maxAttempts)
    {
        printf("%s", prompt);
        scanf(" %s", input);
        if (valdation(input))
        {
            return 1;
        }
        else
        {
            printf("Invalid input. Try again.\n\n");
        }
        attempts++;
    }
    printf("\n\tYou have tried too many times...\n\n\tThank you for using PerPro. Goodbye!\n");
    exit(0);
}

int attemptInputInt (int(*valdation)(int), int *input, const char *prompt, int maxAttempts)
{
    int attempts = 0;
    while (attempts < maxAttempts)
    {
        printf("%s", prompt);
        if (scanf(" %d", input) == 1 && valdation(*input))
        {
            return 1;
        }
        else
        {
            printf("Invalid input. Try again.\n\n");
        }
        attempts++;
    }
    printf("\n\tYou have tried too many times...\n\n\tThank you for using PerPro. Goodbye!\n");
    exit(0);
}

int attemptInputFloat (int (*validation)(float), float *input, const char *prompt, int maxAttempts)
{
    int attempts = 0;
    while (attempts < maxAttempts)
    {
        printf("%s", prompt);
        if (scanf(" %f", input) == 1 && validation(*input))
        {
            return 1;
        }
        else
        {
            printf("Invalid input. Try again.\n\n");
        }
        attempts++;
    }
    printf("\n\tYou have tried too many times...\n\n\tThank you for using PerPro. Goodbye!\n");
    exit(0);
}

int attemptInputRank (char *rank, const char *prompt, int maxAttempts)
{
    int attempts = 0;
    while (attempts < maxAttempts)
    {
        printf("%s", prompt);
        scanf(" %[^\n]%*c", rank);
        UpperCase(rank);

        if (strcmp(rank, "PROFESSOR") == 0 || strcmp(rank, "ADJUNCT") == 0)
        {
            return 1;
        }
        else
        {
            printf("\n\tSorry entered rank (%s) is invalid. Try again.\n", rank);
            attempts++;
        }
    }
    printf("\n\tYou have tried too many times...\n\n\tThank you for using PerPro. Goodbye!\n");
    exit(0);
}

//Adds new data to staff structure 
void addStaff()
{
    //Checks to see if limit is reached
    if (staffCount >= MaxStaff)
    {
        printf("Sorry, max staff reached.\n");
        return;
    }

    Staff newStaff;

    //adds name to structure
    printf("\nEnter the faculty's info:\n");
    printf("\tName of the faculty: ");
    scanf(" %[^\n]%*c", newStaff.name);
    UpperCase(newStaff.name);

    //Validates and gives three attempts at inputs
    attemptInputStr(checkID, newStaff.id, "\tID: ", 3);
    attemptInputRank(newStaff.rank,"\tRank: ", 3);
    attemptInputStr(validateDepartment, newStaff.department, "\tDepartment: ", 3);

    staff[staffCount++] = newStaff;
    printf("\nThanks!\n\n");
}

//Adds new data to student structure 
void addStudent()
{
    //Checks to see if limit is reached
    if (studentCount >= MaxStudents)
    {
        printf("Sorry, max student count reached.\n");
        return;
    }

    Student newStudent;
    //adds name to structure
    printf("\nEnter the student's info:\n\n");
    printf("\tName of the Student: ");
    scanf(" %[^\n]%*c", newStudent.name);
    UpperCase(newStudent.name);

    //Validates and gives three attempts at inputs
    attemptInputStr(checkID, newStudent.id, "\tID: ", 3);
    attemptInputFloat(validGPA,  &newStudent.gpa, "\tGPA: ", 3);
    attemptInputInt(validCredits, &newStudent.credits, "\tCredit hours: ", 3);

    students[studentCount++] = newStudent;
    printf("\nThanks!\n\n");
}

//displays invoice
void printInvoice()
{
    char studentID[10];
    int check = 0;
    const float creditFee = 236.45f;
    const float additionalFees = 52.0f;

    //gathers and validates input
    printf("Enter the student's id: ");
    scanf(" %s", studentID);

    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i].id, studentID) == 0)
        {
            //Calculates invoice and prints data
            check = 1;
            UpperCase(students[i].id);
            float tuition = students[i].credits * 236.45;
            float discount = (students[i].gpa >= 3.85) ? tuition * .25 : 0;
            float total = tuition + 52 - discount;

            printf("Here is the tuition invoice for %s :\n\n", students[i].name);
            printf("---------------------------------------------------------------------------\n");
            printf("%-20s %35s\n", students[i].name, students[i].id);
            printf("\nCredit Hours:%d ($%.2f/credit hour)\n", students[i].credits, creditFee);
            printf("Fees: $%.2f\n\n", additionalFees);
            printf("Total payment: $%.2f \t($%.2f discount applied)\n", total, discount);
            printf("---------------------------------------------------------------------------\n");
            break;
        }
    }

    //Display error if invalid input is given
    if (!check)
    {
        printf("Sorry-student not found!\n");
    }
}

//displays data for staff
void printStaff()
{
    char staffID[10];
    int found = 0;

    printf("Enter the faculty's id: ");
    scanf(" %s", staffID);

    UpperCase(staffID);

    for (int i = 0; i < staffCount; i++)
    {
        char tempID[10];
        strcpy(tempID, staff[i].id);

        UpperCase(tempID);

        if (strcmp(tempID, staffID) == 0)
        {
            found = 1;
            printf("Faculty found:\n");
            printf("---------------------------------------------------------------------------\n");
            printf("\t%s\n\t%s department, %s\n", staff[i].name, staff[i].department, staff[i].rank);
            printf("---------------------------------------------------------------------------\n");
            break;
        }
    }

    if (!found)
    {
        printf("Sorry %s doesn't exist\n", staffID);
    }
}

//Sorts input  
void sortStaffName()
{
    for (int i = 0; i < staffCount - 1; i++)
    {
        for (int j = i + 1; j < staffCount; j++)
        {
            if (strcmp(staff[i].name, staff[j].name) > 0)
            {
                Staff temp = staff[i];
                staff[i]= staff[j];
                staff[j] = temp;
            }
        }
    }
}

void sortStaffDepartment()
{
    for (int i = 0; i < staffCount - 1; i++)
    {
        for (int j = i + 1; j < staffCount; j++)
        {
            if (strcmp(staff[i].department, staff[j].department) > 0)
            {
                Staff temp = staff[i];
                staff[i]= staff[j];
                staff[j] = temp;
            }
        }
    }
}

void sortStaffRank()
{
    for (int i = 0; i < staffCount - 1; i++)
    {
        for (int j = i + 1; j < staffCount; j++)
        {
            if (strcmp(staff[i].rank, staff[j].rank) > 0)
            {
                Staff temp = staff[i];
                staff[i]= staff[j];
                staff[j] = temp;
            }
        }
    }
}

void sortStudentName()
{
    for (int i = 0; i < studentCount - 1; i++)
    {
        for (int j = i + 1; j < studentCount; j++)
        {
            if (strcmp(students[i].name, students[j].name) > 0)
            {
                Student temp = students[i];
                students[i]= students[j];
                students[j] = temp;
            }
        }
    }
}

void sortStudentGPA()
{
    for (int i = 0; i < studentCount - 1; i++)
    {
        for (int j = i + 1; j < studentCount; j++)
        {
            if (students[i].gpa < students[j].gpa)
            {
                Student temp = students[i];
                students[i]= students[j];
                students[j] = temp;
            }
        }
    }
}

//Validates input and gives three attempts 
int attemptInputChar (const char *prompt, char *input, const char *validChoice, int maxAttempts)
{
    int attempts = 0;

    while (attempts < maxAttempts)
    {
        printf("%s", prompt);
        scanf(" %c", input);

        for (int i = 0; validChoice[i] != '\0'; i++)
        {
            if (*input == validChoice[i])
            {
                return 1;
            }
        }

        printf("Invalid input. Try again.\n\n");
        attempts++;
    }

    return 0;

}

//Prints report
void report()
{
    char staffSortChoice, studentSortChoice;

    printf("Would you like to print the final report (Y/N): ");
    char choice;
    scanf(" %c", &choice);

    if (toupper(choice) == 'Y')
    {
        //Takes input and directs to other functions
        if (attemptInputChar("\n\nEnter\n\tN or n to sort the faculty by name\n\tD or d to sort the faculty by department\n\tR or r to sort the faculty by rank\nMake your sort selection: ", &staffSortChoice, "NnDdRr", 3))
        {
            switch (toupper(staffSortChoice))
            {
                case 'N':
                    sortStaffName();
                    break;
                case 'D':
                    sortStaffDepartment();
                    break;
                case 'R':
                    sortStaffRank();
                    break;
            }
        }

        else
        {
            printf("\n\tYou have tried too many times...\n\n\tThank you for using PerPro. Goodbye!\n");
            exit(0);
        }

        if (attemptInputChar("\n\nEnter\n\tN or n to sort the students by name\n\tG or G to sort the students by gpa\nMake your sort selection: ", &studentSortChoice, "NnGg", 3))
        {
            switch (toupper(studentSortChoice))
            {
                case 'N':
                    sortStudentName();
                    break;
                case 'G':
                    sortStudentGPA();
                    break;
            }
        }
        else
        {
            printf("\n\tYou have tried too many times...\n\n\tTha2nk you for using PerPro. Goodbye!\n");
            exit(0);
        }

        //Prints data with corrected sorting
        printf("Here is your report....\n");
        printf("\t------ L I S T  O F  F A C U L T Y -----\n");
        for (int i = 0; i < staffCount; i++)
        {
            printf("\t\t%s - %s\n", staff[i].name, staff[i].department);
        }

        printf("\n\t------ L I S T  O F  S T U D E N T S -----\n");
        for (int i = 0; i < studentCount; i++)
        {
            printf("\t\t%s (GPA = %.2f)\n", students[i].name, students[i].gpa);
        }

        printf("\n\nThank you for using PerPro. Goodbye!");

    }
    else
    {
        printf("\n\nThank you for using PerPro. Goodbye!");
    }
}
