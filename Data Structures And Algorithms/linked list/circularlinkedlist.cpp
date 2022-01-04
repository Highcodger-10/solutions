#include <iostream>
using namespace std;
template <class type>
class Node{
  public:
    int key;
    int data;
    Node *next;
    Node(){
      key = 0;
      data = 0;
      next = NULL;
    }
    Node(int k, int d){
      key = k;
      data = d;
    }
};
template <class type>
class CircularLinkedList{
  public:
    Node<type> *HEAD;
    CircularLinkedList(){
    HEAD = NULL;
    }
  //  CHeck if node exists using key value
  Node<type> *nodeExists(int k){
    Node<type> *temp = NULL;
    Node<type> *ptr = HEAD;
    if (ptr == NULL){
      return temp;
    }
    else{
      do{
        if (ptr->key == k){
          temp = ptr;
        }
        ptr = ptr->next;
      }while (ptr != HEAD);
      return temp;
    }
  }
  //  Append a node to the list
  void appendNode(Node<type> *n){
    if(nodeExists(n->key)!= NULL){
        cout << "Node already exists with the key value: " << n->key << "Append another node with different key value" << endl;
      }
    else{
      if (HEAD == NULL){
        HEAD = n;
        n->next = HEAD;
        cout << "Node Appended at first HEAD position" << endl;
      }
      else{
        Node<type> *ptr = HEAD;
        while (ptr->next != HEAD){
          ptr = ptr->next;
        }
        ptr->next = n;
        n->next = HEAD;
        cout << "Node Appended" << endl;
      }
    }
  }
  //  Prepend Node - Attach a node at the start
  void prependNode(Node<type> *n){
    if (nodeExists(n->key) != NULL){
      cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
    }
    else{
      if (HEAD == NULL){
        HEAD = n;
        n->next = HEAD;
        cout << "Node Prepended at first HEAD position" << endl;
      }
      else{
        Node *ptr = HEAD;
        while (ptr->next != HEAD){
          ptr = ptr->next;
        }
        ptr->next = n;
        n->next = HEAD;
        HEAD = n;
        cout << "Node Prepended" << endl;
      }
    }
  }

  //  Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node<type> *n){
    Node<type> *ptr = nodeExists(k);
    if (ptr == NULL){
      cout << "No node exists with key value OF: " << k << endl;
    }
    else{
      if (nodeExists(n->key) != NULL){
        cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
      }
      else{
        //incase we need to insert at the end
        if (ptr->next == HEAD){
          n->next = HEAD;
          ptr->next = n;
          cout << "Node Inserted at the End" << endl;
        }
        //inserting in other places besides at the end
        else{
          n->next = ptr->next;
          ptr->next = n;
          cout << "Node Inserted in between" << endl;
        }
      }
    }
  }

  //  Delete node by unique key
  void deleteNodeByKey(int k){
    Node<type> *ptr = nodeExists(k);
    if (ptr == NULL){
      cout << "No node exists with key value OF : " << k << endl;
    }
    else{
      //if selected node is the head node
      if (ptr == HEAD){
        //if only one node is in the list
        if (HEAD->next == NULL){
          HEAD = NULL;
          cout << "HEAD node Unlinked... List Empty";
        }
        //for more than one nodes
        else{
          Node<type> *ptr1 = HEAD;
          while (ptr1->next != HEAD){
            ptr1 = ptr1->next;
          }
          ptr1->next = HEAD->next;
          HEAD = HEAD->next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        }
      }
      //if selected node is other than the head node
      else{
        Node<type> *temp = NULL;
        Node<type> *prevptr = HEAD;
        Node<type> *currentptr = HEAD->next;
        while (currentptr != NULL){
          if (currentptr->key == k){
            temp = currentptr;
            currentptr = NULL;
          }
          else{
            prevptr = prevptr->next;
            currentptr = currentptr->next;
          }
        }
        prevptr->next = temp->next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      }
    }
  }

  //for the node after key k to be deleted
  void deleteafter(int k){
    Node<type> *ptr = nodeExists(k);
    if (ptr == NULL){
      cout << "No node exists with key value OF : " << k << endl;
    }
    else{
      //if next node is head node
      if(ptr->next == HEAD){
        if(ptr == HEAD){
          HEAD = NULL;
          cout << "HEAD node Unlinked... List Empty";
        }
        else{
          Node<type> *ptr1 = HEAD;
          while (ptr1->next != HEAD){
            ptr1 = ptr1->next;
          }
          ptr1->next = HEAD->next;
          HEAD = HEAD->next;
          cout << "HEAD node removed " <<  endl;
        } 
      }
      //if next node is not the head node
      else{
        Node<type> *temp = NULL;
        Node<type> *prevptr = HEAD;
        Node<type> *cptr = HEAD->next;
        while(cptr!= NULL){
          if(prevptr->key == k){
            temp = cptr;
            cptr = NULL;
          }
          else{
            prevptr = prevptr->next;
            cptr = cptr->next;
          }
        }
        prevptr->next = temp->next;
        cout << "node after the node with key "<< k<< " is removed"<< endl;
      }
    }
  }


  //delete from front
  void delfront(){
    Node<type> *ptr = HEAD;
    //for only one node
    if (HEAD->next == NULL){
      HEAD = NULL;
      cout << "HEAD node Unlinked... List Empty";
    }
    //for more than one nodes
    else{
      Node<type> *ptr1 = HEAD;
      while (ptr1->next != HEAD){
        ptr1 = ptr1->next;
      }
      ptr1->next = HEAD->next;
      HEAD = HEAD->next;
      cout << "HEAD node removed " <<  endl;
    }
  }

  //delete from rear
  void delrear(){
    Node<type>* temp = NULL;
    Node<type> *prevptr = HEAD;
    Node<type> *cptr = HEAD->next;
    while(cptr->next!= HEAD){
      prevptr = prevptr->next;
      cptr = cptr->next;
    }
    temp = cptr;
    cptr = NULL;
    prevptr->next = temp->next;
    cout << "Node deleted from rear "<< endl;
  }


  //update node
  void updateNodeByKey(int k, int new_data){
    Node<type> *ptr = nodeExists(k);
    if (ptr != NULL){
      ptr->data = new_data;
      cout << "Node Data Updated Successfully" << endl;
    }
    else{
      cout << "Node Doesn't exist with key value : " << k << endl;
    }
  }

  // printing all of the nodes in the list
  void printList(){
    if (HEAD == NULL){
      cout << "No Nodes in Circular Linked List" << endl;
    }
    else{
      Node<type> *temp = HEAD;
      do{
        cout << temp->key << "\t" << temp->data << "\t" << temp->next << endl;
        temp = temp->next;
      }while (temp != HEAD);
    }
  }
};

int main(){
  CircularLinkedList<int> obj;
  int option;
  int key1, k1, data1;
  do{
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
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
    Node<int> *n1 = new Node<int>();
    // Node n1;
    switch (option){
    case 0:
      delete n1;
      exit(0);
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;
      obj.appendNode(n1);
      // cout<<n1.key<<" = "<<n1.data<<endl;
      break;
    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;
      obj.prependNode(n1);
      break;
    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;
      obj.insertNodeAfter(k1, n1);
      break;
    case 4:
      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);
      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);
      break;
    case 6:
      obj.printList();
      break;
    case 7:
      obj.delfront();
      break;
    case 8:
      obj.delrear();
      break;
    case 9:
      cout << "Enter the key of the node after which deletion is to be preformed "<<endl;
      cin >> k1;
      obj.deleteafter(k1);
      break;
    case 10:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
  }while(option != 0);
  return 0;
}