/*
 * Node.c
 *
 *  Created on: Sep 30, 2020
 *      Author: thek1d
 */

#include "main.h"

Node_t* createNode(int val)
{
	Node_t *newNode = (Node_t*) malloc(sizeof(Node_t));
	assert(newNode);
	newNode->value = val;
	return newNode;
}

void addNewNodeSortedToList(List_t *pList, int data)
{
	Node_t *pNode = createNode(data);
	insertSorted(pList, pNode);
}

/*
 *	This function is also done by  insertSorted( List_t, Node_t ) : void
 *	so commented out because of duplication
 *
void insertFront(List_t *pList, int value)
{
	Node_t *newNode = createNode(value);
	newNode->pNext = pList->pHead;
	pList->pHead = newNode;
	pList->size++;
}
*/

void printList(List_t *pList)
{
	Node_t *pCurrent = (Node_t *)malloc(sizeof(Node_t));
	assert(pCurrent);

	pCurrent = pList->pHead;
	while(pCurrent != NULL)
	{
		printf("%i -> ", pCurrent->value);
		pCurrent = pCurrent->pNext;
	}

	printf("NULL\n");
}

void insertSorted(List_t *pList, Node_t *pNewNode)
{
	assert(pNewNode);

	// adding node to empty list
	if(pList->size == 0)
		pList->pHead = pNewNode;

	else
	{
		// adding node at head of the list
		if(pNewNode->value < pList->pHead->value)
		{
			pNewNode->pNext = pList->pHead;
			pList->pHead 	= pNewNode;
		}
		else
		{
			// adding node somewhere in list
			Node_t *pCurrent = pList->pHead;
			Node_t *pPrevious = NULL;

			// finding position
			while(pCurrent != NULL)
			{
				if(pCurrent->value >= pNewNode->value)
					break;

				else
				{
					pPrevious = pCurrent;
					pCurrent  = pCurrent->pNext;
				}
			}

			if(pCurrent != pList->pHead)
			{
				pNewNode->pNext  = pCurrent;
				pPrevious->pNext = pNewNode;
			}
		}
	}
	pList->size++;
}

void deleteList	(List_t *pList)
{
	Node_t *pCurrent, *pNext;

	pCurrent  = pList->pHead;
	pNext = NULL;

	while(pCurrent != NULL)
	{
		pNext  = pCurrent->pNext;
		printf("deleted Node with value: %d\n", pCurrent->value);
		free(pCurrent);
		pCurrent = pNext;
	}

	pList->pHead = NULL;
}
