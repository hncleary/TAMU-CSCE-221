#include "DoublyLinkedList.h"
#include <stdexcept>

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
	// Initialize the list
	header.next = &trailer;
	trailer.prev = &header;
	// Copy items from dll
	DListNode *node = dll.getFirst(); //set search node to first item
	header.next = trailer.prev = new DListNode(node->getElem(), &header, &trailer);  // initialize header and trailer pointers
	node = node->getNext(); // move to next node
	while (node != dll.getAfterLast()) { //until the last node
		insertLast(node->getElem());
		node = node->getNext();
	}
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
	while (!(this->isEmpty())) {
		this->removeLast();
	}
	header = 0;
	trailer = 0;
	header.next = &trailer;
	trailer.prev = &header;
	DListNode *newNode = dll.getFirst();
	header.next = trailer.prev = new DListNode(newNode->getElem(), &header, &trailer);
	newNode = newNode->getNext();
	while (newNode != dll.getAfterLast()) {
		insertLast(newNode->getElem());
		newNode = newNode->getNext();
	}
	return *this;
}

// insert the new object as the first one
void DoublyLinkedList::insertFirst(int newobj)
{ 
    /* Complete this function */
	DListNode *newNode = new DListNode(newobj, &header, header.next);
	header.next->prev = newNode;
	header.next = newNode;
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newobj)
{
    /* Complete this function */
	DListNode *newNode = new DListNode(newobj, trailer.prev, &trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

// remove the first object from the list 
int DoublyLinkedList::removeFirst()
{ 
    /* Complete this function */
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	DListNode *node = header.next;
	node->next->prev = &header;
	header.next = node->next;
	int obj = node->obj;
	delete node;
	return obj;
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
    /* Complete this function */
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
    /* Complete this function */
	DListNode *previous, *node = header.next;
	while (node != &trailer) {
		previous = node;
		node = node->next;
		delete previous;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// return the first object
int DoublyLinkedList::first() const
{ 
    /* Complete this function */
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	return header.next->obj;
}

// return the last object
int DoublyLinkedList::last() const
{
    /* Complete this function */
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	return trailer.prev->obj;
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(DListNode &p, int newobj)
{
    /* Complete this function */
	DListNode *newNode = new DListNode(newobj);
	DListNode *node = header.next;
	while (node != &p && node->next != NULL) {
		node = node->next;
	}
	newNode->next = node->next;
	newNode->prev = node;
	node->next = newNode;
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(DListNode &p, int newobj)
{
    /* Complete this function */
	DListNode *newNode = new DListNode(newobj);
	DListNode *node = header.next;
	while (node != &p && node->next != NULL) {
		node = node->next;
	}
	// node = node->prev;
	// insertAfter(*node, newobj);
	// newNode->prev = node->prev;
	// newNode->next = node;
	// node->prev = newNode;
	node = node->prev;
	newNode->next = node->next;
	newNode->prev = node;
	node->next = newNode;
}

// remove the node after the node p
int DoublyLinkedList::removeAfter(DListNode &p)
{
    /* Complete this function */
	DListNode *next_node = header.next;
	DListNode *node = header.next;
	while (node != &p) {
		node = node->next;
	}
	next_node = node->next;
	node->next = next_node->next;
	int obj = next_node->obj;
	delete next_node;
	return obj;
}

// remove the node before the node p
int DoublyLinkedList::removeBefore(DListNode &p)
{
    /* Complete this function */
	DListNode *next_node = header.next;
	DListNode *node = header.next;
	while (node != &p) {
		node = node->next;
	}
	node = node->prev;
	next_node = node->next;
	node->next = next_node->next;
	int obj = next_node->obj;
	delete next_node;
	return obj;
	//prev_node = node->prev;
	//node->prev = prev_node->prev;
	//int obj = prev_node->obj;
	//delete prev_node;
	return obj;
}

// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll)
{
    /* Complete this function */
	DListNode *node = dll.getFirst();
	int count = 0;
	while (node != dll.getAfterLast()) {
		count++;
		node = node->next; // go to next node
	}
	return count;
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
	/* Complete this function */
	DListNode* node = dll.getFirst(); // initialize search node and point it at first element
	while (node != dll.getAfterLast()) { // until the search node is pointing at the trailer
		out << node->obj << " "; // output the data at the node being pointed at
		node = node->next;// go to next node
	}
	return out;
}

