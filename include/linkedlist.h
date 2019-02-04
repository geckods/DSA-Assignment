/*linkedlist.h*/
#include <../include/stack.h>


typedef struct list {
	int head;
	int size;
} LinkedList;

typedef int node_object;

//allocateObject is used to make writing to memory convenient
int allocateObject(int key,int prev,int next); //returns NIL if no space remained

/*LinkedList functions*/
LinkedList* createList();
int insertSorted(LinkedList* list,node_object obj); //let it return location of new insert if successful, NIL if unsuccessful
int deleteElement(LinkedList* list,node_object obj); //let it return location of freeing if successful, NIL if unsuccessful - either element not found or list is empty
int count(LinkedList* list);
void printList(LinkedList* list);
