#include <iostream>
using namespace std;

// list node
struct Node {
  int data; // each node holds an integer data
  Node* previous; // pointer to the previous node
  Node* next; // pointer to the next node
  Node(int d=0, Node* prv=NULL, Node* nxt=NULL) : data(d), previous(prv), next(nxt) {}
  Node* get_previous() const { return previous; }
  Node* get_next() const { return next; }
  Node* insert_before(int d); // insert the int before this node
                                // return a pointer to the inserted node
  Node* insert_after(int d); // insert the int after this node
                               // return a pointer to the inserted node
  void delete_before(); // delete the node before this node
  void delete_after(); // delete the node after this node
};

// insert the int before this node
// return a pointer to the inserted node
Node* Node::insert_before(int d) {
  
  /* Complete this function */
    Node* newNode = new Node(d); // create a new node and put the data in the node
    newNode->next=this; // the next portion of the newNode should hold an address of trailer node since thats what the function is being called on.
    newNode->previous=previous; // previous portion of the newNode should now be address of the previous node aka link back
    previous->next=newNode; // the previous nodes next portion should be pointing to address of new Node. aka link ahead
    previous=newNode; // the previous node should now be the new Node.
    return newNode;
    
    
  
} // O(1) function runs in constant time
// insert the int after this node
// return a pointer to the inserted node
Node* Node::insert_after(int d) {
  
  /* Complete this function */
    Node* newNode = new Node(d); // create a new node and put data in the node
    newNode->previous=this; // the next portion of the newNode should hold an address of header node since thats what the function is being called off of
    newNode->next=next; // the next portion of newNode hold the address of the next node aka link ahead
    next->previous=newNode; // the next nodes previous should hold an address to newNode aka link back
    next = newNode; // next should now be the node newNode
    return newNode;
  
}// O(1) function runs in constant time
// delete the node before this node
void Node::delete_before()
{
  
  /* Complete this function */
    
    Node* newNode = previous; // let newNode be previous node
    previous = newNode->previous; // let previous node be newNode's previous portion
    previous->next = this; // previous nodes next portion should be trailer
    delete newNode; // delete
  
}// O(1) function runs in constant time
// delete the node after this node
void Node::delete_after()
{
  
  /* Complete this function */
    Node* newNode = next;
    next = newNode->next;
    next->previous = this;
    delete newNode;
  
}// O(1) function runs in constant time 

// Display the doubly linked list
void display_list(Node* header, Node* trailer) {
  Node* p=header->get_next();
  //Node* p=header; // uncomment this if want to display the header
  while (p!=trailer) {
    cout << p->data << ", ";
    p=p->get_next();
  }
  //cout << p->data << ", "; // uncomment this if want to display the trailer
  cout << endl;
}

// Test program
int main() {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  Node *header = new Node(-1);
  Node *trailer = new Node(-2);
  trailer->previous = header;
  header->next = trailer;
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    trailer->insert_before(i);
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;

  // Insert 10 nodes at front with value 100,90,80,..,10
  cout << "Insert 10 nodes at front with value 100,90,80,..,10" << endl;
  for (int i=10;i<=100;i+=10) {
    header->insert_after(i);
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    trailer->delete_before();
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    header->delete_after();
  }
  cout << "list: ";
  display_list(header,trailer);
  
  return 0;
  
}