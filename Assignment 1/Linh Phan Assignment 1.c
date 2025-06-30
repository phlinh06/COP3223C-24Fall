//unit1.hw
//Linh Phan

#include <stdio.h>
#include <math.h>

int main()
{
	int classNum1, classCredit1;
	int classNum2, classCredit2;
	int studentId;
	float gpa;
	float money = 120.25;

	printf("Enter Student's ID:");
	scanf("%d", &studentId);
	printf("\nEnter crn/credit hours for the first class:");
	scanf("%d/%d", &classNum1, &classCredit1);
	printf("Enter crn/credit hours for the second class:");
	scanf("%d/%d", &classNum2,&classCredit2);

	printf("\nEnter the GPA of the Student: ");
	scanf("%f", &gpa);
	if (gpa > 2.5) {
		float due1 = classCredit1*money;
		float due2 = classCredit2*money;
		printf("25%% Discount is applicable!\n\nThank you!\nHERE IS THE FEE INVOICE....");
		printf("\n\nSIMPLE COLLEGE\nORLANDO FL 10101\n***********************\n\nFee Invoice Prepared for:\n[Student: %d]", studentId);
		printf("\n\n1 Credit Hour = $120.25\n\nCRN\tCREDIT HOURS");
		printf("\n%d\t%d\t\t$%.2f", classNum1, classCredit1, due1);
		printf("\n%d\t%d\t\t$%.2f", classNum2, classCredit2, due2);
		printf("\nHealth & ID Fees:\t$35.00");
		float total = (due1 + due2) - (.25 * (due1 + due2)) + 35;
		printf("\n________________________________\n\t\tTotal Payments\t$%.2f", total);
	}
	else if (gpa <= 2.5) {
		float due1 = classCredit1*money;
		float due2 = classCredit2*money;
		printf("25%% Discount is NOT applicable.\n\nThank you!\nHERE IS THE FEE INVOICE...");
		printf("\n\nSIMPLE COLLEGE\nORLANDO FL 10101\n***********************\n\nFee Invoice Prepared for:\n[Student: %d]", studentId);
		printf("\n\n1 Credit Hour = $120.25\n\nCRN\tCREDIT HOURS");
		printf("\n%d\t%d\t\t$%.2f", classNum1, classCredit1, due1);
		printf("\n%d\t%d\t\t$%.2f", classNum2, classCredit2, due2);
		printf("\nHealth & ID Fees:\t$35.00");
		float total = due1 + due2 + 35;
		printf("\n________________________________\n\t\tTotal Payments\t$%.2f", total);
	}

	return 0;
}