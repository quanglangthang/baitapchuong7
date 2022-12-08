#include <iostream>
using namespace std;


int main() {
	int n, arr[1000], max = 0, min = 0;
	cout << "Nhap so phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	max = min = arr[0];
	for (int i = 1; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	for (int i = 1; i < n; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	cout << max << " " << min;
	
}
