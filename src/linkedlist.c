#include "../include/linkedlist.h"

int allocateObject(int key,int prev,int next){
	int loc = freePop();
	if(loc==-1){
		return NIL;
	}

	memory[loc]=key;
	memory[loc+1]=next;
	memory[loc+2]=prev;
	return loc;
}


LinkedList* createList(){
	LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));	
	newList->head=NIL;
	newList->size=0;
	return newList;
}

int insertSorted(LinkedList* list,node_object obj){ 
	if(list->size==0){
		int newLoc = allocateObject(obj,NIL,NIL);
		if(newLoc==NIL) return NIL;
		list->head = newLoc;
		list->size++;
		return newLoc;
	}
	else{ //list is not empty

		int curr=list->head;
		int prev=NIL;
		while((curr!=NIL) && (memory[curr]>=obj)){
			prev=curr;
			curr=memory[curr+1];
		}

		//now, the new element needs to be inserted after prev, but before curr
		int newLoc = allocateObject(obj,prev,curr);
		if(newLoc==NIL) return NIL;

		if(prev!=NIL){
			memory[prev+1]=newLoc;
		}

		if(curr!=NIL){
			memory[curr+2]=newLoc;
		}

		if(prev==NIL){ //new first element, so the LinkedList head needs to be changed
			list->head = newLoc;
		}
		list->size++;
		return newLoc;
	}
}
		

int deleteElement(LinkedList* list,node_object obj){
	if(list->size==0) return NIL;
	int currLoc = list->head;

	while(currLoc!=NIL && memory[currLoc]!=obj){
		currLoc = memory[currLoc+1];
	}
	if(currLoc==NIL) return NIL;
	
	//delete the element at currLoc
	
	int prev = memory[currLoc+2];
	int next = memory[currLoc+1];

	freePush(currLoc);
	
	if(prev!=NIL){
		memory[prev+1]=next;
	}

	if(next!=NIL){
		memory[next+2]=prev;
	}

	if(prev==NIL){
		list->head = next;
	}
	list->size--;
	return currLoc;
}

int count(LinkedList* list){
	return list->size;
}

void nicep(int a){
	if(a==-1) printf("NIL   ");
	else printf("%-6d",a);
}

void printList(LinkedList* list){
	int curr = list->head;
//	printf("[ ");
	printf("key   next  prev\n");
	while(curr!=NIL){
//		printf("%-6d%-6d%-6d\n",memory[curr],memory[curr+1],memory[curr+2]);
		nicep(memory[curr]);
		nicep(memory[curr+1]);
		nicep(memory[curr+2]);
		putchar('\n');
		curr = memory[curr+1];
	}
//	printf("]\n");
}

