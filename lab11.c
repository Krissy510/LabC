#Q1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
struct Date
{
	int day;
	int month;
	int year;
};
struct Company
{
	char name[30];
	char code;
	int noOfEmployees;
	struct Date foundingDate;
};
struct Company getCompanyInfo() {
	struct Company newComp;
	printf("Enter company name: ");
	gets(newComp.name);
	do {
		printf("Enter company code (P/C/L): ");
		newComp.code = toupper(getchar());
		while (getchar() != '\n');
	} while (newComp.code != 'P' && newComp.code != 'C' && newComp.code != 'L');
	printf("Enter the number of employees: ");
	scanf("%d", &newComp.noOfEmployees);
	while (1)
	{
		printf("Enter founding date: ");
		scanf("%d/%d/%d", &newComp.foundingDate.day, &newComp.foundingDate.month, &newComp.foundingDate.year);
		if (newComp.foundingDate.day > 31 || newComp.foundingDate.day < 1)
			printf("Error: The day should be in the range 1..31.\n");
		if (newComp.foundingDate.month < 1 || newComp.foundingDate.month > 12)
			printf("Error: The month should be in the range 1..12.\n");
		if(1 <= newComp.foundingDate.day && newComp.foundingDate.day <= 31 && 1 <= newComp.foundingDate.month && newComp.foundingDate.month <= 12)
			break;
	}
	return newComp;
}
void printCompanyInfo(struct Company comp) {
	printf("Company name: %s\n", comp.name);
	printf("Type of company: ");
	switch (comp.code) {
	case 'P':
		printf("Public Company\n");
		break;
	case 'C':
		printf("Limited Company\n");
		break;
	case 'L':
		printf("Limited Partnership\n");
		break;
	default:
		printf("Unknown\n");
	}
	printf("Number of employees: %d\n", comp.noOfEmployees);
	printf("Founding date: %d/%d/%d",comp.foundingDate.day,comp.foundingDate.month, comp.foundingDate.year);
}
void main()
{
	struct Company comp;
	comp = getCompanyInfo();
	printCompanyInfo(comp);
}


#Q2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
struct Date
{
	int day;
	int month;
	int year;
};
struct Company
{
	char name[30];
	char code;
	int noOfEmployees;
	struct Date foundingDate;
};
struct Company getCompanyInfo() {
	struct Company newComp;
	printf("Enter company name: ");
	gets(newComp.name);
	do {
		printf("Enter company code (P/C/L): ");
		newComp.code = toupper(getchar());
		while (getchar() != '\n');
	} while (newComp.code != 'P' && newComp.code != 'C' && newComp.code != 'L');
	printf("Enter the number of employees: ");
	scanf("%d", &newComp.noOfEmployees);
	while (1)
	{
		printf("Enter founding date: ");
		scanf("%d/%d/%d", &newComp.foundingDate.day, &newComp.foundingDate.month, &newComp.foundingDate.year);
		if (newComp.foundingDate.day > 31 || newComp.foundingDate.day < 1)
			printf("Error: The day should be in the range 1..31.\n");
		if (newComp.foundingDate.month < 1 || newComp.foundingDate.month > 12)
			printf("Error: The month should be in the range 1..12.\n");
		if(1 <= newComp.foundingDate.day && newComp.foundingDate.day <= 31 && 1 <= newComp.foundingDate.month && newComp.foundingDate.month <= 12)
			break;
	}
	getchar();
	return newComp;
}
void printCompanyInfo(struct Company comp) {
	printf("Company name: %s\n", comp.name);
	printf("Type of company: ");
	switch (comp.code) {
	case 'P':
		printf("Public Company\n");
		break;
	case 'C':
		printf("Limited Company\n");
		break;
	case 'L':
		printf("Limited Partnership\n");
		break;
	default:
		printf("Unknown\n");
	}
	printf("Number of employees: %d\n", comp.noOfEmployees);
	printf("Founding date: %d/%d/%d\n",comp.foundingDate.day,comp.foundingDate.month, comp.foundingDate.year);
}

void main()
{
	
	struct Company comp[10];
	char choice,count = 0;
	while (1)
	{
		do{
		printf("Add a company, List companies, or Quit (A/L/Q): ");
		choice = toupper(getchar());
		while (getchar() != '\n' );
		} while (choice != 'A' && choice != 'L' && choice != 'Q');
		printf("Choice = %c\n", choice);
		if (choice == 'A')
		{
			comp[count] = getCompanyInfo();
			printf("\n");
			count++;
		}
		else if (choice == 'L')
		{
			char type_comp;
			do {
				printf("Enter company code (P/C/L): ");
				type_comp = toupper(getchar());
				while (getchar() != '\n');
			} while (type_comp != 'P' && type_comp != 'C' && type_comp != 'L');
			for (int i = 0; i <= count; i++) {
				if (type_comp == comp[i].code)
				{
					printCompanyInfo(comp[i]);
				}
			}
			printf("\n");
		}
		else if (choice == 'Q')
		{
			break;
		}
	}
}
