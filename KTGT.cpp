#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

struct list {
	int mssv, tuoi;
	string tsv, gioitinh, hocluc;
	float toan, li, hoa, dtb;
};

void input(list sv[], int& n);
void output(list sv[], int n);
void add(list sv[], int &n, int &a);
void checkLocal(list sv[], int n, int &local);
void update(list sv[], int n, int local);
void xoa(list sv[], int& n, int local);
void sortName(list sv[], int n, string &name);
void tangdan(list sv[], int n);
void giamdan(list sv[], int n);
void sapxep(list sv[], int n);

int main() {
	int n, opt, local;
	char laplai;
	string name;
	bool check = true;
	list sv[1000];
	do {
		cout << "0. Thoat" << endl;
		cout << "1. Nhap danh sach sinh vien." << endl;
		cout << "2. Them sinh vien" << endl;
		cout << "3. Cap nhat sinh vien boi ID." << endl;
		cout << "4. Xoa sinh vien ID" << endl;
		cout << "5. Tim kiem sinh vien theo ten" << endl;
		cout << "6. Sap xep theo diem trung binh" << endl;
		cout << "8. Hien thi danh sach" << endl;
		cout << "Nhap lua chon: ";
		cin >> opt;
		switch (opt) {
		case 0:
			exit(0);
		case 1:
			input(sv, n);
			break;
		case 2:
			int a;
			add(sv, n, a);
			break;
		case 3:
			checkLocal(sv, n, local);
			update(sv, n, local);
			break;
		case 4:
			checkLocal(sv, n, local);
			xoa(sv, n, local);
			break;
		case 5:

			sortName(sv, n, name);
			break;
		case 6:
			sapxep(sv, n);
			break;

		case 8:
			output(sv, n);
			break;

		default:
			cout << "Sai cu phap !!" << endl;

		}
		cout << "Ban con muon su dung(Y/N): ";
		cin >> laplai;
		if ((laplai == 'Y') || (laplai == 'y')) {
			check = true;
		}
		else if ((laplai == 'N') || (laplai == 'n')) {
			check = false;
		}
		system("cls");
	} while (check);
}
	
void input(list sv[], int& n) {
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		system("cls");
		cout << "Thong tin sinh vien thu " << i + 1 << endl;
		cout << "Nhap MSSV: ";
		cin >> sv[i].mssv;
		cout << "Nhap Ten SV: ";
		cin.ignore();
		getline(cin,sv[i].tsv);
		cout << "Nhap Tuoi: ";
		cin >> sv[i].tuoi;
		cout << "Nhap gioi tinh: ";
		cin >> sv[i].gioitinh;
		cout << "Nhap diem toan, li, hoa: ";
		cin >> sv[i].toan >> sv[i].li >> sv[i].hoa;
		sv[i].dtb = (sv[i].toan + sv[i].li + sv[i].hoa) / 3;
		if (sv[i].dtb >= 8) {
			sv[i].hocluc = "Gioi";
		}
		else if ((sv[i].dtb >= 6.5) && (sv[i].dtb <8)) {
			sv[i].hocluc = "Kha";
		}
		else if ((sv[i].dtb >=5) && (sv[i].dtb) < 6.5) {
			sv[i].hocluc = "Trung binh";
		}
		else {
			sv[i].hocluc = "Yeu";
		}
	}
}

void output(list sv[], int n) {
	/*cout << setw(40) << "Danh sach sinh vien !!!" << endl;
	cout << setw(40) << "-----------------------\n";*/
	cout << "\t\tDanh sach sinh vien" << endl;
	cout << left << setw(12) << "MSSV "
		<< left << setw(15) << "Ten SV"
		<< left << setw(7) << "Tuoi"
		<< left << setw(12) << "Gioi tinh"
		<< left << setw(7) << "Toan"
		<< left << setw(7) << "Li"
		<< left << setw(7) << "Hoa"
		<< left << setw(7) << "DTB"
		<< left << setw(7) << "Hoc luc" << endl;


	for (int i = 0; i < n; i++) {
		cout << left << setw(12)  << sv[i].mssv
			<< left << setw(15)  << sv[i].tsv
			<< left << setw(7)  << sv[i].tuoi
			<< left << setw(12)  << sv[i].gioitinh
			<< left << setw(7)  << sv[i].toan
			<< left << setw(7)  << sv[i].li
			<< left << setw(7)  << sv[i].hoa
			<< left << setw(7)  << fixed << setprecision(1) << sv[i].dtb
			<< left << setw(7) << sv[i].hocluc << endl;

	}
}

