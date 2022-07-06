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
}student;
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
void get_student_data(student*stu,int i)
{

	char first_name[14];
	char second_name[14];
	printf("Enter the first name of student %d: ",i);
	fflush(stdin);fflush(stdout);
	getting_string(first_name,10);
	printf("Enter the second name of student %d: ",i);
	fflush(stdin);fflush(stdout);
	getting_string(second_name,10);
	strcpy(stu->name,first_name);
	strcat(stu->name,"  ");
	strcat(stu->name,second_name);
	fflush(stdin);fflush(stdout);
	printf("Enter roll number of student %d: ",i);
	fflush(stdin);fflush(stdout);
	scanf("%d",&stu->roll);
	printf("Enter the marks of employee %d: ",i);
	fflush(stdin);fflush(stdout);
	scanf("%f",&stu->marks);
}
void get_students_data(student*emp,int n)
{
	for (int i=1;i<=n;i++)
	{
		get_student_data(emp+i-1,i);
	}
}
void print_student_data(student*stu,int i)
{
	printf("The name of employee %d is: %s\n",i,stu->name);
	fflush(stdin);fflush(stdout);
	printf("The roll number of employee %d is %d\n",i,stu->roll);
	fflush(stdin);fflush(stdout);
	printf("The marks of employee %d is %.2f\n",i,stu->marks);
	fflush(stdin);fflush(stdout);
}
void print_students_data(student*stu,int n)
{
	for (int i=1;i<=n;i++)
	{
		print_student_data(stu+i-1,i);
	}
}
int main()
{
	student stus[N];
	int index;
	get_students_data(stus,N);
	//print_employees_data(stu,N);
	printf("Enter the student number you want to know about: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&index);
	print_student_data(&stus[index-1],index);
}
