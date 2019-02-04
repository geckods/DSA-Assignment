#include <stack.h>

int freePop(){
	int curr = freePointer;
	if (freePointer==NIL) return NIL;
	freePointer = memory[curr+1];
	return curr;
}

void freePush(int loc){
	memory[loc]=NIL;
	memory[loc+1]=freePointer;
	memory[loc+2]=NIL;
	freePointer=loc;
}

void initializeStack(){
	freePointer = NIL;
	for(int i=SIZE-1;i>=0;i--){
		freePush(i*3);
	}
}

void displayFree(){
	printf("Elements of free list are:\n[");
	int curr=freePointer;
	while(curr!=NIL){
		if(memory[curr+1]==NIL)
			printf("%d]",curr);
		else
			printf("%d,",curr);

		curr = memory[curr+1];
	}
	if(freePointer==NIL){
		putchar(']');
	}
	putchar('\n');
}


void swap(int loc1, int loc2,int trackarr[],int n){
	int prev1=memory[loc1+2];
	int next1=memory[loc1+1];
	int prev2=memory[loc2+2];
	int next2=memory[loc2+1];

//	printf("%d %d\n",loc1,loc2);

	for(int i=0;i<n;i++){
		if (trackarr[i]==loc1) trackarr[i]=loc2;
		else if (trackarr[i]==loc2) trackarr[i]=loc1;
	}
	
	/*
	for(int i=0;i<SIZE;i++){
		int j=i*3;
		printf("%d :%d %d %d\n",j, memory[j],memory[j+1],memory[j+2]);
	}
	getchar();
	*/


	if(next1 != loc2 && next2 != loc1){

//		if (prev1 != NIL)
//			memory[prev1+1] = loc2;
		if(next1 != NIL && memory[next1+2]!=NIL)
			memory[next1+2] = loc2;

//		if (prev2 != NIL) 
//			memory[prev2+1] = loc1;
		if(next2 != NIL && memory[next2+2]!=NIL)
			memory[next2+2] = loc1;

		int j;
		for(int i=0;i<SIZE;i++){
			j = i*3;
//			printf("%d::%d::%d::%d\n",j,memory[j+1],loc1,loc2);
			if(memory[j+1]==loc1){
//				printf("HIHI");
				memory[j+1]=loc2;
//				printf("%d\n",memory[j+1]);
			}
			else if(memory[j+1]==loc2) memory[j+1]=loc1;
		}


	
		int a,b,c;
		a = memory[loc1];
		b = memory[loc1+1];
		c = memory[loc1+2];
	
		memory[loc1] = memory[loc2];
		memory[loc1+1] = memory[loc2+1];
		memory[loc1+2] = memory[loc2+2];
	
		memory[loc2]=a;
		memory[loc2+1]=b;
		memory[loc2+2]=c;
	}
	else{
		if(next1 == loc2){
//			if (prev1 != NIL)
//				memory[prev1+1] = loc2;
			if(next2 != NIL && memory[next2+2]!=NIL)
				memory[next2+2] = loc1;


			int a,b,c;
			a = memory[loc1];
			b = memory[loc1+1];
			c = memory[loc1+2];
	
			int j;
			for(int i=0;i<SIZE;i++){
				j = i*3;
				if(memory[j+1]==loc1) memory[j+1]=loc2;
			}

			memory[loc1] = memory[loc2];
			memory[loc1+1] = memory[loc2+1];
			if(memory[loc2+2]!=NIL)
				memory[loc1+2] = loc2;
			else
				memory[loc1+2] = NIL;
	
			memory[loc2]=a;
			memory[loc2+1]=loc1;
			memory[loc2+2]=c;



		}
		if(next2 == loc1){
//			if(prev2 != NIL)
//				memory[prev2+1] = loc1;
			if(next1 != NIL && memory[next1+2]!=NIL)
				memory[next1+2] = loc1;

			int a,b,c;
			a = memory[loc1];
			b = memory[loc1+1];
			c = memory[loc1+2];

			int j;
			for(int i=0;i<SIZE;i++){
				j = i*3;
				if(memory[j+1]==loc2) memory[j+1]=loc1;
			}
	
			memory[loc1] = memory[loc2];
			memory[loc1+1] = loc2;
			memory[loc1+2] = memory[loc2+2];
	
			memory[loc2]=a;
			memory[loc2+1]=b;
			if(memory[loc1+2]!=NIL)
				memory[loc2+2]=loc1;
			else
				memory[loc2+2] = NIL;

		}
	}
}


/*
void swap(int loc1,int loc2){

	printf("%d %d\n",loc1,loc2);
	for(int i=0;i<SIZE;i++){
		int j=i*3;
		printf("%d :%d %d %d\n",j, memory[j],memory[j+1],memory[j+2]);
	}
	getchar();

	int a,b,c;
	int prev1=memory[loc1+2];
	int next1=memory[loc1+1];
	int prev2=memory[loc2+2];
	int next2=memory[loc2+1];


	a = memory[loc1];
	b = memory[loc1+1];
	c = memory[loc1+2];
	
	memory[loc1] = memory[loc2];
	memory[loc1+1] = memory[loc2+1];
	memory[loc1+2] = memory[loc2+2];
	
	memory[loc2]=a;
	memory[loc2+1]=b;
	memory[loc2+2]=c;

	int j;
	for(int i=0;i<SIZE;i++){
		j = i*3;
		if(j==loc1 || j==loc2) continue;
		if(memory[j+1]==loc1) memory[j+1]=loc2;
		if(memory[j+1]==loc2) memory[j+1]=loc1;
		if(memory[j+2]==loc1) memory[j+2]=loc2;
		if(memory[j+2]==loc2) memory[j+2]=loc1;
	}

	if(next1==loc2){
		memory[loc2+1]=loc1;
		if(prev2!=NIL)
			memory[loc1+2]=loc2;
	}

	if(next2==loc1){
		memory[loc1+1]=loc2;
		if(prev1!=NIL)
			memory[loc2+2]=loc1;
	}
}
*/

int defrag(int trackarr[],int n){
	if(freePointer==NIL) return NIL;
	int curr=freePointer;
	int prev,next;
	int i=0;

	while(curr!=NIL){
		i++;
		swap(curr,(SIZE-i)*3,trackarr,n);
		prev=curr;
		curr = memory[(SIZE-i)*3+1];
	}
	freePointer = (SIZE-1)*3;
	return freePointer;
}

