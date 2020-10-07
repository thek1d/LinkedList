/*
 * main.c
 *
 *  Created on: Sep 30, 2020
 *      Author: thek1d
 */

// ToDo implement double linked list, with generic value type for nodes!

#include "main.h"

int main(int argc, char* argv[])
{
	List_t *pList = &((List_t){.size = 0, .pHead = NULL});

	addNewNodeSortedToList(pList, 3);
	printList(pList);
	addNewNodeSortedToList(pList, 1);
	printList(pList);
	addNewNodeSortedToList(pList, 2);
	printList(pList);
	addNewNodeSortedToList(pList, 5);
	printList(pList);
	addNewNodeSortedToList(pList, 4);
	printList(pList);
	addNewNodeSortedToList(pList, -1);
	printList(pList);

	printf("Size of List: %d\n\n", (int)pList->size);

	deleteList(pList);
	printList(pList);

	return 0;
}
