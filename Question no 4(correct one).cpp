#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
node* head = NULL;
node* head1 = NULL;
node* curr1 = NULL;
node* head2 = NULL;
node* Insert(node* NODE, int data) {

	node* curr = NULL;
	if (head == NULL) {
		NODE = new node;
		NODE->data = data;
		head = NODE;
		curr = NODE;
	}
	else {
		curr = NODE;
		NODE = new node;
		NODE->data = data;
		NODE->next = NULL;
		curr->next = NODE;
		curr1 = NODE;
	}
	return NODE;
}
node* Insert1(node* NODE, int data) {

	node* curr = NULL;
	if (head1 == NULL) {
		NODE = new node;
		NODE->data = data;
		head1 = NODE;
		curr = NODE;
	}
	else {
		curr = NODE;
		NODE = new node;
		NODE->data = data;
		NODE->next = NULL;
		curr->next = NODE;
	}
	return NODE;
}
node* Insert3(node* NODE, int data) {

	node* curr = NULL;
	if (head2 == NULL) {
		NODE = new node;
		NODE->data = data;
		head2 = NODE;
		curr = NODE;
	}
	else {
		curr = NODE;
		NODE = new node;
		NODE->data = data;
		NODE->next = NULL;
		curr->next = NODE;
	}
	return NODE;
}
node* merge_lists(node* NODE1) {
	node* temp = head1;
	int count = 0;
	while (count < 3) {
		if (count == 2) {
			curr1->next = temp;
			break;
		}
		else {
			temp = temp->next;
			count = count + 1;
		}
	}
	return head;
}
void Print() {
	node* NODE = head;
	cout << endl;
	while (NODE != NULL) {
		cout << NODE->data;
		cout << endl;
		NODE = NODE->next;
	}
}
void Common_Element() {
	head2 = NULL;
	node* NODE = head;
	node* NODE2 = NULL;
	while (NODE != NULL) {
		NODE2 = Insert3(NODE2, NODE->data);
		NODE = NODE->next;
	}
	node* temp2 = head2;
	node* temp3 = head2;
	int count = 0;
	int data = 0;
	while (temp2 != NULL) {
		temp3 = head2;
		data = temp2->data;
		while (temp3 != NULL) {
			if (temp3->data == data) {
				count = count + 1;
				temp3->data = 0;
			}
			temp3 = temp3->next;
		}
		if (data != 0 && count > 1) {
			cout << "Your Data :: " << data << " Comes " << count << " Times";
			cout << endl;
		}
		count = 0;
		temp2 = temp2->next;
	}
	cout << endl;

}
void Print1() {
	node* NODE = head;
	cout << endl;
	while (NODE != curr1->next) {
		cout << NODE->data;
		cout << endl;
		NODE = NODE->next;
	}
}
void Print3() {
	node* NODE = head1;
	cout << "Your Data is ";
	cout << endl;
	cout << "---------------";
	cout << endl;
	while (NODE != NULL) {
		cout << NODE->data;
		cout << endl;
		NODE = NODE->next;
	}
}
int main() {
	node* Node = NULL;
	node* Node1 = NULL;

	int l = 10;
	while (true) {
		cout << "Enter 1 to Input the Value in 1st Link list";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 2 to Input the Value in 1st Link list";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 3 to Merg ";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 4 to Print The Merig Link List i.e Mergigng should done";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 5 to Print The First Link List";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 6 to Find The Common Element";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 7 to Print The Second Link List";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 8 to Break";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		int data;
		cin >> data;
		if (data == 1) {
			cout << "Enter The Data You Want to Insert";
			cout << endl;
			cout << "--------------------------------------------";
			cout << endl;
			int data = 0;
			cin >> data;
			Node = Insert(Node, data);
		}
		if (data == 2) {
			cout << "Enter The Data You Want to Insert";
			cout << endl;
			cout << "--------------------------------------------";
			cout << endl;
			int data1 = 0;
			cin >> data1;
			Node1 = Insert1(Node1, data1);
		}
		if (data == 3) {
			merge_lists(Node1);
		}
		if (data == 4) {
			Print();
		}
		if (data == 5) {
			Print1();
		}
		if (data == 6) {
			Common_Element();
		}
		if (data == 7) {
			Print3();
		}
		if (data == 8) {
			break;
		}
	}
}