#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, arr[100],count = 0, n1;
	cin >> n;
	
	for (int i=0;i<n;i++) {
		cin >> arr[i];
	}
	cout << "So can kiem tra so lan lap: ";
	cin >> n1;
	for (int i=0;i<n;i++) {
		if (arr[i] == n1) {
			count++;
		}
	}
	cout << count;
}
	
