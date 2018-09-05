//Useful code. Doubly Linked Lists.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "DLList.h"

// data structures representing DLList

typedef struct DLListNode {
	char   *value;  // value of this list item (string)
	struct DLListNode *prev;
	               // pointer previous node in list
	struct DLListNode *next;
	               // pointer to next node in list
} DLListNode;

typedef struct DLListRep {
	int  nitems;      // count of items in list
	DLListNode *first; // first node in list
	DLListNode *curr;  // current node in list
	DLListNode *last;  // last node in list
} DLListRep;

// create a new DLListNode (private function)
static DLListNode *newDLListNode(char *it)
{
	DLListNode *new;
	new = malloc(sizeof(DLListNode));
	assert(new != NULL);
	new->value = strdup(it);
	new->prev = new->next = NULL;
	return new;
}

// create a new empty DLList
DLList newDLList()
{
	struct DLListRep *L;

	L = malloc(sizeof (struct DLListRep));
	assert (L != NULL);
	L->nitems = 0;
	L->first = NULL;
	L->last = NULL;
	L->curr = NULL;
	return L;
}

// free up all space associated with list
void freeDLList(DLList L)
{
	assert(L != NULL);
	DLListNode *curr, *prev;
	curr = L->first;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev->value);
		free(prev);
	}
	free(L);
}

// display list to file, one item per line
// assumes that the file is open for writing
void putDLList(FILE *out, DLList L)
{
	assert(out != NULL); assert(L != NULL);
	DLListNode *curr;
	for (curr = L->first; curr != NULL; curr = curr->next)
		fprintf(out,"%s\n",curr->value);
}