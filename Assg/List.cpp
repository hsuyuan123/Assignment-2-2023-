

#include "List.h"
List::List() { size = 0; firstNode = NULL; }
bool List::add(ItemType item)
{
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	if (firstNode == NULL)
	{
		firstNode = newNode;
	}
	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;

	}
	size++;
	return true;
}
bool List::add(int index, ItemType item)
{
	if (index >= 0 && index < size)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		if (firstNode == NULL)
		{
			firstNode = newNode;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 1; i < index; i++) {
				if (temp->next != NULL) {
					temp = temp->next;
				}
			}
			if (index == 0)
			{

				newNode->item = temp->item;
				temp->item = item;
				newNode->next = temp->next;
				temp->next = newNode;

			}
			else
			{
				newNode->next = temp->next;
				temp->next = newNode;
			}


		}
		size++;
		return true;
	}
	else
	{
		return false;
	}

}
void List::remove(int index)
{
	if (index >= 0 && index < size)
	{

		if (index == 0)
		{
			firstNode = firstNode->next;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 1; i < index; i++) {
				if (temp->next != NULL) {
					temp = temp->next;
				}
			}

			temp->next = temp->next->next;
		}


		size--;

	}


}
ItemType List::get(int index)
{
	if (index >= 0 && index < size)
	{


		if (index == 0)
		{
			return firstNode->item;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 0; i < index; i++) {
				if (temp->next != NULL) {
					temp = temp->next;

				}

			}
			return temp->item;
		}

	}
}
bool List::isEmpty()
{
	if (firstNode == NULL) { return true; }
	else { return false; }
}
int List::getLength()
{
	Node* temp = firstNode;
	int amt = 0;
	// Check for empty list.
	if (firstNode == NULL) {
		return 0;
	}

	// Traverse the list.
	while (temp != NULL) {
		temp = temp->next;
		amt++;
	}
	return amt;
}

void List::print()
{
	Node* temp = firstNode;

	// Check for empty list.
	if (firstNode == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		cout << temp->item << " ";
		temp = temp->next;
	}
	cout << endl;
}



