#include "DoublyLinkedList.h"
#include <stdexcept>
// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
    explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};
// copy constructor

// O(n)
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll):
header(0),trailer(0){
    // Initialize the list
    header.next = &trailer; trailer.prev = &header;
    
    // Copy from dll
    DListNode *node = dll.getFirst();
    header.next =  trailer.prev = new DListNode( node->getElem(),&header, &trailer);
    node = node ->getNext();
    while( node != dll.getAfterLast()){
        // O(n)
        insertLast( node -> getElem() );
        node = node -> getNext();
    }
}
// assignment operator
// O(n)
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll){
    // Delete the whole list
    while(! (this-> isEmpty())){
        //O(n)
        this -> removeLast();
    }
    // Copy from dll
    header = 0;
    trailer = 0;
    header.next = &trailer;
    trailer.prev = &header;

    DListNode *newNode = dll.getFirst();
    header.next = trailer.prev = new DListNode( newNode->getElem(),&header, &trailer);
    newNode = newNode->getNext();
    while(newNode != dll.getAfterLast()){
        //O(n)
        insertLast(newNode -> getElem());
        newNode = newNode -> getNext();
    }
    return *this;
}
// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{
    DListNode *newNode = new DListNode(newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}
// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
    DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}
// remove the first object of the list
int DoublyLinkedList::removeFirst()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    int obj = node->obj;
    delete node;
    return obj;
}
// remove the last object of the list
int DoublyLinkedList::removeLast()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    int obj = node->obj;
    delete node;
    return obj;
}
// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    DListNode *prev_node, *node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}
// return the first object
int DoublyLinkedList::first() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return header.next->obj;
}
// return the last object
int DoublyLinkedList::last() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return trailer.prev->obj;
}
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll) {
    DListNode *current = dll.getFirst();
    int count = 0;
    while(current != dll.getAfterLast()) {
        count++;
        current = current->getNext(); //iterate
    }
    return count;
}
// output operator
// O(n)
ostream& operator<<(ostream& out, const DoublyLinkedList& dll) {
    DListNode* node = dll.getFirst();
    while( node != dll.getAfterLast()){
        //O(n)
        out << node -> getElem() << " ";
        node = node -> getNext();
    }
    return out;
}
