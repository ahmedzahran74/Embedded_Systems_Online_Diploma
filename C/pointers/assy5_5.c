/*
 * assy5_5.c
 *
 *  Created on: Jul 13, 2022
 *      Author: AM
 */
#include "stdio.h"
#include"string.h"
typedef struct {
	char*name;
	int ID;
}data;
int main ()
{
	char str[50];
	data employees[3]={{.name="Ahmed",.ID=1000},{.ID=10001,.name="Ziad"},{.ID=1002,.name="Tarek"}};

	data *p[3]={&employees[0],&employees[1],&employees[2]};
	data *(*ptr)[3]=&p;
	printf("Enter the name of the employee :\n");
	fflush(stdin);fflush(stdout);
	scanf("%s",str);
	int flag=0;
	for (int i=0;i<3;i++)
	{
		if(!strcmp(str,((*ptr)[i])->name))
		{
			printf("Employee ID is : ");
			fflush(stdin);fflush(stdout);
			printf("%d",((*ptr)[i])->ID);
			fflush(stdin);fflush(stdout);
			flag=1;
			break;
		}
	}
	if (!flag)
	{
		printf("The name is not exist\n");
		fflush(stdin);fflush(stdout);
	}
}
