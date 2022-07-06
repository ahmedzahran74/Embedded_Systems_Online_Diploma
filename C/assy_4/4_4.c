/*
 * 4_4.c
 *
 *  Created on: Jul 6, 2022
 *      Author: AM
 */
#include "stdio.h"
#include "string.h"
#define N 2
typedef struct{
	char name[30];
	int roll;
	float marks;
}employee;
void getting_string(char *str,int n)
{
	char ch;
	char flag=0;
	for (int i=0;i<n;i++)
	{
		if ((ch=getchar())!='\n')
			str[i]=ch;
		else
		{
			str[i]=0;
			break;
			flag=1;
		}
	}
	if (flag==0)
	str[n]='\0';

}
void get_employee_data(employee*emp,int i)
{

	char first_name[14];
	char second_name[14];
	printf("Enter the first name of employee %d: ",i);
	fflush(stdin);fflush(stdout);
	getting_string(first_name,10);
	printf("Enter the second name of employee %d: ",i);
	fflush(stdin);fflush(stdout);
	getting_string(second_name,10);
	strcpy(emp->name,first_name);
	strcat(emp->name,"  ");
	strcat(emp->name,second_name);
	fflush(stdin);fflush(stdout);
	printf("Enter roll number of employee %d: ",i);
	fflush(stdin);fflush(stdout);
	scanf("%d",&emp->roll);
	printf("Enter the marks of employee %d: ",i);
	fflush(stdin);fflush(stdout);
	scanf("%f",&emp->marks);
}
void get_employees_data(employee*emp,int n)
{
	for (int i=1;i<=n;i++)
	{
		get_employee_data(emp+i-1,i);
	}
}
void print_employee_data(employee*emp,int i)
{
	printf("The name of employee %d is: %s\n",i,emp->name);
	fflush(stdin);fflush(stdout);
	printf("The roll number of employee %d is %d\n",i,emp->roll);
	fflush(stdin);fflush(stdout);
	printf("The marks of employee %d is %f\n",i,emp->marks);
	fflush(stdin);fflush(stdout);
}
void print_employees_data(employee*emp,int n)
{
	for (int i=1;i<=n;i++)
	{
		print_employee_data(emp+i-1,i);
	}
}
int main()
{
	employee emps[N];
	int index;
	get_employees_data(emps,N);
	//print_employees_data(emps,N);
	printf("Enter the employee number you want to know about: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&index);
	print_employee_data(&emps[index-1],index);
}