void add(list sv[], int &n, int &a) {
	cout << "Nhap so sinh vien can them: ";
	cin >> a;
	for (int i = n; i < n + a; i++) {
		cout << "Nhap MSSV: ";
		cin >> sv[i].mssv;
		cout << "Nhap Ten SV: ";
		cin >> sv[i].tsv;
		cout << "Nhap Tuoi: ";
		cin >> sv[i].tuoi;
		cout << "Nhap gioi tinh: ";
		cin >> sv[i].gioitinh;
		cout << "Nhap diem toan, li, hoa: ";
		cin >> sv[i].toan >> sv[i].li >> sv[i].hoa;
		sv[i].dtb = (sv[i].toan + sv[i].li + sv[i].hoa) / 3;
		if (sv[i].dtb >= 8) {
			sv[i].hocluc = "Gioi";
		}
		else if ((sv[i].dtb >= 6.5) && (sv[i].dtb < 8)) {
			sv[i].hocluc = "Kha";
		}
		else if ((sv[i].dtb >= 5) && (sv[i].dtb) < 6.5) {
			sv[i].hocluc = "Trung binh";
		}
		else {
			sv[i].hocluc = "Yeu";
		}
	}
	n += a;
}

void  checkLocal(list sv[], int n, int &local) {
	int id;
	cout << "Nhap id can sua/xoa: ";
	cin >> id;
	for (int i = 0; i < n; i++) {
		if (sv[i].mssv == id) {
			local = i;
		}
	}
}

void update(list sv[], int n, int local) {
	
	for (int i = local; i < local + 1; i++) {
		cout << "Nhap MSSV: ";
		cin >> sv[i].mssv;
		cout << "Nhap Ten SV: ";
		cin >> sv[i].tsv;
		cout << "Nhap Tuoi: ";
		cin >> sv[i].tuoi;
		cout << "Nhap gioi tinh: ";
		cin >> sv[i].gioitinh;
		cout << "Nhap diem toan, li, hoa: ";
		cin >> sv[i].toan >> sv[i].li >> sv[i].hoa;
		sv[i].dtb = (sv[i].toan + sv[i].li + sv[i].hoa) / 3;
		if (sv[i].dtb >= 8) {
			sv[i].hocluc = "Gioi";
		}
		else if ((sv[i].dtb >= 6.5) && (sv[i].dtb < 8)) {
			sv[i].hocluc = "Kha";
		}
		else if ((sv[i].dtb >= 5) && (sv[i].dtb) < 6.5) {
			sv[i].hocluc = "Trung binh";
		}
		else {
			sv[i].hocluc = "Yeu";
		}
	}
 }

