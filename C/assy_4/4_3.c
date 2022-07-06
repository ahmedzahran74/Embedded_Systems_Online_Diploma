/*
 * 4_3.c
 *
 *  Created on: Jul 6, 2022
 *      Author: AM
 */
#include"stdio.h"
#define N 2
typedef struct{
	float real;
	float imaj;
}complex;
void get_complx(complex*com,int i)
{
	printf("Enter the real part of number %d: ",i+1);
	fflush(stdin);fflush(stdout);
	scanf("%f",&((&com[i])->real));
	printf("Enter the imajinary part of %d: ",i+1);
	fflush(stdin);fflush(stdout);
	scanf("%f",&((&com[i])->imaj));
}
void get_multible_complex(complex*num,int n)
{
	for(int i=0;i<n;i++)
	{
		get_complx(num,i);
	}
}
void add_two_complex(complex*num_1,complex*sum)
{
	sum->real+=num_1->real;
	sum->imaj+=num_1->imaj;
}
void add_multible_complex(complex*num,complex*sum,int n)
{

	sum->real=0;
	sum->imaj=0;
	for (int i=0;i<n;i++)
	{
		add_two_complex(num+i,sum);

	}

}
void print_complex(complex*num)
{
	printf("%.2f +j %.2f feet",num->real,num->imaj);
	fflush(stdin);fflush(stdout);
}
int main()
{
	complex num[N];
	complex sum;
	sum.real=0;
	sum.imaj=0;
	get_multible_complex(num,N);
	add_multible_complex(num,&sum,N);
	printf("The total sum=");
	fflush(stdin);fflush(stdout);
	print_complex(&sum);
}
