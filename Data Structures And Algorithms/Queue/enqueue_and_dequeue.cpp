#include<iostream>
#include<algorithm>
#define max 1000
using namespace std;

//creating a template for the class so that the Queue data structure becomes valid for all kinds of data types
template<class T>
class Queue{
  private:
    int front,rear;
    T a[max];
  public:
    //initializing queue by using constructors
    Queue(){
      front = 0; // in an array implementation of linear queue, front is set to 0 and rear is set to -1
      rear = -1;
    }
    bool isempty(){
      if (front == rear)  
        return true;
      else
        return false;
    }
    bool isfull(){
      if(rear == max-1) //front == 0 is not checked in this case because we assume the queue to be full even though the initial part of queue is empty so that this would show the limitation of linear queue 
        return true;
      else
        return false;
    }
    void enqueue(T data){
      if(isfull()){
        cout << "Queue overflow" << endl;
        return;
      }
      rear++;
      a[rear] = data;
    }
    void dequeue(){
      if(isempty()){
        cout << "Queue underflow"<< endl;
        return;
      }
      front++;
    }
    void displaylast(){
      if(isempty()){
        cout << "Queue underflow"<<endl;
        return;
      }
      cout << "Last element: " << a[rear] << endl;
    }
    void displayfirst(){
      if(isempty()){
        cout << "Queue underflow"<< endl;
        return;
      }
      cout << "First element is: " << a[front] << endl;
    }
};

int main(){
  Queue<int> q1;
  int decider, data;
  // cout << q1.isempty();
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