void xoa(list sv[], int &n, int local) {
	for (int i = local + 1; i < n; i++) {
		sv[i - 1].mssv = sv[i].mssv;
		sv[i - 1].tsv = sv[i].tsv;
		sv[i - 1].tuoi = sv[i].tuoi;
		sv[i - 1].gioitinh = sv[i].gioitinh;
		sv[i - 1].toan = sv[i].toan;
		sv[i - 1].li = sv[i].li;
		sv[i - 1].hoa = sv[i].hoa;
		sv[i - 1].dtb = sv[i].dtb;
		sv[i - 1].hocluc = sv[i].hocluc;
	}
	n--;
}
void sortName(list sv[], int n, string &name) {
	cout << "Nhap vao ten sinh vien can tim: ";
	cin >> name;
	for (int i = 0; i < n; i++) {
		if (name == sv[i].tsv) {
			cout << "\t\tDanh sach sinh vien da tim kiem" << endl;
			cout << left << setw(12) << "MSSV "
				<< left << setw(15) << "Ten SV"
				<< left << setw(7) << "Tuoi"
				<< left << setw(12) << "Gioi tinh"
				<< left << setw(7) << "Toan"
				<< left << setw(7) << "Li"
				<< left << setw(7) << "Hoa"
				<< left << setw(7) << "DTB"
				<< left << setw(7) << "Hoc luc" << endl;
			
			cout << left << setw(12) << sv[i].mssv
				<< left << setw(15) << sv[i].tsv
				<< left << setw(7) << sv[i].tuoi
				<< left << setw(12) << sv[i].gioitinh
				<< left << setw(7) << sv[i].toan
				<< left << setw(7) << sv[i].li
				<< left << setw(7) << sv[i].hoa
				<< left << setw(7) << fixed << setprecision(1) << sv[i].dtb
				<< left << setw(7) << sv[i].hocluc << endl;
		}
		else {
			cout << "\t\t Khong co ten sinh vien nay trong danh sach !!";
		}
	}
}

void sapxep(list sv[], int n) {
	int choice;
	cout << "1. Sap xep tang dan" << endl;
	cout << "2. Sap xep giam dan" << endl;
	cout << "Nhap lua chon: ";
	cin >> choice;
	switch (choice) {
		case 1:
			tangdan(sv, n);
			break;
		case 2:
			giamdan(sv, n);
			break;
		default:
			cout << "Sai cu phap." << endl;
			return;
	}
}

void tangdan(list sv[], int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sv[i].dtb > sv[j].dtb) {
				temp = sv[i].dtb;
				sv[i].dtb = sv[j].dtb;
				sv[j].dtb = temp;
			}
		}
	}
	cout << "\t\tDanh sach sinh vien da sap xep diem tang dan" << endl;
	cout << left << setw(12) << "MSSV "
		<< left << setw(15) << "Ten SV"
		<< left << setw(7) << "Tuoi"
		<< left << setw(12) << "Gioi tinh"
		<< left << setw(7) << "Toan"
		<< left << setw(7) << "Li"
		<< left << setw(7) << "Hoa"
		<< left << setw(7) << "DTB"
		<< left << setw(7) << "Hoc luc" << endl;
	for (int i = 0; i < n; i++) {
		cout << left << setw(12) << sv[i].mssv
			<< left << setw(15) << sv[i].tsv
			<< left << setw(7) << sv[i].tuoi
			<< left << setw(12) << sv[i].gioitinh
			<< left << setw(7) << sv[i].toan
			<< left << setw(7) << sv[i].li
			<< left << setw(7) << sv[i].hoa
			<< left << setw(7) << fixed << setprecision(1) << sv[i].dtb
			<< left << setw(7) << sv[i].hocluc << endl;
	}
}

void giamdan(list sv[], int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sv[i].dtb < sv[j].dtb) {
				temp = sv[i].dtb;
				sv[i].dtb = sv[j].dtb;
				sv[j].dtb = temp;
			}
		}
	}
	cout << "\t\tDanh sach sinh vien da sap xep diem giam dan" << endl;
	cout << left << setw(12) << "MSSV "
		<< left << setw(15) << "Ten SV"
		<< left << setw(7) << "Tuoi"
		<< left << setw(12) << "Gioi tinh"
		<< left << setw(7) << "Toan"
		<< left << setw(7) << "Li"
		<< left << setw(7) << "Hoa"
		<< left << setw(7) << "DTB"
		<< left << setw(7) << "Hoc luc" << endl;
	for (int i = 0; i < n; i++) {
		cout << left << setw(12) << sv[i].mssv
			<< left << setw(15) << sv[i].tsv
			<< left << setw(7) << sv[i].tuoi
			<< left << setw(12) << sv[i].gioitinh
			<< left << setw(7) << sv[i].toan
			<< left << setw(7) << sv[i].li
			<< left << setw(7) << sv[i].hoa
			<< left << setw(7) << fixed << setprecision(1) << sv[i].dtb
			<< left << setw(7) << sv[i].hocluc << endl;
	}
}
