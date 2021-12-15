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
      rear = 0;
    }
    bool isempty(){
      if (front == -1 || rear == -1)
        return true;
      else
        return false;
    }
    bool isfull(){
      if((rear == max-1 && front == 0) || front == rear + 1)
        return true;
      else
        return false;
    }
    void addfront(T data){
      if(isfull()){
        cout << "Queue overflow " << endl;
        return;
      }
      //at the beginning of the data entry
      if(front == -1){
        front = 0;
        rear = 0;
      }
      else if(front == 0){
        front = max - 1;
      }
      else{
        front--;
      }
      a[front] = data;
    }
    void addrear(T data){
      if(isfull()){
        cout << "Queue overflow " << endl;
        return;
      }
      if(front == -1){
        front = 0;
        rear = 0;
      }
      else if(rear == max - 1)
        rear = 0;
      else
        rear++;
      a[rear] = data;
    }
    void removefront(){
      if(isempty()){
        cout << "Queue underflow " << endl;
        return;
      }
      if(front == rear){
        front = -1;
        rear = -1;
      }
      else{
        if(front == max - 1){
          front = 0;
        }
        else
          front++;
      }
    }
    void removerear(){
      if(isempty()){
        cout << "Queue underflow " << endl;
        return;
      }
      if(front == rear){
        front = -1;
        rear = -1;
      }
      else{
        if(rear == 0){
          rear = max -1;
        }
        else
          rear--;
      }
    }
    void displayfront(){
      if(isempty()){
        cout << "Queue underflow"<< endl;
        return;
      }
      cout << "Front element: " << a[front] << endl;
    }
    void displayrear(){
      if(isempty()){
        cout << "Queue underflow" << endl;
        return;
      }
      cout << "Rear element is: " << a[rear] << endl;
    }
};
int main(){
  Queue<int> q1;
  int decider,data;
  while(1){
    cout << "Enter 1 for inserting data from front "<< endl;
    cout << "Enter 2 for inserting data from end "<< endl;
    cout << "Enter 3 for removing data from front "<< endl;
    cout << "Enter 4 for removing data from end "<< endl;
    cout << "Enter 5 for getting data from front "<< endl;
    cout << "Enter 6 for getting data from end "<< endl;
    cout << "Enter 7 for terminating the program "<< endl;
    cin >> decider;
    switch (decider){
    case 1:
      cout << "Enter the data to be inserted: ";
      cin >> data;
      q1.addfront(data);
      break;
    case 2:
      cout << "Enter the data to be inserted: ";
      cin >> data;
      q1.addrear(data);
      break;
    case 3:
      q1.removefront();
      break;
    case 4:
      q1.removerear();
      break;
    case 5:
      q1.displayfront();
      break;
    case 6:
      q1.displayrear();
      break;
    case 7:
      exit(0);
      break;
    default:
    cout << "Enter the numbers as shown in the program"<< endl;
      break;
    }
  }
  return 0;
}