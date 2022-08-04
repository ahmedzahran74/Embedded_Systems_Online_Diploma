/*
 * linked_list.c
 *
 *  Created on: Aug 2, 2022
 *      Author: AM
 */
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<conio.h>
#include <stddef.h>
#include "linked_list.h"
SStudent_t*gpFirstStudent=NULL;
//
SStudent_t*temp;
//
void Add_Student(SStudent_t**P_Linked_List)
{
	SStudent_t*PLast_Student;
	SStudent_t*PNew_Student;
	if (*P_Linked_List==NULL)//check if the list is empty
	{
		PNew_Student=(SStudent_t*)malloc(sizeof(SStudent_t));
		PLast_Student=PNew_Student;
		*P_Linked_List=PLast_Student;
	}
	else//if list contain records
	{
		PLast_Student=*P_Linked_List;
		while(PLast_Student->PNextStudent!=NULL)//getting the last student in the list
			PLast_Student=PLast_Student->PNextStudent;
		PNew_Student=(SStudent_t*)malloc(sizeof(SStudent_t));
		PLast_Student->PNextStudent=PNew_Student;
		PLast_Student=PLast_Student->PNextStudent;

	}
	//fill the new record
	fill_the_record(PLast_Student);
}
void fill_the_record(SStudent_t*PNew_Student)
{
	uint8_t temp_text[40];
	//getting student ID
	DPRINTF("Enter student ID: ");
	gets(temp_text);
	PNew_Student->SData_Student.ID=atoi(temp_text);
	//getting student name
	DPRINTF("Enter student full name: ");
	gets(PNew_Student->SData_Student.name);
	//getting student height
	DPRINTF("Enter student height: ");
	gets(temp_text);
	PNew_Student->SData_Student.height=atof(temp_text);
	//set the next record to null
	PNew_Student->PNextStudent=NULL;

}
uint8_t Delet_Student(SStudent_t**P_List)
{
	if(*P_List==NULL)
	{
		DPRINTF("the list is empty\n");
		return 0;
	}
	else
	{
		uint8_t temp_text[40];
		uint32_t ID;
		SStudent_t*Selected_Student=*P_List;
		SStudent_t*Prev_Selected_Student=NULL;
		DPRINTF("enter the ID for the student you want to delete\n");
		gets(temp_text);
		ID=atoi(temp_text);

		//to check if the selected ID of the first student

		if(Selected_Student->SData_Student.ID==ID)
		{
			*P_List=(*P_List)->PNextStudent;
			free(Selected_Student);
			DPRINTF("Delete is done\n");
			return 1;
		}
		else//if the student doesn't exist in the first node
		{
			Prev_Selected_Student=Selected_Student;
			Selected_Student=Selected_Student->PNextStudent;
			while(Selected_Student)
			{
				if(Selected_Student->SData_Student.ID==ID)
				{
					//check if the student is the last student
					Prev_Selected_Student->PNextStudent=Selected_Student->PNextStudent;
					free(Selected_Student);
					DPRINTF("Delete is done\n");
					return 1;
				}
				Prev_Selected_Student=Selected_Student;
				Selected_Student=Selected_Student->PNextStudent;

			}
			DPRINTF("the ID is not exist");
			return 0;

		}

	}
}

