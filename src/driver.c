#include <linkedlist.h>

int main(){

	initializeStack();

	int uin = NIL;
	int listcount=0;
	int listno;
	node_object elem;
	int status;
	int thecount;
	LinkedList* listarray[SIZE];
	printf("Welcome to the program! Written by Abhinav Ramachandran, 2017A7PS1176P on 2.1.19.");
	int trackarr[SIZE];
	while(uin!=0){

		printf("\nSelect an option:\n1. Create a new list\n2. Insert a new element in a given list in sorted order\n3. Delete an element from a given list\n4. Count total elements excluding free list\n5. Count total elements of a list\n6. Display all lists\n7. Display free list\n8. Perform defragmentation\nPress 0 to exit\n");
		scanf("%d",&uin);
		switch(uin){
		case 1:
			listarray[listcount++] = createList();
			printf("The sequence number of the newly created list is: %d.\n",listcount);
			printf("Enter key value to be inserted in the newly created list-n:");
			scanf("%d",&elem);
			status = insertSorted(listarray[listcount-1],elem);
			if(status==NIL){
				printf("FAILURE: MEMORY NOT AVAILABLE\n");
				printf("Deleting List.");
				listcount--;
			}
			else{
				printf("SUCCESS\n");
			}

			break;
		case 2:
			printf("List you want to insert in(ONE INDEXED):");
			scanf("%d",&listno);
			if(listno>listcount||listno<1){
				printf("Invalid list number! Returning to main menu.\n");
				break;
			}
			printf("Enter the key value:");
			scanf("%d",&elem);
			status = insertSorted(listarray[listno-1],elem);
			if(status==NIL){
				printf("FAILURE: MEMORY NOT AVAILABLE\n");
			}
			else{
				printf("SUCCESS\n");
			}
			break;
		case 3:
			printf("List you want to delete from(ONE INDEXED):");
			scanf("%d",&listno);
			if(listno>listcount||listno<1){
				printf("Invalid list number! Returning to main menu.\n");
				break;
			}
			printf("\nPlease enter the element:");
			scanf("%d",&elem);
			status = deleteElement(listarray[listno-1],elem);
			if(status==NIL){
				printf("FAILURE: ELEMENT NOT THERE / LIST EMPTY\n");
			}
			else{
				printf("SUCCESS\n");
			}
			break;
		case 4:
			thecount=0;
			for(int i=0;i<listcount;i++){
				thecount += count(listarray[i]);
			}
			printf("Total number of nodes in all the lists is %d.\n",thecount);
			break;
		case 5:	
			printf("Enter the list number:(ONE INDEXED):");
			scanf("%d",&listno);
			if(listno>listcount||listno<1){
				printf("Invalid list number! Returning to main menu.\n");
				break;
			}
			printf("Total number of nodes in list %d is %d.\n",listno,count(listarray[listno-1]));
			break;
		case 6:
			for(int i=0;i<listcount;i++){
				printf("Elements of list %d (of size %d) are:\n",i+1,count(listarray[i]));
				printList(listarray[i]);
			}
			break;
		case 7:
			displayFree();
			break;
		case 8:
			for(int i=0;i<listcount;i++){
				trackarr[i]=listarray[i]->head;
			}
			status = defrag(trackarr,listcount);
			if(status==NIL){
				printf("Defragmentation unsuccessful!\n");
			}
			else{
				printf("SUCCESS\n");
				for(int i=0;i<listcount;i++){
					listarray[i]->head = trackarr[i];
				}
			}
			break;
		case 9:
			printf("FreePointer is %d.\n",freePointer);
			for(int i=0;i<SIZE;i++){
				int j=i*3;
				printf("%d :%d %d %d\n",j, memory[j],memory[j+1],memory[j+2]);
			}
			break;
		case 10:
			printf("SWAPTEST\n");
			int a,b;
			scanf("%d",&a);
			scanf("%d",&b);
			swap(a,b,NULL,0);
			break;
		}
	}
	return 0;
}
