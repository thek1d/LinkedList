/*
 * Node.h
 *
 *  Created on: Sep 30, 2020
 *      Author: thek1d
 */

#ifndef NODE_H_
#define NODE_H_

typedef struct Node
{
	struct Node *pNext, *pPrevious;
		   int	 value;
}Node_t;

typedef struct List
{
	Node_t 	 *pHead;
	size_t   size;
}List_t;

/* Function prototypes */
Node_t* createNode  		  (int val);
void 	addNewNodeSortedToList(List_t *pList, int data);
void  	insertFront 		  (List_t *pList, int value);
void	printList			  (List_t *pList);
void	insertSorted		  (List_t *pList, Node_t *pNewNode);
void	deleteList			  (List_t *pList);


#endif /* NODE_H_ */