void View_Students(SStudent_t*P_Student_node)
{
	uint32_t count=0;
	if (P_Student_node==NULL)
	{
		DPRINTF("The list is empty\n");
	}
	else
	{
		while(P_Student_node)
		{
			count++;
			DPRINTF("The record number %d:\n",count);
			DPRINTF("The Student ID is %d\n",P_Student_node->SData_Student.ID);
			DPRINTF("The Student name is %s\n",P_Student_node->SData_Student.name);
			DPRINTF("The Student height is %.2f \n",P_Student_node->SData_Student.height);
			P_Student_node=(P_Student_node->PNextStudent);
		}
	}
}
void view_student(SStudent_t*P_Node)
{
	DPRINTF("The Student ID is %d\n",P_Node->SData_Student.ID);
	DPRINTF("The Student name is %s\n",P_Node->SData_Student.name);
	DPRINTF("The Student height is %.2f \n",P_Node->SData_Student.height);
}
void Delett_All(SStudent_t**P_Student_node)
{
	if(*P_Student_node==NULL)
	{
		DPRINTF("The List is empty");
	}
	else
	{
		SStudent_t*P_Deleted_node=*P_Student_node;//pointer to the node to be deleted
		SStudent_t*P_N_Deleted_node=*P_Student_node;//pointer to the next node to be deleted
		uint32_t count=0;
		while(P_Deleted_node)
		{
			P_N_Deleted_node=P_N_Deleted_node->PNextStudent;
			count++;
			free(P_Deleted_node);
			DPRINTF("The Record number %d is deleted \n",count);
			P_Deleted_node=P_N_Deleted_node;

		}
		gpFirstStudent=NULL;
	}
}
uint8_t GetNth_List(SStudent_t*P_List)
{
	SStudent_t* P_Temp=P_List;
	if(P_Temp!=NULL)
	{
		uint32_t number;
		char temp_text[40];
		DPRINTF("Enter the node number: ");
		gets(temp_text);
		number=atoi(temp_text);
		uint32_t count=0;
		while(count<number)
		{
			P_Temp=P_Temp->PNextStudent;
			count++;
			if (P_Temp==NULL)
			{
				DPRINTF("The node is not exist\n");
				return 0;
			}
		}
		temp=P_Temp;
		view_student(P_Temp);
		return 1;
	}
	else
	{
		DPRINTF("The list is empty");
		return 0;
	}
}
uint32_t Get_List_Number_Of_Nodes(SStudent_t*P_List)
{
	uint32_t count=0;
	SStudent_t*P_Temp=P_List;
	while(P_Temp!=NULL)
	{
		count++;
		P_Temp=P_Temp->PNextStudent;
	}
	DPRINTF("the number of nodes is %d",count);
	return count;
}
void Reverse_Linked_List(SStudent_t**P_List)
{
	//creating 3 pointers
	SStudent_t*P_Previous=*P_List;
	SStudent_t*P_Current=*P_List;
	SStudent_t*P_Next=*P_List;
	if(P_Current==NULL)
		return ;
	else
	{
		if(P_Current->PNextStudent==NULL)
		{
			return;
		}
		else
		{
			P_Current=P_Current->PNextStudent;
			P_Next=P_Next->PNextStudent->PNextStudent;
			P_Previous->PNextStudent=NULL;
			while(P_Current->PNextStudent)
			{
				P_Current->PNextStudent=P_Previous;
				P_Previous=P_Current;
				P_Current=P_Next;
				P_Next=P_Next->PNextStudent;
			}
			P_Current->PNextStudent=P_Previous;
			*P_List=P_Current;
		}
		DPRINTF("Reverse is done");
	}

}
void Find_Nth_Student_From_End(SStudent_t*P_List)
{
	uint8_t temp_text[10];
	uint8_t number;
	if(P_List==NULL)
	{
		DPRINTF("The List is empty");
	}
	else
	{
		DPRINTF("Enter the student's number form the End");
		gets(temp_text);
		number=atoi(temp_text);
		SStudent_t*P_Main=P_List;
		SStudent_t*P_Assist=P_List;

		uint32_t count=0;
		while(count<number)
		{

			P_Assist=P_Assist->PNextStudent;
			count++;
			if(P_Assist==NULL)
			{
				DPRINTF("The %d element from the last is not exist\n",number);
				return;
			}
		}
		while(P_Assist->PNextStudent)
		{
			P_Assist=P_Assist->PNextStudent;
			P_Main=P_Main->PNextStudent;
		}
		view_student(P_Main);


	}
}
void Find_Middle_Of_List(SStudent_t*P_List)
{
	SStudent_t*P_Fast=P_List;
	SStudent_t*P_Slow=P_List;
	if(P_List==NULL)
	{
		DPRINTF("The List is empty\n");
	}
	else
	{
		while(P_Fast!=NULL)//loop until the end of the list
		{
			P_Fast=P_Fast->PNextStudent;
			if(P_Fast!=NULL)//Even number of nodes
			{
				P_Fast=P_Fast->PNextStudent;
				P_Slow=P_Slow->PNextStudent;
			}

		}
		view_student(P_Slow);
	}
}
void Detect_Loop_In_The_List(SStudent_t*P_List)
{
	SStudent_t*P_Fast=P_List;
	SStudent_t*P_Slow=P_List;
	if(P_List==NULL)
	{
		DPRINTF("The List Is Empty");
	}
	else
	{
		while(P_Fast!=NULL)
		{
			P_Fast=P_Fast->PNextStudent;
			if(P_Fast!=NULL)
			{
				P_Fast=P_Fast->PNextStudent;
				P_Slow=P_Slow->PNextStudent;
				if(P_Fast==P_Slow)
				{
					DPRINTF("There is a loop in the list");
					return;
				}
			}
			else
			{
				DPRINTF("There is not a loop is the list");
				return;
			}
		}
		DPRINTF("There is not a loop is the list");
		return;
	}
}

