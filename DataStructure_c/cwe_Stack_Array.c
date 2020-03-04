#include <stdio.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}


int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   }else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
   return 0;
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
	   printf("%d\t", stack[top]);
   }else {
      printf("Could not insert data, Stack is full.\n");
   }
   return 0;
}

int main() {
   // push items on to the stack 
   printf("Push Elements: \n");
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("\nElement at top of the stack: %d\n" ,peek());
   printf("Pop Elements: \n");

   // print stack data 
   while(!isempty()) {
      int data = pop();
      printf("%d\t",data);
   }

   printf("\nStack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   
   return 0;
}