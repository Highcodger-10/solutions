//simple stack implementation using C++
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<process.h>
#define MAXSIZE 5
using namespace std;
int stack[MAXSIZE];
int top = -1;
int isfull(){
  if(top == MAXSIZE - 1 ){
    return 1;
  }
  else{
    return 0;
  }
}

int isempty(){
  if(top == -1){
    return 1;
  }
  else{
    return 0;
  }
}
void push(int data){
  if(isfull()){
    cout <<  " STACK OVERFLOW. Stack is already full, no more elements can be added. " << endl;
    return;
  }
  top++;
  stack[top] = data;
}

void pop(){
  if(isempty()){
    cout << " STACK UNDERFLOW. No more elements can be popped out from the stack. " << endl;
    return;
  }
  top--;
}

void showstack(){
  cout << " The elements in the stack are shown as follows " << endl;
  for (int i = 0; i <= top; i++){
    cout << stack[i] << endl;
  }
}
void top_of_stack(){
  if(isempty()){
    cout << "The stack is empty already, no element can be shown unless elements are added to the stack" << endl;
    return ;
  }
  cout << " The top of the stack will be " << stack[top];
}

int main(){
  int decider;
  int data;
  while(1){
  cout << "Enter 1 for pushing to stack " << endl;
  cout << "Enter 2 for popping from stack " << endl;
  cout << "Enter 3 to display all elements of the stack " << endl;
  cout << "Enter 4 to display the top of the stack " << endl;
  cout << "Enter 5 to exit the program " << endl;
  cin >> decider;
    switch(decider){
      case 1: 
        cout << "Enter the integer data to be pushed into the stack "<< endl;
        cin >> data;
        push(data);
        break;
      case 2:
        pop();
        break;
      case 3:
        showstack();
        break;
      case 4:
        top_of_stack();
        break;
      case 5:
        cout << "Thank you for interacting with the stack " << endl;
        exit(0);
        break;
      default:
        cout << "You should have entered numbers from 1 to 5 " << endl;
        exit(0);
        break;
    }
  }
}