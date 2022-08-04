/*
s * Linked_list_main.c
 *
 *  Created on: Aug 3, 2022
 *      Author: AM
 */

#include"linked_list.h"
#include<stdio.h>
#include<conio.h>
#define DPRINTF(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
extern SStudent_t*gpFirstStudent;
//
extern SStudent_t*temp;
//
void main()
{
	char temp_text[40];
	uint8_t option;
	uint8_t count=6;
	while(count)
	{
		DPRINTF("\n======================\n");
		DPRINTF("\t Choose one of the following options\n");
		DPRINTF("1: To Add Student\n");
		DPRINTF("2: To Delete Student\n");
		DPRINTF("3: To View Student\n");
		DPRINTF("4: To Delete all \n");
		DPRINTF("5: To Show Nth node \n");
		DPRINTF("6: To Get the number of nodes \n");
		DPRINTF("7: To reverse the list \n");
		DPRINTF("8: To View Student Nth form the End \n");
		DPRINTF("9: To Find the middle of the List \n");
		DPRINTF("10: To Detect the loop in the list \n");
		DPRINTF("Enter option number: ");
		count--;
		gets(temp_text);
		DPRINTF("\n =====================\n");
		option=atoi(temp_text);
		switch(option)
		{
		case 1:
			Add_Student(&gpFirstStudent);
			break;
		case 2:
			Delet_Student(&gpFirstStudent);
			break;
		case 3:
			View_Students(gpFirstStudent);
			break;
		case 4:
			Delett_All(&gpFirstStudent);
			break;
		case 5:
			GetNth_List(gpFirstStudent);
			break;
		case 6:
			Get_List_Number_Of_Nodes(gpFirstStudent);
			break;
		case 7:
			Reverse_Linked_List(&gpFirstStudent);
			break;
		case 8:
			Find_Nth_Student_From_End(gpFirstStudent);
			break;
		case 9:
			Find_Middle_Of_List(gpFirstStudent);
			break;
		case 10:
			Detect_Loop_In_The_List(gpFirstStudent);
			break;
		default :
			DPRINTF("Wrong option");
			break;
		}
	}


}
