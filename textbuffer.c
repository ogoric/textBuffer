#include <stdlib.h>
#include <stdio.h>
#include "textbuffer.h"
#include string.h

//helper function prototypes:
static tbNode *newtbNode(char *it);
static void append(TB tb, char *val);
static TB emptyTb(void);
static void putTB(FILE *out, TB bfr);

//static helper functions:----------------------------------------------------
//textbuffer struct------------------------------------
typedef struct TB{
	int  nitems;   // count of items in list
	tbNode *first; // first node in list
	tbNode *last; 
}TB;

//textbuffer Node struct-------------------------------
typedef struct tbNode { 
	char   *value;
	struct tbNode *next;
	struct tbNode *prev;
} tbNode;

//puts list onto stdout---------------------------------
static void putTB(FILE *out, TB bfr)
{
	assert(out != NULL); assert(bfr != NULL);
	tbNode *curr;
	for (curr = bfr->first; curr != NULL; curr = curr->next)
		fprintf(out,"%s\n",curr->value);
}

//creates a new node with info.-------------------------
static tbNode *newtbNode(char *it){
	
	tbNode *new;
	new = malloc(sizeof(tbNode));
	assert(new != NULL);
	new->value = strdup(it);
	new->prev = new->next = NULL;
	return new;
}
	
//append to end of tb-----------------------------------
static void append(TB tb, char *val){
	
	assert(tb != NULL);
	tbNode *new = newtbNode(val);
	
	if(tb->first == NULL && tb->last == NULL){
		//empty tb
		tb->first = new;
		tb->last = new;
		tb->nitems++;
	} else {
		//regular case
		new->prev = tb->last;
		tb->last->next = new;
		tb->last = new;.
		tb->nitems++;
	}
}

//create empty TB---------------------------------------
static TB emptyTB(void){

	struct TB *tb;

	tb = malloc(sizeof (struct TB));
	assert (tb != NULL);
	tb->nitems = 0;
	tb->first = NULL;
	tb->last = NULL;
	return tb;
}

/* Allocate a new textbuffer. contents initialised
 * in text array.
 */
 //actual function lmaooo-----------------------------------------------------
TB newTB (char text[]) {

	TB mytb = emptyTB();
	if(text == NULL) return mytb;
	
	//normal case
	//Will have issues with strtok!!! just FYI Carlos. debug
	const char delim[2] = "\n";
	char *token;
	token = strtok(text, delim);
	append(mytb, token);
	
	//loop to continuously append shiz.
	while(token != NULL){
		append(mytb, token);
		token = strtok(NULL, text);
	}
	static void putTB(FILE *out, TB bfr)
	putTB(stdout, mytb);//for testing.
	return tb;
}

/* Free the memory occupied by the given textbuffer.
 * It is an error to access the buffer afterwards.
 */
void releaseTB (TB tb) {

}

/* Allocate and return an array containing the text in the given textbuffer.
 * add a prefix corrosponding to line number iff showLineNumbers == TRUE
 */
char *dumpTB (TB tb, int showLineNumbers){
	return NULL;
}

/* Return the number of lines of the given textbuffer.
 */
int linesTB (TB tb){
	assert(tb != NULL);
	return tb->nitems;
}

/* Add a given prefix to all lines between pos1 and pos2
 *
 * - The program is to abort() with an error message if line 'pos1' or line
 *   'pos2' is out of range.  The first line of a textbuffer is at position 0.
 */
void addPrefixTB (TB tb, int pos1, int pos2, char* prefix){

}

/* Merge 'tb2' into 'tb1' at line 'pos'.
 *
 * - Afterwards line 0 of 'tb2' will be line 'pos' of 'tb1'.
 * - The old line 'pos' of 'tb1' will follow after the last line of 'tb2'.
 * - After this operation 'tb2' can not be used anymore (as if we had used
 *   releaseTB() on it).
 * - The program is to abort() with an error message if 'pos' is out of range.
 */
void mergeTB (TB tb1, int pos, TB tb2){

}

/* Copy 'tb2' into 'tb1' at line 'pos'.
 *
 * - Afterwards line 0 of 'tb2' will be line 'pos' of 'tb1'.
 * - The old line 'pos' of 'tb1' will follow after the last line of 'tb2'.
 * - After this operation 'tb2' is unmodified and remains usable independent
 *   of 'tb1'.
 * - The program is to abort() with an error message if 'pos' is out of range.
 */
void pasteTB (TB tb1, int pos, TB tb2) {

}

/* Cut the lines between and including 'from' and 'to' out of the textbuffer
 * 'tb'.
 *
 * - The result is a new textbuffer (much as one created with newTB()).
 * - The cut lines will be deleted from 'tb'.
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
TB cutTB (TB tb, int from, int to){
	return NULL;
}

/*  Return a linked list of Match nodes of all the matches of string search
 *  in tb
 *
 * - The textbuffer 'tb' will remain unmodified.
 * - The user is responsible of freeing the returned list
 */
Match searchTB (TB tb, char* search){
	return NULL;
}

/* Remove the lines between and including 'from' and 'to' from the textbuffer
 * 'tb'.
 *
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
void deleteTB (TB tb, int from, int to){

}


/* Search every line of tb for each occurrence of a set of specified subsitituions
 * and alter them accordingly
 *
 * refer to spec for table.
 */
void formRichText (TB tb){

}

/* Your whitebox tests
 */
void whiteBoxTests() {

}
