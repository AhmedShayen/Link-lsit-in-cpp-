#include<iostream>
using namespace std;
int main() {
	int* a;
	cout << "Enter the Size of the Array";
	cout << endl;
	int size;
	cin >> size;
	a = new int[size];
	cout << "Enter The Data";
	cout << endl;
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
	int c = 0;
	for (int i = 1; i < 10; i++) {
		if (a[c] % i == 0) {
			cout << "Factor of ::" << a[c] << " ::" << i;
			cout << endl;
		}
		if (i == 9) {
			i = 0;
			c = c + 1;
		}
		if (c == size-1) {
			break;
		}
	}
}