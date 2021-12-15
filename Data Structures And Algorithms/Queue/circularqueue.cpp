#include<iostream>
#include<algorithm>
#define max 100
using namespace std;
template<class T>
class Queue{
  private:
    int front,rear;
    T a[max];
  public:
    Queue(){
      front = -1;
      rear = -1;
    }
    bool isempty(){
      if((front == rear+1) || (front == -1) )
        return true;
      else
        return false;
    }
    bool isfull(){
      if((rear == max-1) && front == 0)
        return true;
      else
        return false;
    }
    void enqueue(T data){
      if(isfull()){
        cout << "Queue overflow" << endl;
        return;
      }
      if(front == -1){
        front = 0;
      }
      rear++;
      if(rear >= max){
        rear == 0;
      }
      a[rear] = data;
    }
    void dequeue(){
      if(isempty()){
        cout << "Queue underflow" << endl;
        return;
      }
      front++;
      if(front == rear+1){
        front = -1;
        rear = -1;
      }
      if(front >= max){
        front = 0;
      }
    }
    void displaylast(){
      if(isempty()){
        cout << "Queue underflow"<< endl;
        return;
      }
      cout << "Last element: " << a[rear] << endl;
    }
    void displayfirst(){
      if(isempty()){
        cout << "Queue underflow" << endl;
        return;
      }
      cout << "First element is: " << a[front] << endl;
    }
};
int main(){
  Queue<int> q1;
  int decider, data;
  while(1){
    cout << " Enter 1 for enqueue " << endl;
    cout << " Enter 2 for dequeue " << endl;
    cout << " Enter 3 for displaying last element " << endl;
    cout << " Enter 4 for displaying first element " << endl;
    cout << " Enter 5 to exit the program " << endl;
    cin >> decider;
    switch(decider){
      case 1:
        cout << " Enter the data for insertion: ";
        cin >> data;
        q1.enqueue(data);
        break;
      case 2:
        q1.dequeue();
        break;
      case 3:
        q1.displaylast();
        break;
      case 4:
        q1.displayfirst();
        break;
      case 5:
        exit(0);
        break;
      default:
        cout << "Enter the numbers as listed in the program "<< endl;
        break;
    }
  }
  return 0;
}