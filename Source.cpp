#include <iostream>
using namespace std;

class chunk {
public:
	int value;
	chunk* next;

	chunk() {
		value = 0;
		next = NULL;
	}


};
class LinkedList {
public:
	int length;
	chunk* head;
	LinkedList() {
		length = 0;
		head = NULL;
	}
	void insertAtHead(int value) {
		chunk* temp;
		temp = new chunk;
		temp->value = value;
		temp->next = head;
		head = temp;
		length++;
	}
	void insertAtPosition(int value, int position) {
		chunk* temp;
		temp = new chunk;
		temp->value = value;
		if (position <= length + 1 && position > 0) {
			if (position == 1) {
				cout << "use 'insert at head' function" << endl;
			}
			else if (position > 1 && position <= length + 1) {
				chunk* helper = head;
				for (int i = 1; i < position - 1; i++) {
					helper = helper->next;
				}
				temp->next = helper->next;
				helper->next = temp;
				length++;
			}

		}
		else {
			cout << "invalid position" << endl;
		}
	}
	void remove(int position) {


		if (position > 0 && position <= length) {
			if (length == 1 && position == 1) {
				delete head;
				head = NULL;
			}
			else if (position == 1) {
				chunk* temp = head;
				head = head->next;
				delete temp;
			}
			else if (position > 1 && position <= length) {
				chunk* temp;
				chunk* slow;
				temp = slow = head;

				for (int i = 1; i <= position - 1; i++) {
					slow = temp;
					temp = temp->next;
				}
				slow->next = temp->next;
				delete temp;
			}
			length--;
		}
		else {
			cout << "cannot delete" << endl;
		}
	}
	void displayContents() {
		chunk* temp;
		temp = head;
		cout << "--------------" << endl;
		while (temp != NULL) {
			cout << temp->value << " --> ";
			temp = temp->next;

		}
		cout << "NULL" << endl;
		cout << "--------------" << endl;
	}
	void reverseLinkedList() {
		chunk* temp;
		chunk* follow;
		chunk* slow;
		follow = head;
		temp = head->next;
		head->next = NULL;

		while (temp != NULL) {
			slow = follow;
			follow = temp;
			temp = temp->next;
			follow->next = slow;
		}
		head = follow;
	}
	void removeEveryOtherNode() {
		int l = 0;
		int i = 0;
		chunk* temp;
		chunk* destroy;
		temp = head;
		destroy = head;
		while (temp->next != NULL && temp->next->next != NULL) {
			destroy = temp->next;
			temp->next = temp->next->next;
			temp = temp->next;
			delete destroy;
			l++;
		}
		if (temp->next != NULL && temp->next->next == NULL) {
			destroy = temp->next;
			temp->next = NULL;
			destroy->next = NULL;
			delete destroy;
			length--;
		}
		while (i < l) {
			length--;
			i++;
		}
	}
};
int main() {
	LinkedList L;
	int value, position, a;
	while (1) {
		cout << "press 1 to add to head" << endl;
		cout << "press 2 to add elsewhere" << endl;
		cout << "press 3 to remove" << endl;
		cout << "press 4 to display contents" << endl;
		cout << "press 5 to exit" << endl;
		cout << "press 6 to reverse" << endl;
		cout << "press 7 to delete every other value" << endl;
		cin >> a;
		switch (a) {
		case 1:
			cout << "insert value to add" << endl;
			cin >> value;
			L.insertAtHead(value);
			break;
		case 2:
			cout << "insert value to add" << endl;
			cin >> value;
			cout << "insert position" << endl;
			cin >> position;
			L.insertAtPosition(value, position);
			break;
		case 3:
			cout << "insert position" << endl;
			cin >> position;
			L.remove(position);
			break;
		case 4:
			L.displayContents();
			break;
		case 5:
			exit(1);
		case 6:
			L.reverseLinkedList();
			L.displayContents();
			break;
		case 7:
			L.removeEveryOtherNode();
			L.displayContents();
			break;
		}
		
	}
}