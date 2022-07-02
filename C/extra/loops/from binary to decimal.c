/*
 * from binary to decimal.c
 *
 *  Created on: Jul 2, 2022
 *      Author: AM
 */

#include"stdio.h"
int power(int x,int y)
{
	int result=1;
	for (int i=1;i<=y;i++)
	{
		result*=x;
	}
	return result;
}
int from_binary_to_decimal(int number)
{
	int result=0,rem,count=0;;
	while(number!=0)
	{
		rem=number%10;
		number/=10;
		result+=rem*power(2,count);
		count++;
	}
	return result;
}
int main()
{
	printf("%d",from_binary_to_decimal(1001101));
}
