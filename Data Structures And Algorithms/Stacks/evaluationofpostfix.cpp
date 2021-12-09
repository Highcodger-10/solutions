#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

//creation fo stack class for further use
class stack {
  private:
    char a[20];
    int Size;
    int top;
  public:
    stack(){
      top = -1;
      Size = sizeof(a)/sizeof(char);
    }
    bool isfull(){
      if(top == Size-1)
        return true;
      else
      return false;
    }
    bool isempty(){
      if(top == -1)
        return true;
      else
        return false;
    }
    void push(char data){
      if(!isfull()){
        top++;
        a[top] = data;
      }
      else
        cout << " STACK OVERFLOW " << endl;
    }
    void pop(){
      if(!isempty()){
        top--;
      }
      else
        cout << " STACK UNDERFLOW " << endl;
    }
    char topelement(){
      return a[top];
    }
    void showstack(){
      for (int i = 0; i < Size; i++){
        cout << a[i] << endl;
      }
    }
};

//to convert character into floating number
float scanNum(char ch) {
   int value;
   value = ch;
   return float(value-'0');   //return float from character
}

//defining what is an operator
bool isOperator(char c){
  if( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' ){
    return true;
  }
  else
  return false;
}

//checking for the operand
int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;   //character is an operand
   return -1;   //not an operand
}

//implementing operation
float operation(int a, int b, char op) {
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a); //find b^a
   else
      return -1; 
}

//actual calculation
float postfixEval(string postfix) {
   int a, b;
   stack s1;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++) {
      //read elements and perform postfix evaluation
      if(isOperator(*it)) {
         a = s1.topelement();
         s1.pop();
         b = s1.topelement();
         s1.pop();
         s1.push(operation(a, b, *it));
      }
      else if(isOperand(*it) > 0) {
         s1.push(scanNum(*it));
      }
   }
   return s1.topelement();
}

int main(){
  string expression;
  cout << "Enter a postfix expression for its opeartion "<< endl;
  cin >> expression;
  float result = postfixEval(expression);
  cout << "The result will be: " << result << endl;
  return 0;
}