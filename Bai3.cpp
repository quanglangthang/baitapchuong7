#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int arr[1000],n;
	ifstream iFile;
	iFile.open("test.txt",ios_base::in);
  	if (iFile.fail() == true) {
  		cout << "ERROR";
  		return 0;
	}
	iFile >> n;
	for (int i = 0;i<n;i++) {
		iFile >> arr[i];
	}
	for (int i = 0;i<n;i++) {
		cout << arr[i] << " ";
	}
  	iFile.close();
}
	
