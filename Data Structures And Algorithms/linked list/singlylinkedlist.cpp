#include<iostream>
#include<cstdio>
using namespace std;
template<class type>
class Node{
  public:
    int key;
    type data;
    Node* next;
  Node(){
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, type d){
    key = k;
    data = d;
  }
};
template<class type>
class Singlylinkedlist{
  public:
    Node<type>* HEAD;
    Singlylinkedlist(){
      HEAD = NULL;
    }
    Singlylinkedlist(Node<type> *n){
      HEAD = n;
    }

    //checking if the node exists using the key value of the node
    Node<type>* nodeexists(int k){
      Node<type>* temp = NULL;
      Node<type> *ptr = HEAD;
      while(ptr!= NULL){
         if(ptr->key == k){
           temp = ptr;
         }
         ptr = ptr->next;
      }
      return temp;
    }

    //appending a node at the end of the list
    void appendnode(Node<type> *n){
      if(nodeexists(n->key)!= NULL){
        cout << "Node already exists with the key value: " << n->key << "Append another node with different key value" << endl;
      }
      else{
        if(HEAD == NULL){
          HEAD = n;
          cout << "Node appended to the list"<< endl;
        }
        else{
          Node<type> *ptr = HEAD;
          while(ptr->next!= NULL){
            ptr = ptr->next;
          }
          ptr->next = n;
          cout << "Node appended to the list"<< endl;
        }
      }
    }

    //prepending the node at the start
    void prependnode(Node<type> *n){
      if(nodeexists(n->key)!= NULL){
        cout << "Node already exists with the key value: " << n->key << "Append another node with different key value" << endl;
      }
      else{
        if(HEAD == NULL){
          HEAD = n;
          cout << "Node appended to the list"<< endl;
        }
        else{
          n->next = HEAD;
          HEAD = n;
          cout << "Node Prepended "<< endl;
        }
      }
    }

    //inserting after a certain node
    void Insertafter(int k, Node<type> *n){
      Node<type> *ptr = nodeexists(k);
      if(ptr == NULL){
        cout << "No node exists with that particular key "<< endl;
      }
      else{
        if(nodeexists(n->key)!= NULL){
        cout << "Node already exists with the key value: " << n->key << "Append another node with different key value" << endl;
        }
        else{
          n->next = ptr->next;
          ptr->next = n;
          cout << " Node inserted at desired location "<< endl;
        } 
      }
    }

    //deleting a particular node by keyvalue
    void deletenode(int k){
      if(HEAD == NULL){
        cout << "Singly linked list already empty, cant deleter further "<< endl;
      }
      //what if the 1st node is to be removed
      else if(HEAD->key == k){
        HEAD = HEAD->next;
        cout << "node deleted from the list "<< endl;
      }
      //for nodes other than 1st node to be removed
      else{
        Node<type>* temp = NULL;
        Node<type>* prevptr = HEAD;
        Node<type>* currentptr = HEAD->next;
        while(currentptr!= NULL){
          if(currentptr->key == k){
            temp = currentptr;
            currentptr = NULL;
          }
          else{
            prevptr = prevptr->next;
            currentptr = currentptr->next;
          }
        }
        if(temp != NULL){
          prevptr->next = temp->next;
          cout << "node deleted from the list "<<endl;
        }
        else{
          cout << "Node with key "<< k << " not found" <<endl;
        }
      }
    }

    //deleting after a certain keyvalue
    void deleteafterkey(int k){
      Node<type> *ptr = nodeexists(k);
      if(ptr->next == NULL){
        cout << "Next node is null i.e. there is no any node further "<< endl;
        return;
      }
      else if(HEAD == NULL){
        cout << "Singly linked list already empty, cant deleter further "<< endl;
      }
      else{
        Node<type>* temp = NULL;
        Node<type>* prevptr = HEAD;
        Node<type>* cptr = HEAD->next;
        while(cptr != NULL){
          if(prevptr->key == k){
            temp = prevptr->next;
            cptr = NULL;
          }
          else{
            prevptr = prevptr->next;
            cptr = cptr->next;
          }
        }
        if(temp != NULL){
          prevptr->next = temp->next;
          cout << "Node after the key "<< k<<  " deleted " <<endl; 
        }
        else{
          cout << "Node after the key "<< k<< " Not found";
        }
      }
    }

