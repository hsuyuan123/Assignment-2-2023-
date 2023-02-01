/*#using "topic.h"
List::List() {
	firstNode = NULL;
	size = 0;
}

bool List::add(ItemType item) {
	Node* newNode = new Node;

	newNode->item = item;
	newNode->next = NULL;
	if (size == 0) {
		firstNode = newNode;
	}
	else {
		Node* temp = firstNode;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp = newNode;
	}
	size++;
	return true;
}
bool List::add(int index, ItemType item) {
	if ((index >= 0) && (index <= size)) {
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		if (index == 0) {
			firstNode = newNode;
		}
		else {
			Node* temp = firstNode;
			for (int pos = index - 1; pos < size; pos++) {
				temp = temp->next;
			}
			newNode = temp;



		}
		size++;
		return true;
	}
	else
	{
		return false;
	}
}
void List::remove(int index) {
	if ((index > 0) && (index <= size)) {
		if (index == 1) {
			firstNode->next = NULL;
		}
		else
		{
			Node* temp = firstNode;
			for (int pos = index - 1; pos < size; pos++) {
				temp = temp->next;
			}
			temp->next;
		}
	}
	size--;
}

void List::print() {
	Node* temp = firstNode;
	while (temp->next != NULL) {
		std::cout << temp->item;
		temp = temp->next;
	}
}*/