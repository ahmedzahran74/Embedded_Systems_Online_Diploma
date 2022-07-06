/*
 * 4_1.c
 *
 *  Created on: Jul 5, 2022
 *      Author: AM
 */
#include "stdio.h"
#include "string.h"
#define N_STUDENTS 2
typedef struct{
	char name[20];
	int roll;
	float marks;
}student;
void get_student_information(student* s,int i)
{
	char first_name[10];
	char second_name[10];
	printf("Enter the first name of student %d: ",i);
	fflush(stdin);fflush(stdout);
	scanf("%s",first_name);
	printf("Enter the second name of student %d: ",i);
	fflush(stdin);fflush(stdout);
	scanf("%s",second_name);
	strcpy(s->name,first_name);
	strcat(s->name," ");
	strcat(s->name,second_name);
	printf("Enter the roll number of %s ",s->name);
	fflush(stdin);fflush(stdout);
	scanf("%d",&s->roll);
	printf("Enter the mark of %s ",s->name);
	fflush(stdin);fflush(stdout);
	scanf("%f",&s->marks);
}
void get_students_information(student *s,int n)
{
	for(int i=0;i<n;i++)
	{
		get_student_information(s+i,i+1);
	}
}
void print_student_information(student* s,int i)
{
	printf("the name of student %d is: %s\n",i,s->name);
	fflush(stdin);fflush(stdout);
	printf("the roll of %s  is: %d\n",s->name,s->roll);
	fflush(stdin);fflush(stdout);
	printf("the mark of student %s is: %f\n",s->name,s->marks);
	fflush(stdin);fflush(stdout);
}
void print_students_information(student*s,int n)
{
	for(int i=0;i<n;i++)
	{
		print_student_information(s+i,i+1);
	}
}
int main()
{
	student students[N_STUDENTS];
	get_students_information((student*)students,N_STUDENTS);
	print_students_information((student*)students,N_STUDENTS);

}
