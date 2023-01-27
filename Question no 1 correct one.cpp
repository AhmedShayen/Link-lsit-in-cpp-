#include<iostream>
using namespace std;
int main() {
	int a[10];
	int data=0;
	cout << "Enter the  Data is ";
	cout << endl;
	int count = 0;
	int count1 = 0;
	for (int i = 0; i < 10; i++) {
		cin >> data;
		a[i] = data;
		if (i == 9) {
			break;
		}
		if (data % 2 == 0) 
		{
			count = count + 1;
		}
		if (data % 2 != 0)
		{
			count1 = count1 + 1;
		}
		if (count == 5) {
			cout << "All Evene Indexes are occupied";
			cout << endl;
			cout << "Enter The Odd Value";
			cout << endl;
		}else if (count1 == 5) {
			cout << "All Odd Indexes are occupied";
			cout << endl;
			cout << "Enter The Even Value";
			cout << endl;
		}
	}
	int b[10];
	for (int i = 0; i < 10; i++) {
		b[i] = 0;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (b[j] == 0) {
				if (j % 2 == 0) {
					if (a[i] % 2 == 0) {
						b[j] = a[i];
						break;
					}
				}
			}
			if (b[j] == 0) {
				if (j % 2 != 0) {
					if (a[i] % 2 != 0) {
						b[j] = a[i];
						break;
					}
				}
			}
		}
	}
	cout << "Your Data is ";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << b[i] << " ";
	}
}