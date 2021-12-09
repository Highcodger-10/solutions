#include<iostream>
#include<cstring>
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


// function to check if brackets are balanced
bool areBracketsBalanced(string expr){ 
    stack s1;
    char x;
    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++){
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{'){
            // Push the element in the stack
            s1.push(expr[i]);
        }
 
        // If without checking for the closing bracket, if we are to check for stack to be empty, then ofcourse it is going to be empty as we don't push the closing bracket into the stack. So false should be returned even if there are no opening brackets.
        if (s1.isempty())
            return false;
 
        switch (expr[i]) {
        case ')':
            // Store the top element in a variable x also to check for correct bracket pair. If the bracket pair is not correct, expression is not balanced
            x = s1.topelement();
            s1.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':
            x = s1.topelement();
            s1.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
            x = s1.topelement();
            s1.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    // Check for Empty Stack after gone through the entire process of traversing through the expression
    return (s1.isempty());
}
 
// Driver code
int main()
{
    string expr;
    cout << "Enter the expression to check for the balanced parenthesis " << endl;
    cin >> expr;
    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}