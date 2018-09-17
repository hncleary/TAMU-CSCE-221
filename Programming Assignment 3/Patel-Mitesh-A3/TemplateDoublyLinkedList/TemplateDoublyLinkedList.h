#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;
template<class T>
class DoublyLinkedList; // class declaration

// list node
template<class T>

class DListNode {
private: T obj;
    DListNode<T> *prev, *next;
    friend class DoublyLinkedList<T>;
public:
    DListNode(T e = T(), DListNode<T> *p = NULL, DListNode<T> *n = NULL) // use default value for this class - T()
    : obj(e), prev(p), next(n) {}
    T getElem() const { return obj; }
    DListNode<T> * getNext() const { return next; }
    DListNode<T> * getPrev() const { return prev; }
};


//Big O time complexity is same for doubly linked list.
// doubly linked list
template<class T>

class DoublyLinkedList
{
protected: DListNode<T> header, trailer;
public:
    DoublyLinkedList() : header(T()), trailer(T()) // constructor
    { header.next = &trailer; trailer.prev = &header; }
    DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor
    ~DoublyLinkedList(); // destructor
    DoublyLinkedList& operator=(const DoublyLinkedList<T>& dll); // assignment operator
    // return the pointer to the first node
    DListNode<T> *getFirst() const { return header.next; }
    // return the pointer to the trailer
    const DListNode<T> *getAfterLast() const { return &trailer; }
    // return if the list is empty
    bool isEmpty() const { return header.next == &trailer; }
    T first() const; // return the first object
    T last() const; // return the last object
    void insertFirst(T newobj); // insert to the first of the list
    T removeFirst(); // remove the first node
    void insertLast(T newobj); // insert to the last of the list
    T removeLast(); // remove the last node
};
template<class T>
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);


// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
    explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};





template<class T>
// copy constructor
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
    // Initialize the list
    header.next = &trailer; trailer.prev = &header;
    
    // Copy from dll
    /* Complete this function */
    
    if (!dll.isEmpty()){ // if not empty
        DListNode<T>* newNode; // create a new node
        newNode = dll.getFirst(); // get the first node in the list
        while (newNode != dll.getAfterLast()) // basically while node is not trailer because trailer is the last node it signifies stop O(n) because goes through node by node
        {
            insertLast(newNode->getElem());//insert new element
            newNode = newNode->getNext();//go to next node
        }
    }
}






template<class T>
// assignment operator
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
    // Delete the whole list
    /* Complete this function */
    DListNode<T> *previousNode, *newNode = header.next; // create two nodes one to hold previous and one to hold new and initialize to the next portion of the headers node
    while (newNode != &trailer) { // until you hit last element basically // O(n) because node by node
        previousNode = newNode; // set previousNode to newNode
        newNode = newNode->next; //set newNode to the newNode's next node
        delete previousNode; // finally delete previous node
    }
    header.next = &trailer; // reset header and trailer
    trailer.prev = &header;
    
    // Copy from dll
    /* Complete this function */
    if (!dll.isEmpty())
    {
        newNode = dll.getFirst(); // let newNode be the first Node in list
        while (newNode != dll.getAfterLast()) // go through while loop until last basically // O(n) because node by node
        {
            insertLast(newNode->getElem());//set new element
            newNode = newNode->getNext();//go to next node
        }
    }
}






template<class T>
// insert the object to the first of the linked list
void DoublyLinkedList<T>::insertFirst(T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}

template<class T>
// insert the object to the last of the linked list
void DoublyLinkedList<T>::insertLast(T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}

template<class T>
// remove the first object of the list
T DoublyLinkedList<T>::removeFirst()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    T obj = node->obj;
    delete node;
    return obj;
}

template<class T>
// remove the last object of the list
T DoublyLinkedList<T>::removeLast()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    T obj = node->obj;
    delete node;
    return obj;
}

template<class T>
// destructor
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DListNode<T> *prev_node, *node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

template<class T>
// return the first object
T DoublyLinkedList<T>::first() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return header.next->obj;
}

template<class T>
// return the last object
T DoublyLinkedList<T>::last() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return trailer.prev->obj;
}

template<class T>
// return the list length
T DoublyLinkedListLength(DoublyLinkedList<T>& dll) {
    DListNode<T> *current = dll.getFirst();
    T count = T();
    while(current != dll.getAfterLast()) {
        count++;
        current = current->getNext(); //iterate
    }
    return count;
}






template<class T>
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {
    
    /* Complete this function */
    DListNode<T>* temp = dll.getFirst(); // create new temp node initalized to first node
    while (temp != dll.getAfterLast()){//go until last element O(n)
        out << temp->getElem() << " ";
        temp = temp->getNext();
    }
    return out;
}
