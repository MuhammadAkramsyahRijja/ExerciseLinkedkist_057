#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** akram, Node** syah);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() {
	Node* newNode = new Node();
	cout << "Enter roll number: ";
	cin >> newNode->rollNumber;
	cout << "Enter name: ";
	cin >> newNode->name;

	if (LAST == NULL) {
		LAST = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = LAST->next;
		LAST->next = newNode;
		LAST = newNode;
	}

	cout << "Node added successfully!" << endl;
}


bool CircularLinkedList::search(int rollno, Node** akram, Node** syah) {
	*akram = LAST->next;
	*akram = LAST->next;
	while (*syah != LAST) {
		if (rollno == (*syah)->rollNumber) {
			return true;
		}
		*akram = *syah;
		*syah = (*syah)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { 
	if (listEmpty()) {
		cout << "List is empty. Deletion failed!" << endl;
		return false;
	}

	int rollno;
	cout << "Enter the roll number to delete: ";
	cin >> rollno;

	Node* akram = NULL;
	Node* syah = NULL;

	if (search(rollno, &akram, &syah)) {
		if (syah == LAST && syah->next == LAST) {
			delete syah;
			LAST = NULL;
		}
		else if (syah == LAST) {
			LAST = akram;
			akram->next = syah->next;
			delete syah;
		}
		else {
			akram->next = syah->next;
			delete syah;
		}

		cout << "Node with roll number " << rollno << " deleted successfully!" << endl;
		return true;
	}
	else {
		cout << "Node with roll number " << rollno << " not found in the list!" << endl;
		return false;
	}
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* syahNode = LAST->next;
		while (syahNode != LAST) {
			cout << syahNode->rollNumber << " " << syahNode->name << endl;
			syahNode = syahNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}