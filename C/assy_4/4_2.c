/*
 * 4_2.c
 *
 *  Created on: Jul 6, 2022
 *      Author: AM
 */


#include"stdio.h"
#define N 6
typedef struct{
	int feet;
	float inch;
}distance_feet;

void get_distance(distance_feet*dis,int i);
void get_multible_distance(distance_feet*dist,int n);
void add_two_distance(distance_feet*dis_1,distance_feet*sum);
void add_multible_distance(distance_feet*dis,distance_feet*sum,int n);
void print_dist(distance_feet*dist);
int main()
{
	distance_feet dist[N];
	distance_feet sum;
	sum.feet=0;
	sum.inch=0;
	get_multible_distance(dist,N);
	add_multible_distance(dist,&sum,N);
	printf("The sum of the distances= ");
	fflush(stdin);fflush(stdout);
	print_dist(&sum);
}
void get_distance(distance_feet*dis,int i)
{
	printf("Enter the feet distance for user %d: ",i+1);
	fflush(stdin);fflush(stdout);
	scanf("%d",&((&dis[i])->feet));
	printf("Enter the inch distance for user %d: ",i+1);
	fflush(stdin);fflush(stdout);
	scanf("%f",&((&dis[i])->inch));
}

void get_multible_distance(distance_feet*dist,int n)
{
	for(int i=0;i<n;i++)
	{
		get_distance(dist,i);
	}
}
void add_two_distance(distance_feet*dis_1,distance_feet*sum)
{
	sum->feet+=dis_1->feet;
	sum->inch+=dis_1->inch;
	if(sum->inch>=12)
	{
		sum->feet+=1;
		sum->inch-=12;
	}
}
void add_multible_distance(distance_feet*dis,distance_feet*sum,int n)
{

	sum->feet=0;
	sum->inch=0;
	for (int i=0;i<n;i++)
	{
		add_two_distance(dis+i,sum);

	}

}
void print_dist(distance_feet*dist)
{
	printf("%d inch %f feet",dist->feet,dist->inch);
	fflush(stdin);fflush(stdout);
}
