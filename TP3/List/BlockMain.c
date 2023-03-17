#include <stdlib.h>
#include <stdio.h>
#include "BlockList.h"

void PrintList(SList *list);

int main()
{
	SList *list;
	SCell *cell1, *cell2;

	list = CreateList();
	AddElementEnd(list, 1);
	AddElementEnd(list, 2);
	AddElementEnd(list, 3);
	AddElementEnd(list, 4);
	cell1 = AddElementEnd(list, 5);
	AddElementEnd(list, 6);
	AddElementEnd(list, 7);
	AddElementEnd(list, 8);
	cell2 = AddElementEnd(list, 9);

	PrintList(list);
	PrintBlockList(list);
	PrintRecycleList(list);
	DeleteCell(list, cell1);
	PrintList(list);
	PrintBlockList(list);
	PrintRecycleList(list);
	DeleteCell(list, cell2);
	PrintList(list);
	PrintBlockList(list);
	PrintRecycleList(list);

	printf("\n");

	// printf("Add 5, 3, 1\n");
	// AddElementEnd(list, 5);
	// cell = AddElementEnd(list, 3);
	// AddElementEnd(list, 1);
	// PrintList(list);
	// PrintBlockList(list);
	// printf("\n");

	// printf("Add 6, 8\n");
	// AddElementEnd(list, 6);
	// AddElementEnd(list, 8);
	// PrintList(list);
	// PrintBlockList(list);
	// printf("\n");

	// printf("Add 4\n");
	// AddElementAfter(list, cell, 4);
	// PrintList(list);
	// PrintBlockList(list);
	// printf("\n");

	// printf("Add 2\n");
	// AddElementAfter(list, GetFirstElement(list), 2);
	// PrintList(list);
	// printf("\n");

	// printf("Delete 3\n");
	// DeleteCell(list, cell);
	// PrintList(list);
	// printf("\n");

	// printf("Add 7\n");
	// AddElementAfter(list, GetPrevElement(GetLastElement(list)), 7);
	// PrintList(list);
	// printf("\n");

	// DeleteList(list);

	return 0;
}

void PrintList(SList *list)
{
	printf("List: ");
	if (list)
	{
		SCell *cell = GetFirstElement(list);
		while (cell != NULL)
		{
			printf("[%d] -> ", GetData(cell));
			cell = GetNextElement(cell);
		}
		printf("NULL\n");
	}
}
