#include <stdio.h>
#define MAXSIZE 8       
int stack[MAXSIZE];     
int top = -1;            
int isempty() {
   if(top == -1)
      return 1;
   else
      return 0;
}
int isfull() {
   if(top == MAXSIZE-1)
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
   } else {
      printf("Could not retrieve data, Stack is empty. STACK UNDERFLOW\n");
   }
}
void push(int data) {
   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full. STACK OVERFLOW\n");
   }
}
int main() {
   // push items on to the stack 
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);
   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");
   // print stack data 
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }
   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   return 0;
}



//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<process.h>
//#define N 5
//struct stack_array
//{
//  int* n[N];
//  int top;
//};
//void push(struct stack_array *s,int top);
//void pop(struct stack_array *s);
//void show(struct stack_array *s);
//void tos(struct stack_array *s);//tos = top of the stack
//
//
//int main(){
//  int c, val;
//  struct stack_array s;
//  s.top = -1;
//  do{
//    printf("\n\t\t Array implementation using stack \t\t\n");
//    fflush(stdout);
//    printf("Enter 1 for pushing, 2 for popping, 3 to show the stack,\n 4 for top of the stack and press 5 for exit");
//    fflush(stdout);
//    scanf("%d",&c);
//    switch (c)
//    {
//    case 1:
//      printf("Enter the number to push into the stack \n");
//      fflush(stdout);
//      scanf("%d",&val);
//      push(&s,val);
//      break;
//    case 2:
//      pop(&s);
//      break;
//    case 3:
//      show(&s);
//      break;
//    case 4:
//      tos(&s);
//      break;
//    case 5: 
//      exit(1);
//      break;
//    default:
//      printf("\n Wrong option");
//      fflush(stdout);
//      getch();
//      break;
//    }
//  }while(c!=5);
//}
//
//void push(struct stack_array *s,int val){
//  if(s->top == N-1){
//    printf("The stack is already full");
//    fflush(stdout);
//    getch();
//    exit(1);
//  }
//  else{
//    s->top++;
//    s->n[s->top] = val;
//    printf("\n %d is pushed to the top of the stack", val);
//    fflush(stdout);
//    getch();
//  }
//}
//
//void pop(struct stack_array *s){
//  if(s->top == -1){
//    printf("\n Sorry, the stack is empty already, underflow \n Press any key to quit");
//    fflush(stdout);
//    getch();
//    exit(1);
//  }
//  else{
//    printf("value popped is %d", s->n[s->top]);
//    fflush(stdout);
//    s->top--;
//  }
//}
//
//void show(struct stack_array *s){
//  if(s->top == -1){
//    printf("\n Sorry, the stack is empty already, underflow.\n Press any key to quit");
//    fflush(stdout);
//    getch();
//    exit(1);
//  }
//  else{
//    for (int i = s->top; i >=0; i++){
//      printf("\n %d", s->n[i]);
//    }
//  }
//}
//
//void tos(struct stack_array *s){
//  if(s->top == -1){
//    printf("\n Sorry, the stack is empty already, underflow.\n Press any key to quit");
//    fflush(stdout);
//    getch();
//    exit(1);
//  }
//  else{
//    printf("\n %d resides on the top of the stack", s->n[s->top]);
//    fflush(stdout);
//    getch();
//  }
//}


