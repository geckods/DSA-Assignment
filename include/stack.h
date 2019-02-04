/*stack.h*/
#include <stdio.h>
#include <stdlib.h>

/*
#define SIZE 10

int memory[SIZE*3];
*/
int SIZE;
int *memory;

#define NIL -1

int freePointer;

int freePop();
void freePush(int loc);
void initializeStack();
void displayFree();
void swap(int loc1, int loc2,int trackarr[],int n);

int defrag(int trackarr[],int n);
