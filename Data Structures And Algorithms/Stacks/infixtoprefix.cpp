#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//creating a class for the stack for further use
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

//defining what is an operator
bool isOperator(char c){
  if( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' ){
    return true;
  }
  else
  return false;
}

//setting the precedance of the operator
int precedence(char c) { 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/' || c == '%') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
}

//actual conversion from infix to prefix
string InfixToPrefix(stack s1, string infix){
  string prefix;
  reverse(infix.begin(), infix.end());//to reverse the string for further use in placing to stack accordingly
  for(int i = 0; i < infix.length(); i++){
   if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		  prefix = prefix + infix[i];

		else if(infix[i] == ')')
			s1.push(infix[i]);

		else if(infix[i] == '('){

			while((s1.topelement()!=')') && (!s1.isempty())){
				char temp=s1.topelement();
				prefix = prefix + temp;
				s1.pop();
			}

			if(s1.topelement()==')')
				s1.pop();

		}

		else if(isOperator(infix[i])){

			if(s1.isempty())
				s1.push(infix[i]);

			else{
				if(precedence(infix[i])>precedence(s1.topelement()))
					s1.push(infix[i]);	
				else if((precedence(infix[i])==precedence(s1.topelement()))&&(infix[i]=='^'))
					s1.push(infix[i]);
				else{
					while((!s1.isempty())&&( precedence(infix[i])<=precedence(s1.topelement()))){
						prefix = prefix + s1.topelement();
						s1.pop();
					}
					s1.push(infix[i]);
				}
			}
		}
	}
	while(!s1.isempty())
	{
		prefix = prefix + s1.topelement();
		s1.pop();
	}
	reverse(prefix.begin(),prefix.end());
	return prefix;
}

int main(){
  string infix_exp, prefix_exp;
  	cout << " Enter a Infix Expression : "<<endl;
  	cin >> infix_exp;
  	stack  s1;
	  cout<< " INFIX EXPRESSION: " << infix_exp << endl;
  	prefix_exp = InfixToPrefix(s1, infix_exp);
  	cout<<endl<<"PREFIX EXPRESSION: " << prefix_exp;
	return 0;
}