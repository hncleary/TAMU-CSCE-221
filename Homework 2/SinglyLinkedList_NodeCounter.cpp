#include <iostream>

int count(*ListNode node) {
	if (node == NULL) {
		return 0;
	}
	else if (node != NULL) {
		return 1 + count(node->next);
	}
}