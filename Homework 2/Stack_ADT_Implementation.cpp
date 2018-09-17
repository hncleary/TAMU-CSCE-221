#include <isostream>
#include <queue>

void push(T item,queue<T> queue) {
	queue.push_back(item);
}
T pop(queue<T> queue) {
	queue queue2;
	while (queue1.size() > 1) { // copy all items except for one
		queue2.push_back(queue.pop_front());
	}
	T item = queue.pop_front(); //pop lat item in first queue
	while (queue2.isEmpty()) { // copy
		queue.push_back(queue2.pop_front());
	}
	return item;
}
isEmpty(queue<T> queue) {
	if (queue.empty() == true) { // check to se if queue is empty using empty()
		return true;
	}
	else{
		return false;
	}
}