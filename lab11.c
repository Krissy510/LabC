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
