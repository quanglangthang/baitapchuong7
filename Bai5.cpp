#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, arr[100], chan = 0,le = 0;
	cin >> n;
	for (int i=0;i<n;i++) {
		cin >> arr[i];
	}
	for (int i=0;i<n;i++) {
		if (arr[i] % 2 == 0) {
			chan++;
		}
		else {
			le++;
		}
	}
	cout << chan << " " << le;
}
	
