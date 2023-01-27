#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
node* head = NULL;
node* head1 = NULL;
node* curr1=NULL;
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
		curr1 = NODE->next;
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
node* merge_lists(node* NODE1) {

	if (NODE1->next== NULL) {
		NODE1->next = head1;
	}
	curr1 = NODE1->next;
	return head;
}
void Sort() {
	node* temp = head;
	node* temp2 = head;
	temp2 = temp2->next;
	node* Swap = NULL;
	node* check;
	while (temp != NULL) {
		while (temp2 != NULL) {
			if (temp->data < temp2->data) {
				swap(temp->data, temp2->data);
			}
			else {
				temp2 = temp2->next;
			}
		}
		temp = temp->next;
		temp2 = temp;
		if (temp2 == NULL) {
			break;
		}
		temp2 = temp2->next;
	}
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
void Print1() {
	node* NODE = head;
	cout << endl;
	while (NODE != curr1) {
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
		cout << "Enter 3 to Merg and sort";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 4 to Print The Merig Link List I.E merg should be done";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 5 to Print The First Link List";
		cout << endl;
		cout << "--------------------------------------------";
		cout << endl;
		cout << "Enter 6 to Print The Second Link List";
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
			int data=0;
			cin >> data;
			Node = Insert(Node, data);
		}
		if (data == 2) {
			cout << "Enter The Data You Want to Insert";
			cout << endl;
			cout << "--------------------------------------------";
			cout << endl;
			int data1=0;
			cin >> data1;
			Node1 = Insert1(Node1, data1);
		}
		if (data == 3) {
			merge_lists(Node);
			Sort();
		}
		if (data == 4) {
			Print();
		}
		if (data == 5) {
			Print1();
		}
		if (data == 6) {
			Print3();
		}
	}
}