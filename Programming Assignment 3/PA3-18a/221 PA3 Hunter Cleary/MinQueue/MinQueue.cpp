#include "DoublyLinkedList.h"
#include <iostream>
#include <vector>
using namespace std;
void enqueue(DoublyLinkedList& dll, int obj) {
	dll.insertFirst(obj);
}
void dequeue(DoublyLinkedList& dll) {
	dll.removeLast();
}
bool isEmpty(DoublyLinkedList& dll) {
	return dll.isEmpty();
}
int size(DoublyLinkedList& dll) {
	return DoublyLinkedListLength(dll);
}
int min(DoublyLinkedList dll) {
	// DListNode *newNode = new DListNode(newobj);
	vector<int> values;
	DListNode *node = dll.getFirst();
	while (node->next != NULL) {
		node = node->next;
		values.push_back(node->obj);
	}
	int min = values.at(1);
	for (int i = 0; i < values.size() - 1; i++) {
		//cout << values.at(i) << endl;
		if (values.at(i) < min) {
			min = values.at(i);
		}
	}
	return min;
}
int main () {
	// Construct a linked list with header & trailer
	cout << "Create a new list" << endl;
	DoublyLinkedList dll;
	cout << "list: " << dll << endl << endl;
	
	// Insert 10 nodes at back with value 10,20,30,..,100
	cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
	for (int i = 10; i <= 100; i += 10) {
		dll.insertLast(i);
	}
	cout << "list: " << dll << endl << endl;

	// Insert 10 nodes at front with value 10,20,30,..,100
	cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
	for (int i = 10; i <= 100; i += 10) {
		dll.insertFirst(i);
	}
	
	cout << "list: " << dll << endl << endl;

	cout << "Testing Enqueue Function: " << endl;
	enqueue(dll, 12);
	enqueue(dll, 13);
	enqueue(dll, 14);
	enqueue(dll, 15);
	cout << "list: " << dll << endl << endl;

	cout << "Testing Dequeue Function: " << endl;
	dequeue(dll);
	cout << "list: " << dll << endl << endl;

	cout << "Testing Size Function: " << endl;
	cout << "Size: " << size(dll) << endl;

	cout << endl;
	cout << "Testing isEmptyFunction: " << endl;
	cout << "Is the list empty?:  ";
	cout << isEmpty(dll) << endl;

	cout << endl;
	cout << "Testing Min Function: " << endl;
	cout << "The minimum value of this list is: " << min(dll) << endl;
	cout << endl;


  //	
  system("pause");
  return 0;
}
