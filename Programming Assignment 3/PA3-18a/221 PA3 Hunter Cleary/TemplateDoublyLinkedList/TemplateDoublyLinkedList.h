#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;
template<class T>
class DoublyLinkedList;
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
// doubly linked list
template<class T>
class DoublyLinkedList
{
protected: DListNode<T> header, trailer;
public:
	DoublyLinkedList() : header(T()), trailer(T()){
		header.next = &trailer; trailer.prev = &header;
	}
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
	void insertAfter(DListNode<T> &p, T newobj); // insert after desired node
	void insertBefore(DListNode<T> &p, T newobj); // insert before selected node
	T removeAfter(DListNode<T> &p); // removes node after selected
	T removeBefore(DListNode<T> &p); //removes node before selected
};
template<class T>
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);
// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
	explicit EmptyDLinkedListException(char const* msg = NULL) : range_error(msg) {}
};
template<class T>
// copy constructor
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
	// Initialize the list
	header.next = &trailer; 
	trailer.prev = &header;
	// Copy items from dll
	DListNode<T> *node = dll.getFirst();
	header.next = trailer.prev = new DListNode<T>(node->getElem(), &header, &trailer);
	node = node->getNext();
	while (node != dll.getAfterLast()) {
		insertLast(node->getElem());
		node = node->getNext();
	}
}
template<class T>
// assignment operator
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
	// Delete the whole list
	while (!(this->isEmpty())) {
		this->removeLast();
	}
	header = 0;
	trailer = 0;
	header.next = &trailer;
	trailer.prev = &header;
	DListNode<T> *newNode = dll.getFirst();
	header.next = trailer.prev = new DListNode<T>(newNode->getElem(), &header, &trailer);
	newNode = newNode->getNext();
	while (newNode != dll.getAfterLast()) {
		insertLast(newNode->getElem());
		newNode = newNode->getNext();
	}
	return *this;
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
	DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev, &trailer);
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
	DListNode<T> *previous, *node = header.next;
	while (node != &trailer) {
		previous = node;
		node = node->next;
		delete previous;
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
int DoublyLinkedListLength(DoublyLinkedList<T>& dll) {
	DListNode<T> *node = dll.getFirst();
	int count = 0;
	while (node != dll.getAfterLast()) {
		count++;
		node = ->getNext(); //iterate through the nodes
	}
	return count;
}

template<class T>
// insert the new object after the node p
void DoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)
{
	/* Complete this function */
	DListNode<T> *newNode = new DListNode<T>(newobj);
	DListNode<T> *node = header.next;
	while (node != &p && node->next != NULL) {
		node = node->next;
	}
	newNode->next = node->next;
	newNode->prev = node;
	node->next = newNode;
}

template<class T>
// insert the new object before the node p
void DoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)
{
	/* Complete this function */
	DListNode<T> *newNode = new DListNode<T>(newobj);
	DListNode<T> *node = header.next;
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

template<class T>
// remove the node after the node p
T DoublyLinkedList<T>::removeAfter(DListNode<T> &p)
{
	/* Complete this function */
	DListNode<T> *next_node = header.next;
	DListNode<T> *node = header.next;
	while (node != &p) {
		node = node->next;
	}
	next_node = node->next;
	node->next = next_node->next;
	T obj = next_node->obj;
	delete next_node;
	return obj;
}

template<class T>
// remove the node before the node p
T DoublyLinkedList<T>::removeBefore(DListNode<T> &p)
{
	/* Complete this function */
	DListNode<T> *next_node = header.next;
	DListNode<T> *node = header.next;
	while (node != &p) {
		node = node->next;
	}
	node = node->prev;
	next_node = node->next;
	node->next = next_node->next;
	T obj = next_node->obj;
	delete next_node;
	return obj;
	//prev_node = node->prev;
	//node->prev = prev_node->prev;
	//int obj = prev_node->obj;
	//delete prev_node;
	return obj;
}
template<class T>
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {
	/* Complete this function */
	DListNode<T>* node = dll.getFirst(); // initialize search node and point it at first element
	while (node != dll.getAfterLast()) { // until the search node is pointing at the trailer
		out << node->obj << " "; // output the data at the node being pointed at
		node = node->next;// go to next node
	}
	return out;
}
