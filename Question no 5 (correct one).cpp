#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}
*start;
class double_llist
{
private:
	node* head = NULL;
	node* current_ptr = NULL;
	int count;
public:
	node* insert_at_begin(int value, node* temp) {
		if (head == NULL) {
			temp = new node;
			temp->data = value;
			head = temp;
			current_ptr = temp;
			temp->next = NULL;
			temp->prev = NULL;
		}
		else {
			current_ptr = temp;
			temp = new node;
			temp->data = value;
			current_ptr->next = temp;
			temp->prev = current_ptr;
			temp->next = NULL;
		}
		return temp;
	}
	void insert_after(int value, int position) {
		node* Temp = head;
		int counter = 0;
		node* temp2 = NULL;
		node* temp1 = new node;
		while (Temp != NULL) {
			if (position == 0) {
				temp1->data = value;
				temp1->prev = Temp;
				temp2 = Temp;
				temp2 = temp2->next;
				temp1->next = temp2;
				Temp->next = temp1;
				break;
			}
			if (counter == position) {
				temp1->prev = Temp;
				temp2 = Temp;
				temp2 = temp2->next;
				temp1->data = value;
				temp1->next = temp2;
				Temp->next = temp1;
				break;
			}
			Temp = Temp->next;
			counter = counter + 1;
		}
	}
	node* insert_at_end(int value, node* NODE) {
		node* temp = new node;
		temp->data = value;
		NODE->next = temp;
		temp->prev = NODE;
		temp->next = NULL;
		return temp;
	};
	void delete_at_begin() {
		node* temp = head;
		if (temp == NULL) {
			delete temp;
			return;
		}
		temp = temp->next;
		delete head;
		if (temp == NULL) {
			head = NULL;
			return;
		}
		head = temp;
		temp->prev = NULL;
	};
	void delete_before(int value) {
		node* Temp = head;
		node* temp2 = NULL;
		node* temp3 = NULL;
		while (Temp != NULL) {
			if (Temp->data == value) {
				temp3 = Temp;
				temp2 = Temp;
				temp2 = Temp->prev;
				temp3 = Temp->next;
				if (temp3 == NULL) {
					break;
				}
				delete Temp;
				temp3->prev = temp2;
				temp2->next = temp3;
				Temp = temp3;
				break;
			}
			Temp = Temp->next;
		}
	};
	int Search(int data) {
		node* Temp = head;
		int count = 0;
		while (Temp != NULL) {
			if (data == Temp->data) {
				return count;
			}
			else {
				Temp = Temp->next;
				count = count + 1;
			}
		}
	}
	node* delete_at_end(node* NODE) {
		node* temp = NODE;
		if (temp == NULL) {
			head = NULL;
			return head;
		}
		temp = temp->prev;
		delete NODE;
		if (temp == NULL) {
			head = NULL;
			return head;
		}
		temp->next = NULL;
		return temp;
	};
	void display_dlist() {
		node* Temp = head;
		cout << "Your Data is ";
		cout << endl;
		cout << "-------------------";
		cout << endl;
		while (Temp != NULL) {
			cout << Temp->data << " ";
			Temp = Temp->next;
		}
		cout << endl;
	}
	bool is_empty();
	double_llist()
	{
		head = NULL;
		current_ptr = NULL; //constructor for my class
		count = 0;
	}
	~double_llist() {
		current_ptr = head;
		while (current_ptr != NULL)
		{
			node* next = current_ptr->next;
			delete current_ptr;
			current_ptr = next;
		}
	}
};
int main() {
	node* NODE = NULL;
	double_llist a;
	while (true) {
		cout << "Enter the 1 To insert The Data\n";
		cout << "-------------------------------\n";
		cout << "Enter the 2 To insert The Data at position \n";
		cout << "-------------------------------------------\n";
		cout << "Enter the 3 To insert The Data at last position \n";
		cout << "-----------------------------------------------\n";
		cout << "Enter the 4 To Delete At the First  Position \n";
		cout << "-----------------------------------------------\n";
		cout << "Enter 5 to Delete At the Last Position \n";
		cout << "-----------------------------------------------\n";
		cout << "Enter 6  Delete At Value Except Last\n";
		cout << "-----------------------------------------------\n";
		cout << "Enter 7 to Display At the The List\n";
		cout << "-----------------------------------------------\n";
		cout << "Enter 8 to Search\n";
		cout << "-----------------------------------------------\n";
		cout << "Enter 9 to Break\n";
		cout << "-----------------------------------------------\n";
		int in;
		cin >> in;
		if (in == 1) {
			cout << "Enter the Data you want to Insert\n";
			cout << "-----------------------------------------------\n";
			int data1;
			cin >> data1;
			NODE = a.insert_at_begin(data1, NODE);
		}
		if (in == 2) {
			cout << "Enter the Data At the n Position\n";
			cout << "-----------------------------------------------\n";
			cout << "Enter the Position\n";
			cout << "-------------------------------------------------\n";
			int pos;
			cin >> pos;
			cout << "Enter The Data To Insert At the Last position\n";
			cout << "-------------------------------------------------\n";
			int data;
			cin >> data;
			a.insert_after(data, pos);
		}
		if (in == 3) {
			cout << "Enter the Data you want to Insert at the Last positon\n";
			cout << "-----------------------------------------------\n";
			int data;
			cin >> data;
			NODE = a.insert_at_end(data, NODE);
		}
		if (in == 4) {
			a.delete_at_begin();
		}
		if (in == 5) {
			NODE = a.delete_at_end(NODE);
		}
		if (in == 6) {
			cout << "Enter value You Want to Delete\n";
			cout << "-----------------------------------------------\n";
			int pos;
			cin >> pos;
			a.delete_before(pos);
		}
		if (in == 7) {
			a.display_dlist();
		}
		if (in == 8) {
			cout << "Enter value You Want to Search\n";
			cout << "-----------------------------------------------\n";
			int data;
			cin >> data;
			cout << "Your Data is at position \n";
			cout << "-----------------------------------------------\n";
			cout << a.Search(data);
			cout << endl;
		}
		if (in == 9) {
			break;
		}
	}
	system("pause");
	return 0;
}
