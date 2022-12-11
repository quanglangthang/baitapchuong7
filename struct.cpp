#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct list {
	int MSSV;
	string TSV;
	float d1, d2, d3, bq;
};

void input(list sv[], int n) {
	for (int i = 0; i < n; i++) {
		system("cls");
		cout << "Thong tin sinh vien thu " << i+1 << endl;
		cout << "--------------------\n";
		cout << "Nhap MSSV: ";
		cin >> sv[i].MSSV;
		cout << "Nhap ten sinh vien: ";
		cin >> sv[i].TSV;
		cout << "Nhap diem mon 1,2,3: ";
		cin >> sv[i].d1 >> sv[i].d2 >> sv[i].d3;
		sv[i].bq = (sv[i].d1 * 2 + sv[i].d2 + sv[i].d3) / 4;
		system("cls");
	}
}

void output(list sv[], int n) {
	cout << setw(30) << "Danh sach sinh vien !!" << endl;
	cout << left << setw(5) << "STT"
		<< left << setw(10) << "MSSV"
		<< left << setw(20) << "Ten SV"
		<< left << setw(7) << "D1"
		<< left << setw(7) << "D2"
		<< left << setw(7) << "D3"
		<< left << setw(7) << "Diem BQ" << endl;

	for (int i = 0; i < n; i++) {
		cout << left << setw(5) << i + 1
			<< left << setw(10) << sv[i].MSSV
			<< left << setw(20) << sv[i].TSV
			<< left << setw(7) << sv[i].d1
			<< left << setw(7) << sv[i].d2
			<< left << setw(7) << sv[i].d3
			<< left << setw(7) << sv[i].bq << endl;
	}
}
void sort(list sv[], int n) {
	int local = 0;
	int max = sv[0].bq;
	for (int i = 1; i < n; i++) {
		if (max < sv[i].bq) {
			max = sv[i].bq;
			local = i;
		}
	}
	cout << "-----------------------------" << endl;
	cout << "Sinh vien co diem binh quan cao nhat !" << endl;
	cout << left << setw(5) << "STT"
		<< left << setw(10) << "MSSV"
		<< left << setw(20) << "Ten SV"
		<< left << setw(7) << "D1"
		<< left << setw(7) << "D2"
		<< left << setw(7) << "D3"
		<< left << setw(7) << "Diem BQ" << endl;

	cout << left << setw(5) << local + 1
		<< left << setw(10) << sv[local].MSSV
		<< left << setw(20) << sv[local].TSV
		<< left << setw(7) << sv[local].d1
		<< left << setw(7) << sv[local].d2
		<< left << setw(7) << sv[local].d3
		<< left << setw(7) << sv[local].bq << endl;
}

int main() {
	list sv[1000];
	int n;
	cout << "Nhap vao so luong sinh vien: ";
	cin >> n;
	input(sv, n);
	output(sv, n);
	sort(sv, n);
}
