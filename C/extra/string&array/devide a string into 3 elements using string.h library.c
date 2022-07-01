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
		str[N]='\0';

}
int main()
{
	char s_1[N],s_2[N],s_3[N],s_4[N];
	char*p;
	printf("enter a string");
	fflush(stdin);fflush(stdout);
	getting_string(s_1,N);
	p=strtok(s_1, ",");
	int i=-1;
	do
	{
		i++;
		s_2[i]=p[i];
	}while(p[i]!=0);
	p=strtok(NULL, ",");
	int j=-1;
	do
	{
		j++;
		s_3[j]=p[j];
	}while(p[j]!=0);
	p=strtok(NULL, ",");
	int k=-1;
	do
	{
		k++;
		s_4[k]=p[k];
	}while(p[k]!=0);
	printf("%s\n",s_2);
	fflush(stdin);fflush(stdout);
	printf("%s\n",s_3);
	fflush(stdin);fflush(stdout);
	printf("%s\n",s_4);
	fflush(stdin);fflush(stdout);


	return 0;
}
