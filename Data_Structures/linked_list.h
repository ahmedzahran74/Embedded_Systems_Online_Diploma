	/*
	 * linked_list.h
	 *
	 *  Created on: Aug 2, 2022
	 *      Author: AM
	 */

	#ifndef LINKED_LIST_H_
	#define LINKED_LIST_H_
	#include <stdint.h>
	#include <stddef.h>
	#include <stdlib.h>
	#define DPRINTF(...) {fflush(stdout);\
						  fflush(stdin);\
						  printf(__VA_ARGS__);\
						  fflush(stdout);\
						  fflush(stdin);}
	struct Sdata{
		uint32_t ID;
		char name [40];
		float height;

	};
	typedef struct SStudent_t {
		struct Sdata SData_Student;
		struct SStudent_t *PNextStudent;
	}SStudent_t;
	void Add_Student(SStudent_t**P_Linked_List);//passing the global pointer to the first node of the linked list
	void View_Students(SStudent_t*P_Student_node);//passing pointer to the first node of the list
	void view_student(SStudent_t*P_Node);
	void fill_the_record(SStudent_t*PNew_Student);
	uint8_t Delet_Student(SStudent_t**P_List);
	void Delett_All(SStudent_t**P_Student_node);//passing a pointer to the first node of the list
	uint8_t GetNth_List(SStudent_t*P_List);
	uint32_t Get_List_Number_Of_Nodes(SStudent_t*P_List);
	void Reverse_Linked_List(SStudent_t**P_List);
	void Find_Nth_Student_From_End(SStudent_t*P_List);
	void Find_Middle_Of_List(SStudent_t*P_List);
	void Detect_Loop_In_The_List(SStudent_t*P_List);
	#endif /* LINKED_LIST_H_ */
