#include <iostream>
using namespace std;

int main() {
	int n, arr[1000];
	cout << "Nhap so phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			cout << arr[i];
		}
	}
}
