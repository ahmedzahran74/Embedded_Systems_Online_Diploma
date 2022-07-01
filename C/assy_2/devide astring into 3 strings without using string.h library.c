/*
 * test2.c
 *
 *  Created on: Jul 1, 2022
 *      Author: AM
 */


#include <stdio.h>
#include <string.h>
#define N 100
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
int getting_string_length(char *str)
{
	int number=0;
	for (int i=0;str[i]!=0;i++)
	{
		number ++;
	}
	return number;
}
int main()
{
	char s_1[N],s_2[N],s_3[N],s_4[N];
	printf("enter a string");
	fflush(stdin);fflush(stdout);
	getting_string(s_1,N);
	int length=getting_string_length(s_1);
	int i=0;
	while(i<length)
	{
		if(s_1[i]==',')
			break;
		i++;
	}
	for(int m=0;m<i;m++)
	{
		s_2[m]=s_1[m];
	}
	s_2[i]=0;
	int j=i+1;
	while(j<length)
	{
		if(s_1[j]==',')
			break;
		j++;
	}
	for(int m=i+1;m<j;m++)
	{
		s_3[m-(i+1)]=s_1[m];
	}
	s_3[j-i-1]=0;

	for(int m=j+1;m<length;m++)
	{
		s_4[m-j-1]=s_1[m];
	}
	s_4[length-j-1]=0;
	printf("%s\n",s_2);
	fflush(stdin);fflush(stdout);
	printf("%s\n",s_3);
	fflush(stdin);fflush(stdout);
	printf("%s\n",s_4);
	fflush(stdin);fflush(stdout);


	return 0;
}
