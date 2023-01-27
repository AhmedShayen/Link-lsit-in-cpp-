#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct node
{
	char data;
	struct node* next;
	struct node* prev;
}
*start;
class double_llist
{
private:
	node* head = NULL;
	node* current_ptr = NULL;
	node* head1 = NULL;
	node* current_ptr1 = NULL;
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
			temp->next = head;
			current_ptr1 = temp;
		}
		return temp;
	}
	node* delete_at_begin() {
		node* temp = head;
		temp = temp->next;
		delete head;
		head = temp;
		current_ptr1->next = head;
		return temp;
	};
	void Vowel_Sorting() {

		string oval = {};
		node* Temp = head;
		char data = Temp->data;
		int i = 0;
		while (data != 'A' && data != 'a' && data != 'E' && data != 'e' && data != 'I' && data != 'i' && data != 'O' && data != 'o' && data != 'U' && data && 'u') {
			oval = oval + data;
			Temp = delete_at_begin();
			data = Temp->data;
			if (Temp == current_ptr1) {
				break;
			}
		}
		 if ((data != 'A' && data != 'a' && data != 'E' && data != 'e' && data != 'I' && data != 'i' && data != 'O' && data != 'o' && data != 'U' && data && 'u')||oval == "\0") {
			cout << oval;
			display_dlist();
			cout << "-";
			cout << "way";
		 }
		 else if (oval != "\0") {
			 display_dlist();
			 cout << "-";
			 oval = oval + "ay";
			 cout << oval;
		 }
		cout << endl;
	}
	void display_dlist() {
		node* Temp = head;
		cout << Temp->data << " ";
		Temp = Temp->next;
		while (Temp != head) {
			cout << Temp->data << " ";
			Temp = Temp->next;
		}
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
		while (current_ptr != current_ptr1)
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
	string input;
	cout << "Input the String ";
	cout << endl;
	cout << "------------------";
	cout << endl;
	cin >> input;
	for (int i = 0; input[i] != '\0'; i++) {
		NODE = a.insert_at_begin(input[i], NODE);
	}
	a.display_dlist();
	cout << endl;
	a.Vowel_Sorting();
	system("pause");
	return 0;
}