    //deleting from beginning
    void deletefront(){
      if(HEAD == NULL){
        cout << "Singly linked list already empty, cant deleter further "<< endl;
      }
      else{
        HEAD = HEAD->next;
        cout << "1st node deleted "<< endl;
      }
    }

    //deleting from rear
    void deleterear(){
      if(HEAD == NULL){
        cout << "Singly linked list already empty, cant deleter further "<< endl;
      }
      else{
        Node<type>* temp = NULL;
        Node<type>* prevptr = HEAD;
        Node<type>* cptr = HEAD->next;
        while(cptr->next!= NULL){
          prevptr = prevptr->next;
          cptr = cptr->next;
        }
        // cptr = NULL;
        prevptr->next = NULL;
        cout << "Node deleted from rear "<< endl;
      }
    }

    //updating node by key
    void updatenodebykey(int k, type d){
      Node<type>* ptr = nodeexists(k);
      if(ptr != NULL){
        ptr->data = d;
        cout << "node updated successfully..." <<endl;
      }
      else{
        cout << "no node found "<< endl;
      }
    }

    //printing all of the nodes in the list
    void displayall(){
      Node<type>* ptr = HEAD;
      if(ptr == NULL){
        cout << "Node already empty "<< endl;
      }
      else{
        while(ptr!= NULL){
          cout << ptr->key << "\t" << ptr->data << endl;
          ptr = ptr->next;
        }
      }
    }
};

int main(){
  Singlylinkedlist<int> s;
  int option,key1,k1,data1;
  do{
    cout << "Select acordingly press 0 for exit"<< endl;
    cout << "1. appending node "<< endl;
    cout << "2. prepending node "<< endl;
    cout << "3. Inserting after a certain postion "<< endl;
    cout << "4. delete a node by key "<< endl;
    cout << "5. updating node "<< endl;
    cout << "6. display nodes "<< endl;
    cout << "7. delete node from front"<< endl;
    cout << "8. delete node from rear " << endl;
    cout << "9. delete node after a certain key value" << endl;
    cout << "10. clear screen "<< endl;
    cin >> option;
    Node<int>* n1 = new Node<int>();
    switch(option){
      case 0:
        exit(0);
        break;
      case 1:
        cout << "Enter the key and data for the node to be appended "<< endl;
        cin >> key1;
        cin >> data1;
        n1->key = key1;
        n1->data = data1;
        s.appendnode(n1);
        break;
      case 2:
        cout << "Enter the key and the data for the node to be prepended "<< endl;
        cin >> key1;
        cin >> data1;
        n1->key = key1;
        n1->data = data1;
        s.prependnode(n1);
        break;
      case 3:
        cout << "Enter the key of the node after which node is to be placed "<< endl;
        cin >> k1;
        cout << "Enter the key and the data for the node to be prepended "<< endl; 
        cin >> key1;
        cin >> data1;
        n1->key = key1;
        n1->data = data1;
        s.Insertafter(k1,n1);
        break;
      case 4:
        cout << "Enter the key of the node to delete "<< endl;
        cin >> k1;
        s.deletenode(k1);
        break;
      case 5:
        cout << "Enter the key of the node to update "<< endl;
        cin >> k1;
        cout << "Enter the data to interchange "<<endl;
        cin >> data1;
        s.updatenodebykey(k1,data1);
        break;
      case 6:
        s.displayall();
        break;
      case 7:
        s.deletefront();
        break;
      case 8:
        s.deleterear();
        break;
      case 9:
        cout << "Enter the key value for deletion "<< endl;
        cin >> k1; 
        s.deleteafterkey(k1);
        break;
      case 10:
        system("cls");
        break;
      default:
        cout << "Enter proper option number "<< endl;
        break;
    }
  }while(option!=0);
  return 0;
}
